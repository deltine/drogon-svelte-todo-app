// #include <drogon/orm/Mapper.h>

#include <coroutine>
#include <time.h>
#include <drogon/utils/coroutine.h>
#include <iostream>
#include "api_Account.h"
#include "models/Account.h"
#include "common/HttpReqestMgr.h"
#include "common/util.h"
#include "common/hash/sha256.h"
#include "logic/web_Account/signup.h"

using namespace std;
using namespace drogon;
using namespace drogon::orm;
using namespace api;
using namespace drogon_model;

void api::Account::signup(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string processId = Process::getId();
    try
    {
        LOG_INFO << processId << "call";

        // 1. 登録しようとしているIDを確認あればNG

        auto db = app().getFastDbClient("fast");
        auto params = HttpReqestMgr::getParams(req);
        LOG_DEBUG << processId << "params: " << (*params).toStyledString();

        if (!params || !*params)
        {
            LOG_ERROR << processId << "JsonObject failed";
            LOG_ERROR << req->getJsonError();
            callback(MakeResponse::faild(HttpStatusCode::k409Conflict));
            return;
        }

        auto callbackPtr =
            std::make_shared<std::function<void(const HttpResponsePtr &)>>(
                std::move(callback));

        *db << R"(select * from account where mail_address = ?)"
            << params->get("mailAddress", "default").asString() >>
            [=, this](const Result &r) mutable
        {
            if (r.size() == 0)
            {
                LOG_DEBUG << processId << "account not found.";

                auto account = mydb::Account();
                account.setMailAddress(params->get("mailAddress", "default").asString());
                SHA256 sha256;
                account.setPassword(sha256(params->get("password", "default").asString()));
                account.setCreatedAt(trantor::Date::now());

                Mapper<mydb::Account> mapper(db);
                mapper.insert(
                    account,
                    [=, this](mydb::Account account)
                    {
                        LOG_DEBUG << processId << "Account insert success.";

                        // キーの払い出し
                        auto authKey = drogon::utils::getUuid();
                        auto authToken = drogon::utils::getUuid();

                        // セッション作成
                        req->session()->insert("authKey", authKey);
                        req->session()->insert("authToken", authToken);

                        // ボディ作成
                        Json::Value body;
                        body["authKey"] = authKey;
                        body["authToken"] = authToken;

                        // ヘッダー作成
                        auto response = MakeResponse::success(body);
                        response->addCookie(Cookie("authKey", authKey));
                        response->addCookie(Cookie("authToken", authToken));

                        (*callbackPtr)(response);
                    },
                    CallBackDBAccessFailed{callbackPtr});
            }
            else
            {
                LOG_DEBUG << processId << "account found";
                (*callbackPtr)(MakeResponse::faild(HttpStatusCode::k200OK));
            }
        } >>
            CallBackDBAccessFailed{callbackPtr};
    }
    catch (exception &e)
    {
        LOG_ERROR << processId << "failed: " << e.what();
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
    catch (...)
    {
        LOG_ERROR << processId << "failed";
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
}

void api::Account::checkLogin(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string processId = Process::getId();
    try
    {
        LOG_INFO << processId << "call";

        if (req->session()->find("authToken"))
        {
            auto authToken = req->session()->get<string>("authToken");
            auto params = HttpReqestMgr::getParams(req);

            LOG_DEBUG << processId << "params: " << (*params).toStyledString();

            if (!params)
            {
                LOG_ERROR << processId << "JsonObject failed";
                LOG_ERROR << req->getJsonError();
                callback(MakeResponse::faild(HttpStatusCode::k409Conflict));
                return;
            }

            if (authToken.compare(params->get("authToken", "default").asString()))
            {
                auto response = MakeResponse::success();
                callback(response);
            }

            LOG_ERROR << processId << "failed";
            callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
        }
        callback(MakeResponse::faild(HttpStatusCode::k200OK));
    }
    catch (exception &e)
    {
        LOG_ERROR << processId << "failed: " << e.what();
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
    catch (...)
    {
        LOG_ERROR << processId << "failed";
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
}

void api::Account::signin(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback)
{
    std::string processId = Process::getId();

    try
    {
        LOG_DEBUG << processId << "signin call";

        auto db = app().getFastDbClient("fast");
        auto params = HttpReqestMgr::getParams(req);
        LOG_DEBUG << processId << "params: " << (*params).toStyledString();

        if (!params || !*params)
        {
            LOG_ERROR << processId << "JsonObject failed";
            LOG_ERROR << processId << req->getJsonError();
            Json::Value json;
            json["res"] = 0;
            auto response = HttpResponse::newHttpJsonResponse(std::move(json));
            response->addHeader("Access-Control-Allow-Origin", "*");
            callback(response);
            return;
        }

        auto callbackPtr =
            std::make_shared<std::function<void(const HttpResponsePtr &)>>(
                std::move(callback));
        SHA256 sha256;

        *db << R"(select * from account where mail_address = ? and password = ?)"
            << params->get("mailAddress", "default").asString()
            << sha256(params->get("password", "default").asString()) >>
            [=, this](const Result &r) mutable
        {
            if (r.size() > 0)
            {
                LOG_DEBUG << processId << "signin success";

                // キーの払い出し
                auto authKey = drogon::utils::getUuid();
                auto authToken = drogon::utils::getUuid();

                // セッション作成
                req->session()->insert("authKey", authKey);
                req->session()->insert("authToken", authToken);

                // ボディ作成
                Json::Value body;
                body["authKey"] = authKey;
                body["authToken"] = authToken;
                auto response = MakeResponse::success(body);

                (*callbackPtr)(response);
            }
            else
            {
                LOG_WARN << processId << "signin failed";
                (*callbackPtr)(MakeResponse::faild(HttpStatusCode::k200OK));
            }
        } >> CallBackDBAccessFailed{callbackPtr};
    }
    catch (exception &e)
    {
        LOG_ERROR << processId << "failed: " << e.what();
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
    catch (...)
    {
        LOG_ERROR << processId << "failed";
        callback(MakeResponse::faild(HttpStatusCode::k500InternalServerError));
    }
}

void Account::test(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "call";

    auto params = HttpReqestMgr::getParams(req);
    LOG_DEBUG << "params: " << (*params).toStyledString();

    // セッション作成
    req->session()->insert("authKey", "ngAuthKey");
    req->session()->insert("authToken", "ngAuthToken");

    // ボディ作成
    Json::Value body;
    body["authKey"] = "bAuthKey";
    body["authToken"] = "bAuthToken";

    auto response = MakeResponse::success(body);
    auto a = Cookie("authKey", "ngAuthKey");
    // a.setSecure(true);
    a.setSameSite(Cookie::SameSite::kNone);
    response->addCookie(a);
    response->addCookie(Cookie("authToken", "ngAuthToken"));

    callback(response);
}