#pragma once
#include <drogon/HttpController.h>

class CallBackDBAccessFailed
{
public:
    CallBackDBAccessFailed(std::shared_ptr<drogon::AdviceCallback> callbackPtr) : _callbackPtr(callbackPtr){};
    void operator()(const DrogonDbException &e) const
    {
        LOG_DEBUG << "DB Access failed";
        // LOG_DEBUG << e->
        Json::Value json{};
        json["res"] = 0;
        auto response = HttpResponse::newHttpJsonResponse(std::move(json));
        response->addHeader("Access-Control-Allow-Origin", "*");
        response->addHeader("Access-Control-Allow-Credentials", "true");
        (*_callbackPtr)(response);
    }

private:
    std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
};