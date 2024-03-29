#pragma once
#include <drogon/HttpController.h>
#include <drogon/IOThreadStorage.h>

using namespace drogon;
using namespace drogon::orm;
namespace web
{
    class Mysql : public drogon::HttpController<Mysql>
    {
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(Mysql::selectA, "/selectA", Get);
        METHOD_ADD(Mysql::selectCoro, "/selectCoro", Get);
        METHOD_ADD(Mysql::selectFast, "/selectFast", Get);
        METHOD_ADD(Mysql::selectMapper, "/selectMapper", Get);
        METHOD_ADD(Mysql::selectCallBack, "/selectCallBack", Get);
        METHOD_ADD(Mysql::insert, "/insert", Get);
        METHOD_ADD(Mysql::insert2, "/insert2", Get);
        METHOD_ADD(Mysql::update, "/update", Get);
        METHOD_ADD(Mysql::update2, "/update2", Get);
        METHOD_ADD(Mysql::del, "/del", Get);
        METHOD_ADD(Mysql::del2, "/del2", Get);
        METHOD_ADD(Mysql::tran, "/tran", Get);
        METHOD_LIST_END

        void selectA(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback);
        void selectCoro(const HttpRequestPtr &req,
                        std::function<void(const HttpResponsePtr &)> &&callback);
        void selectFast(const HttpRequestPtr &req,
                        std::function<void(const HttpResponsePtr &)> &&callback);
        void selectMapper(const HttpRequestPtr &req,
                          std::function<void(const HttpResponsePtr &)> &&callback);
        void selectCallBack(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback);
        void insert(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
        void insert2(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback);
        void update(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
        void update2(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback);
        void del(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback);
        void del2(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback);
        void tran(const HttpRequestPtr &req,
                  std::function<void(const HttpResponsePtr &)> &&callback);

    private:
        IOThreadStorage<orm::DbClientPtr> _dbClient;
        std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
    };
}
