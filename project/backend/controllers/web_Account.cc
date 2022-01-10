// #include <drogon/orm/Mapper.h>

#include <coroutine>
#include <time.h>
#include <drogon/utils/coroutine.h>
#include "web_Account.h"
#include "models/Account.h"
#include "common/HttpReqestMgr.h"
#include "logic/common/CallBack.h"

using namespace std;
using namespace drogon;
using namespace drogon::orm;
using namespace web;
using namespace drogon_model::mydb;

void web::Account::signin(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        LOG_DEBUG << "signin call";

        auto db = app().getFastDbClient();
        auto params = HttpReqestMgr::getParams(req);

        if (!params)
        {
            LOG_DEBUG << "JsonObject failed";
            LOG_DEBUG << req->getJsonError();
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

        *db << R"(select * from account where mail_address = ? and password = ?)"
            << params->get("mailAddress", "default").asString()
            << params->get("password", "default").asString() >>
            [callbackPtr](const Result &r) mutable
        {
            if (r.size() > 0)
            {
                LOG_DEBUG << "signin success";
                Json::Value json{};
                json["res"] = 1;
                auto response = HttpResponse::newHttpJsonResponse(std::move(json));
                response->addHeader("Access-Control-Allow-Origin", "*");
                (*callbackPtr)(response);
            }
            else
            {
                LOG_DEBUG << "signin failed";
                Json::Value json{};
                json["res"] = 0;
                auto response = HttpResponse::newHttpJsonResponse(std::move(json));
                response->addHeader("Access-Control-Allow-Origin", "*");
                response->addHeader("Access-Control-Allow-Credentials", "true");
                (*callbackPtr)(response);
            }
        } >> CallBackDBAccessFailed{callbackPtr};
    }
    catch (...)
    {
        LOG_DEBUG << "signin failed";
        Json::Value json{};
        json["res"] = 0;
        auto response = HttpResponse::newHttpJsonResponse(std::move(json));
        response->addHeader("Access-Control-Allow-Origin", "*");
        response->addHeader("Access-Control-Allow-Credentials", "true");
        callback(response);
    }
}