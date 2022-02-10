#include "common/HttpReqestMgr.h"

using namespace std;
using namespace drogon;

// unordered_map<std::string, std::string> &HttpReqestMgr::getParam(const HttpRequestPtr &req)
shared_ptr<Json::Value> HttpReqestMgr::getParams(const HttpRequestPtr &req)
{
    LOG_TRACE << "ContentType: " << req->getContentType();

    // urlパラメータ取得
    auto params = req->getParameters();
    if (!params.empty())
    {
        LOG_TRACE << "url params";

        Json::Value url;
        for (auto itr = params.begin(); itr != params.end(); ++itr)
        {
            LOG_TRACE << "key: " << itr->first << " val: " << itr->second;
            url[itr->first.c_str()] = itr->second.c_str();
        }
        return std::make_shared<Json::Value>(std::move(url));
    }

    // urlパラメータがなければjsonパラメータ取得
    auto json = req->getJsonObject();
    if (json)
    {
        LOG_TRACE << "json params";
        auto jsonMenber = json->getMemberNames();
        for (const auto &men : jsonMenber)
        {
            LOG_TRACE << "key: " << men << " val: " << json->get(men, "default").asString();
        }
        return json;
    }
    return std::make_shared<Json::Value>();
}