// #pragma once
// #include <drogon/HttpController.h>
// #include "models/Account.h"
// #include "logic/common/CallBack.h"

// using namespace drogon_model;

// class InsertCallBackSuccess
// {
// public:
//     InsertCallBackSuccess(){};
//     void operator()() const
//     {
//         // if (r.size() == 0)
//         // {
//         //     LOG_DEBUG << "user not found.";
//         // }
//         // else
//         // {
//         //     LOG_WARN << "failed";
//         //     Json::Value json{};
//         //     json["result"] = -1;
//         //     auto response = HttpResponse::newHttpJsonResponse(std::move(json));
//         //     response->addHeader("Access-Control-Allow-Origin", "*");
//         //     response->addHeader("Access-Control-Allow-Credentials", "true");
//         //     (*_callbackPtr)(response);
//         // }
//         // if (*_counter <= 0)
//         //     return;
//         // if (r.size() > 0)
//         // {
//         //     auto w = Account(r[0]);
//         //     _json->append(w.toJson());
//         //     (*_counter)--;
//         //     if ((*_counter) == 0)
//         //     {
//         //         (*_callbackPtr)(HttpResponse::newHttpJsonResponse(
//         //             std::move(*_json)));
//         //     }
//         // }
//         // else
//         // {
//         //     *_counter = -1;
//         //     Json::Value json{};
//         //     json["code"] = 0;
//         //     json["message"] = "Internal error";
//         //     (*_callbackPtr)(
//         //         HttpResponse::newHttpJsonResponse(std::move(json)));
//         // }
//     }

// private:
//     std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
//     std::shared_ptr<Json::Value> _params;
// };

// class SelectCallBackSuccess
// {
// public:
//     SelectCallBackSuccess(std::shared_ptr<drogon::AdviceCallback> callbackPtr,
//                           std::shared_ptr<Json::Value> params) : _callbackPtr(callbackPtr), _params(params){};
//     void operator()(const Result &r) const
//     {
//         if (r.size() == 0)
//         {
//             LOG_DEBUG << "user not found.";

//             drogon::orm::Mapper<mydb::Account> mapper(app().getFastDbClient());
//             auto account = mydb::Account();
//             account.setMailAddress(_params->get("mailAddress", "default").asString());
//             account.setPassword(_params->get("password", "default").asString());

//             mapper.insert(account, InsertCallBackSuccess{}, CallBackDBAccessFailed{_callbackPtr});

//             // Json::Value json{};
//             // json["result"] = 1;
//             // auto response = HttpResponse::newHttpJsonResponse(std::move(json));
//             // response->addHeader("Access-Control-Allow-Origin", "*");

//             // drogon::Cookie cookie1("authKey", drogon::utils::getUuid());
//             // cookie1.setExpiresDate(trantor::Date(0, 3, 0, 0, 0, 0));
//             // response->addCookie(cookie1);

//             // response->addCookie("authKey", drogon::utils::getUuid());
//             // response->addCookie("ExpiresDate");
//             // response->getCookies()["ExpiresDate"] = trantor::Date(0, 3, 0, 0, 0, 0);
//             // (*callbackPtr)(response);
//         }
//         else
//         {
//             LOG_WARN << "failed";
//             Json::Value json{};
//             json["result"] = -1;
//             auto response = HttpResponse::newHttpJsonResponse(std::move(json));
//             response->addHeader("Access-Control-Allow-Origin", "*");
//             response->addHeader("Access-Control-Allow-Credentials", "true");
//             (*_callbackPtr)(response);
//         }
//         // if (*_counter <= 0)
//         //     return;
//         // if (r.size() > 0)
//         // {
//         //     auto w = Account(r[0]);
//         //     _json->append(w.toJson());
//         //     (*_counter)--;
//         //     if ((*_counter) == 0)
//         //     {
//         //         (*_callbackPtr)(HttpResponse::newHttpJsonResponse(
//         //             std::move(*_json)));
//         //     }
//         // }
//         // else
//         // {
//         //     *_counter = -1;
//         //     Json::Value json{};
//         //     json["code"] = 0;
//         //     json["message"] = "Internal error";
//         //     (*_callbackPtr)(
//         //         HttpResponse::newHttpJsonResponse(std::move(json)));
//         // }
//     }

// private:
//     std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
//     std::shared_ptr<Json::Value> _params;
// };
