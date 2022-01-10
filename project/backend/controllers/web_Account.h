#pragma once
#include <drogon/HttpController.h>
#include <drogon/IOThreadStorage.h>

using namespace drogon;
using namespace drogon::orm;
namespace web
{
    class Account : public drogon::HttpController<Account>
    {
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(Account::signin, "/signin", Post);
        METHOD_LIST_END

        void signin(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
    };
}
