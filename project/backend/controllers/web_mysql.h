#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace web
{
    class Mysql : public drogon::HttpController<Mysql>
    {
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(Mysql::select, "/select", Get);
        METHOD_ADD(Mysql::select2, "/select2", Get);
        METHOD_ADD(Mysql::select3, "/select3", Get);
        METHOD_ADD(Mysql::insert, "/insert", Get);
        METHOD_ADD(Mysql::insert2, "/insert2", Get);
        METHOD_ADD(Mysql::update, "/update", Get);
        METHOD_ADD(Mysql::update2, "/update2", Get);
        METHOD_ADD(Mysql::del, "/del", Get);
        METHOD_ADD(Mysql::del2, "/del2", Get);
        METHOD_LIST_END

        void select(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
        void select2(const HttpRequestPtr &req,
                     std::function<void(const HttpResponsePtr &)> &&callback);
        void select3(const HttpRequestPtr &req,
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
    };
}
