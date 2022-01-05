#include "web_UserCtrl.h"
using namespace web;

void UserCtrl::index(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "index call";
    Json::Value ret;
    ret["result"] = "ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void UserCtrl::view(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    // Viewに渡すデータを格納する
    HttpViewData data;
    data.insert("title", "list parameters");
    data.insert("parameters",
                req->getParameters() // Getパラメータはこのように取得
    );

    // ListParaView.cspというビューにデータを渡す (詳細は後述)
    auto res = drogon::HttpResponse::newHttpViewResponse("test.csp", data);
    callback(res);
}
void UserCtrl::login(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string &&userId,
                     const std::string &password)
{
    LOG_DEBUG << "User " << userId << " login";
    // Authentication algorithm, read database, verify identity, etc...
    //...
    Json::Value ret;
    ret["result"] = "ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void UserCtrl::getInfo(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback,
                       std::string userId,
                       const std::string &token) const
{
    LOG_DEBUG << "User " << userId << " get his information";

    // Verify the validity of the token, etc.
    // Read the database or cache to get user information
    Json::Value ret;
    ret["result"] = "ok";
    ret["user_name"] = "Jack";
    ret["user_id"] = userId;
    ret["gender"] = 1;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}
void UserCtrl::newUser(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback,
                       dto::User &&pNewUser) const
{
    LOG_DEBUG << "pNewUser.userName2: " << pNewUser.userName;

    // Verify the validity of the token, etc.
    // Read the database or cache to get user information
    Json::Value ret;
    ret["result"] = "ok";
    ret["user_name"] = pNewUser.userName;
    ret["user_address"] = pNewUser.address;
    ret["user_email"] = pNewUser.email;
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}