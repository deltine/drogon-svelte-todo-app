#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

namespace std
{
    class HttpReqestMgr
    {
    public:
        /**
         * @brief リクエストパラメータをurlかjsonから取得する。
         *
         * @param req
         * @return std::unordered_map<std::string, std::string>
         */
        // static std::unordered_map<std::string, std::string> &getParam(const HttpRequestPtr &req);
        static shared_ptr<Json::Value> getParams(const HttpRequestPtr &req);
    };
}