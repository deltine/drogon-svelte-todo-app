#pragma once
#include <drogon/HttpController.h>
#include <drogon/IOThreadStorage.h>
#include "models/Account.h"

using namespace drogon_model::mydb;

class selectCallBackSuccess
{
public:
    selectCallBackSuccess(std::shared_ptr<drogon::AdviceCallback> callbackPtr,
                          std::shared_ptr<int32_t> counter,
                          std::shared_ptr<Json::Value> json) : _callbackPtr(callbackPtr), _counter(counter), _json(json){};
    void operator()(const Result &r) const
    {
        if (*_counter <= 0)
            return;
        if (r.size() > 0)
        {
            auto w = Account(r[0]);
            _json->append(w.toJson());
            (*_counter)--;
            if ((*_counter) == 0)
            {
                (*_callbackPtr)(HttpResponse::newHttpJsonResponse(
                    std::move(*_json)));
            }
        }
        else
        {
            *_counter = -1;
            Json::Value json{};
            json["code"] = 0;
            json["message"] = "Internal error";
            (*_callbackPtr)(
                HttpResponse::newHttpJsonResponse(std::move(json)));
        }
    }

private:
    std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
    std::shared_ptr<int32_t> _counter;
    std::shared_ptr<Json::Value> _json;
};