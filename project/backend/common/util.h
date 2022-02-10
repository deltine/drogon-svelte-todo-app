#pragma once
#include <drogon/HttpController.h>

class CallBackDBAccessFailed
{
public:
    CallBackDBAccessFailed(std::shared_ptr<drogon::AdviceCallback> callbackPtr) : _callbackPtr(callbackPtr){};
    void operator()(const DrogonDbException &e) const
    {
        LOG_ERROR << "DB Access failed: " << e.base().what();
        Json::Value json{};
        json["res"] = 0;
        auto response = HttpResponse::newHttpJsonResponse(std::move(json));
        response->setStatusCode(HttpStatusCode::k500InternalServerError);
        response->addHeader("Access-Control-Allow-Origin", "*");
        response->addHeader("Access-Control-Allow-Credentials", "true");
        (*_callbackPtr)(response);
    }

private:
    std::shared_ptr<drogon::AdviceCallback> _callbackPtr;
};

class MakeResponse
{
public:
    static drogon::HttpResponsePtr success()
    {
        return success(Json::Value());
    }

    static drogon::HttpResponsePtr success(Json::Value body)
    {
        body["result"] = 1;
        auto response = HttpResponse::newHttpJsonResponse(std::move(body));
        response->setStatusCode(HttpStatusCode::k201Created);
        // response->addHeader("Access-Control-Allow-Origin", "*");
        // response->addHeader("Access-Control-Allow-Credentials", "true");
        return response;
    }

    static drogon::HttpResponsePtr faild(HttpStatusCode code)
    {
        Json::Value json{};
        json["result"] = 0;
        auto response = HttpResponse::newHttpJsonResponse(std::move(json));
        response->setStatusCode(code);
        // response->addHeader("Access-Control-Allow-Origin", "*");
        // response->addHeader("Access-Control-Allow-Credentials", "true");
        return response;
    }
};

class Process
{
public:
    static std::string getId()
    {
        return "[" + drogon::utils::getUuid() + "] ";
    }
};