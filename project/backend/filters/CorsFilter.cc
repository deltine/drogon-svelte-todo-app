/**
 *
 *  CorsFilter.cc
 *
 */

#include "CorsFilter.h"

using namespace drogon;

void CorsFilter::doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb)
{
    LOG_DEBUG << "call";
    if (req->method() == Post)
    {
        LOG_DEBUG << "Post";
        auto &origin = req->getHeader("Origin");
        LOG_DEBUG << "origin: " << origin;
        auto res = HttpResponse::newHttpJsonResponse(Json::Value());
        res->addHeader("Access-Control-Allow-Origin", origin);
        res->addHeader("Access-Control-Allow-Methods", "OPTIONS,POST");
        res->addHeader("Access-Control-Allow-Headers",
                       "x-requested-with,content-type");
        res->addHeader("Access-Control-Allow-Credentials", "true");
        fcb(res);
        return;
    }
    LOG_DEBUG << "!Post";
    fccb();
}
