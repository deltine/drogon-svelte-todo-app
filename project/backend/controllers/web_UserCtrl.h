#pragma once
#include <drogon/HttpController.h>
#include "dto/User.h"
#include "filters/TestFilter.h"

using namespace drogon;
namespace web
{
    class UserCtrl : public drogon::HttpController<UserCtrl>
    {
    public:
        METHOD_LIST_BEGIN
        // METHOD_ADD(UserCtrl::index, "/", Get);
        METHOD_ADD(UserCtrl::index, "/index", Get, "TestFilter");
        METHOD_ADD(UserCtrl::view, "/view", Get);
        METHOD_ADD(UserCtrl::login, "/token?userId={1}&passwd={2}", Post);
        METHOD_ADD(UserCtrl::getInfo, "/{1}/info?token={2}", Get);
        METHOD_ADD(UserCtrl::newUser, "/users", Post);
        METHOD_LIST_END

        void index(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback);
        void view(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback);
        void login(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   std::string &&userId,
                   const std::string &password);
        void getInfo(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     std::string userId,
                     const std::string &token) const;
        void newUser(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback,
                     dto::User &&pNewUser) const;
    };
}
