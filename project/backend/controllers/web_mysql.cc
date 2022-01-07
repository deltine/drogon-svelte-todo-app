// #include <drogon/orm/Mapper.h>

#include <coroutine>
#include <time.h>
#include <drogon/utils/coroutine.h>
#include "web_mysql.h"
#include "models/Account.h"
#include "models/TodoTask.h"

using namespace drogon;
using namespace drogon::orm;
using namespace web;
using namespace drogon_model::mydb;

/**
 * @brief shared_ptrの仕様確認
 * shared_ptrは各スレッドで独立している。85ms
 *
 * @param req
 * @param callback
 */
void Mysql::selectA(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "selectA call";

    static std::once_flag once;
    std::call_once(once, []()
                   { srand(time(NULL)); });
    int queries = 5;
    auto &parameter = req->getParameter("queries");
    if (!parameter.empty())
    {
        queries = atoi(parameter.c_str());
        if (queries > 500)
            queries = 500;
        else if (queries < 1)
            queries = 1;
    }
    auto json = std::make_shared<Json::Value>();
    json->resize(0);
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));

    auto counterMax = std::make_shared<int>(queries);
    auto counter = std::make_shared<int>(queries);
    auto a = counter.get();

    int testCount = 0;
    auto sTestCount = std::make_shared<int>(testCount);

    if (!*_dbClient)
    {
        *_dbClient = drogon::app().getFastDbClient();
    }
    drogon::orm::Mapper<Account> mapper(*_dbClient);

    auto db = drogon::app().getFastDbClient();

    for (int i = 0; i < queries; i++)
    {
        int id = rand() % 3 + 1;
        *db << R"(select * from account where account_id=?)" << id >>
            [callbackPtr, counter, counterMax, json](const Result &r) mutable
        {
            // std::this_thread::sleep_for(std::chrono::seconds(1));

            if (*counter <= 0)
                return;
            if (r.size() > 0)
            {
                // LOG_DEBUG << "selectA max: " << *counterMax << " counter: " << *counter;
                auto w = Account(r[0]);
                json->append(w.toJson());
                (*counter)--;
                if ((*counter) == 0)
                {
                    (*callbackPtr)(HttpResponse::newHttpJsonResponse(
                        std::move(*json)));
                }
            }
            else
            {
                *counter = -1;
                Json::Value json{};
                json["code"] = 0;
                json["message"] = "Internal error";
                (*callbackPtr)(
                    HttpResponse::newHttpJsonResponse(std::move(json)));
            }
        } >> [callbackPtr, counter](const DrogonDbException &e)
        {
            if (*counter <= 0)
                return;
            *counter = -1;
            Json::Value json{};
            json["code"] = 1;
            json["message"] = e.base().what();
            auto resp = HttpResponse::newHttpJsonResponse(std::move(json));
            (*callbackPtr)(resp);
        };
    }
}

/**
 * @brief コルーチン 142ms
 *
 * @param req
 * @param callback
 */
void Mysql::selectCoro(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto coro_test = [callback]() -> Task<>
    {
        auto clientPtr = app().getDbClient();
        try
        {
            auto json = Json::Value();

            for (int i = 0; i < 500; i++)
            {
                int id = rand() % 3 + 1;
                auto result = co_await clientPtr->execSqlCoro(Account::sqlForFindingByPrimaryKey(), id);
                auto a = Account(result[0]);
                json.append(a.toJson());
            }

            auto resp = HttpResponse::newHttpJsonResponse(std::move(json));
            callback(resp);
        }
        catch (const DrogonDbException &e)
        {
            // FAULT("postgresql - DbClient coroutine interface(0) what():" +
            //       std::string(e.base().what()));
        }
        co_return;
    };
    drogon::sync_wait(coro_test());
}

/**
 * @brief execSqlAsync 82ms
 *
 * @param req
 * @param callback
 */
void Mysql::selectFast(const HttpRequestPtr &req,
                       std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "selectFast call";

    static std::once_flag once;
    std::call_once(once, []()
                   { srand(time(NULL)); });
    int queries = 5;
    auto &parameter = req->getParameter("queries");
    if (!parameter.empty())
    {
        queries = atoi(parameter.c_str());
        if (queries > 500)
            queries = 500;
        else if (queries < 1)
            queries = 1;
    }
    auto json = std::make_shared<Json::Value>();
    json->resize(0);
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    auto counter = std::make_shared<int>(queries);
    auto a = counter.get();

    int testCount = 0;
    auto sTestCount = std::make_shared<int>(testCount);

    if (!*_dbClient)
    {
        *_dbClient = drogon::app().getFastDbClient();
    }
    drogon::orm::Mapper<Account> mapper(*_dbClient);

    auto db = drogon::app().getFastDbClient();

    for (int i = 0; i < queries; i++)
    {
        int id = rand() % 3 + 1;
        db->execSqlAsync(
            "select * from account where account_id = ?",
            [callbackPtr, counter, json](const Result &r) mutable
            {
                if (*counter <= 0)
                    return;
                if (r.size() > 0)
                {
                    auto w = Account(r[0]);
                    json->append(w.toJson());
                    (*counter)--;
                    if ((*counter) == 0)
                    {
                        (*callbackPtr)(HttpResponse::newHttpJsonResponse(
                            std::move(*json)));
                    }
                }
                else
                {
                    *counter = -1;
                    Json::Value json{};
                    json["code"] = 0;
                    json["message"] = "Internal error";
                    (*callbackPtr)(
                        HttpResponse::newHttpJsonResponse(std::move(json)));
                }
            },
            [callbackPtr, counter](const DrogonDbException &e)
            {
                if (*counter <= 0)
                    return;
                *counter = -1;
                Json::Value json{};
                json["code"] = 1;
                json["message"] = e.base().what();
                auto resp = HttpResponse::newHttpJsonResponse(std::move(json));
                (*callbackPtr)(resp);
            },
            id);
    }
}

/**
 * @brief mapper 90ms
 *
 * @param req
 * @param callback
 */
void Mysql::selectMapper(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_DEBUG << "select call";

    // write your application logic here
    static std::once_flag once;
    std::call_once(once, []()
                   { srand(time(NULL)); });
    int queries = 1;
    auto &parameter = req->getParameter("queries");
    if (!parameter.empty())
    {
        queries = atoi(parameter.c_str());
        if (queries > 500)
            queries = 500;
        else if (queries < 1)
            queries = 1;
    }
    auto json = std::make_shared<Json::Value>();
    json->resize(0);
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    auto counter = std::make_shared<int>(queries);
    if (!*_dbClient)
    {
        *_dbClient = drogon::app().getFastDbClient();
    }
    drogon::orm::Mapper<Account> mapper(*_dbClient);

    for (int i = 0; i < queries; i++)
    {
        Account::PrimaryKeyType id = rand() % 3 + 1;
        mapper.findByPrimaryKey(
            id,
            [callbackPtr, counter, json](Account w) mutable
            {
                json->append(w.toJson());
                (*counter)--;
                if ((*counter) == 0)
                {
                    (*callbackPtr)(
                        HttpResponse::newHttpJsonResponse(std::move(*json)));
                }
            },
            [callbackPtr, counter](const DrogonDbException &e)
            {
                if ((*counter) <= 0)
                    return;
                (*counter) = -1;
                Json::Value json{};
                json["code"] = 1;
                json["message"] = e.base().what();
                (*callbackPtr)(
                    HttpResponse::newHttpJsonResponse(std::move(json)));
            });
    }
}

const void testFunc(Account w)
{
}

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