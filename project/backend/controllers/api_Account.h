#pragma once
#include <drogon/HttpController.h>
#include <drogon/IOThreadStorage.h>

using namespace drogon;
using namespace drogon::orm;
namespace api
{
    class Account : public drogon::HttpController<Account>
    {
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(Account::signup, "/signup", Post, Options);
        // METHOD_ADD(Account::signup, "/signup", Post, Options, "CorsFilter");
        METHOD_ADD(Account::checkLogin, "/checkLogin", Post, Options);
        METHOD_ADD(Account::signin, "/signin", Post, Options);
        METHOD_ADD(Account::test, "/test", Post, Options);
        METHOD_LIST_END

        /**
         * @brief サインアップ機能
         * 1. 登録しようとしているIDを確認あればNG
         * 2. 無ければ登録
         * 3. セッション情報を更新
         * 4. Cookieにログイントークンを生成
         *
         * @param req
         * @param callback
         */
        void signup(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
        void checkLogin(const HttpRequestPtr &req,
                        std::function<void(const HttpResponsePtr &)> &&callback);
        void signin(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);

        void test(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback);
    };
}
