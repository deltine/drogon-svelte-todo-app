// #include <drogon/orm/Mapper.h>

#include <coroutine>
#include <drogon/utils/coroutine.h>
#include "web_mysql.h"
#include "models/Account.h"
#include "models/TodoTask.h"

using namespace drogon;
using namespace drogon::orm;
using namespace web;
using namespace drogon_model::mydb;

void Mysql::select(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "select call";
    auto clientPtr = app().getFastDbClient();

    clientPtr->execSqlAsync(
        "select * from account",
        [](const Result &r)
        {
            LOG_DEBUG << r.size() << " rows selected!";
            int i = 0;
            for (auto row : r)
            {
                auto a = Account(row);
                LOG_DEBUG << i++ << ": user name is "
                          << "accountid: " << *a.getAccountId()
                          << " account_name: " << *a.getAccountName();
            }
            return 1;
        },
        [](const DrogonDbException &e)
        {
            LOG_ERROR << "error:" << e.base().what();
        },
        "default");

    Json::Value ret;
    ret["result"] = "select ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

// // コルーチンiotaを定義
// generator iota(int end)
// {
//     for (int n = 0; n < end; ++n)
//     {
//         co_yield n;
//     }
// }

// ->Task<>
void Mysql::select2(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "select2 call";

    // // コルーチンの呼び出し
    // auto g = iota(10);
    // for (int v : g)
    // {
    //     std::cout << v;
    // }
    // auto clientPtr = app().getFastDbClient();
    // try
    // {
    //     auto result = co_await clientPtr->execSqlCoro(Account::sqlForFindingByPrimaryKey());
    //     result.await_resume();
    //     size_t num_users = result[0][0].as<size_t>();
    //     auto resp = HttpResponse::newHttpResponse();
    //     resp->setBody(std::to_string(num_users));
    //     callback(resp);
    // }
    // catch (const DrogonDbException &err)
    // {
    //     // Exception works as sync interfaces.
    //     auto resp = HttpResponse::newHttpResponse();
    //     resp->setBody(err.base().what());
    //     callback(resp);
    // }

    // co_return;

    // Mapper<Account> mp(clientPtr);
    // mp.findByPrimaryKey(
    //     6,
    //     [](Account a)
    //     {
    //         LOG_DEBUG << "accountid: " << *a.getAccountId()
    //                   << " account_name: " << *a.getAccountName();
    //     },
    //     [](const DrogonDbException &e)
    //     {
    //         LOG_ERROR << "error:" << e.base().what();
    //     });

    // auto a = mp.findByPrimaryKey(6);
    // LOG_DEBUG << "accountid: " << *a.getAccountId()
    //           << " account_name: " << *a.getAccountName();

    // auto clientPtr = app().getFastDbClient();
    // try
    // {
    //     auto res = clientPtr->execSqlAsync(Account::sqlForFindingByPrimaryKey(), 6);

    //     for (auto len : res.get())
    //     {
    //         auto a = Account(len);
    //         LOG_DEBUG << "accountid: " << *a.getAccountId()
    //                   << " account_name: " << *a.getAccountName();
    //     }
    // }
    // catch (const DrogonDbException &e)
    // {
    //     std::cerr << "error:" << e.base().what() << std::endl;
    // }

    // auto clientPtr = app().getFastDbClient();
    // Mapper<Account> mp(clientPtr);
    // // LOG_DEBUG << "count: " << mp.count();
    // // auto f = clientPtr->execSqlAsync(R"(select * from account)");
    // // LOG_DEBUG << "count: " << mp.countFuture();
    // Account::sqlForFindingByPrimaryKey();
    // auto ac = new Account();
    // ac->sqlForFindingByPrimaryKey(clientPtr);
    // ac->getTask(
    //     clientPtr,
    //     [](const std::vector<Task> &r)
    //     {
    //         int i = 0;
    //         for (auto row : r)
    //         {
    //             LOG_DEBUG << "accountid: " << *row.getTaskId()
    //                       << " account_name: " << *row.getTitle();
    //         }
    //     },
    //     [](const drogon::orm::ExceptionCallback &ecb)
    //     {
    //         // LOG_ERROR << "error:" << ecb.target();
    //     });
    // try
    // {
    //     // auto res = mp.findFutureAll();

    //     for (auto row : f.get())
    //     {
    //         auto a = Account(row);
    //         LOG_DEBUG << "accountid: " << *a.getAccountId()
    //                   << " account_name: " << *a.getAccountName();
    //     }
    // }
    // catch (const DrogonDbException &e)
    // {
    //     std::cerr << "error:" << e.base().what() << std::endl;
    // }

    Json::Value ret;
    ret["result"] = "select2 ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::select3(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "select3 call";

    // auto clientPtr = app().getFastDbClient();
    // auto res = clientPtr->execSqlSync(R"(select * from account)");
    // try
    // {
    //     for (auto len : res)
    //     {
    //         auto a = Account(len);
    //         LOG_DEBUG << "accountid: " << *a.getAccountId()
    //                   << " account_name: " << *a.getAccountName();
    //     }
    // }
    // catch (const DrogonDbException &e)
    // {
    //     std::cerr << "error:" << e.base().what() << std::endl;
    // }

    Json::Value ret;
    ret["result"] = "select3 ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::insert(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "insert call";

    auto clientPtr = app().getFastDbClient();
    auto f = clientPtr->execSqlAsyncFuture(R"(insert into account (account_name) values ("tarou"))");

    Json::Value ret;
    ret["result"] = "insert ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::insert2(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "insert2 call";

    auto clientPtr = app().getFastDbClient();
    Mapper<Account> mp(clientPtr);
    auto a = new Account();
    a->setAccountName("insert2");
    mp.insertFuture(*a);

    Json::Value ret;
    ret["result"] = "insert2 ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::update(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "update call";

    auto clientPtr = app().getFastDbClient();
    auto f = clientPtr->execSqlAsyncFuture(R"(update account set account_name = "jirou" where account_id = 1)");

    Json::Value ret;
    ret["result"] = "update ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::update2(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "update2 call";

    auto clientPtr = app().getFastDbClient();
    Mapper<Account> mp(clientPtr);
    auto a = new Account();
    a->setAccountId(4);
    a->setAccountName("update2");
    mp.updateFuture(*a);

    Json::Value ret;
    ret["result"] = "update2 ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::del(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "del call";

    auto clientPtr = app().getFastDbClient();
    auto f = clientPtr->execSqlAsyncFuture(R"(delete from account)");

    Json::Value ret;
    ret["result"] = "del ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Mysql::del2(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "del2 call";

    auto clientPtr = app().getFastDbClient();
    Mapper<Account> mp(clientPtr);
    mp.deleteFutureBy(Criteria("account_id", CompareOperator::EQ, 1));
    // mp.deleteByPrimaryKey(1);

    Json::Value ret;
    ret["result"] = "del2 ok";
    ret["token"] = drogon::utils::getUuid();
    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}