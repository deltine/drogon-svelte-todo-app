/**
 *
 *  TestFilter.cc
 *
 */

#include "TestFilter.h"
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#define VDate "visitDate"

using namespace drogon;

void TestFilter::doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb)
{
    // // Edit your logic here
    // if (0)
    // {
    //     // Passed
    //     LOG_DEBUG << "Filter Passed";
    //     fccb();
    //     return;
    // }
    // // Check failed
    // LOG_DEBUG << "Filter failed";

    // // auto res = drogon::HttpResponse::newHttpResponse();
    // // res->setStatusCode(k500InternalServerError);
    // // fcb(res);

    // Json::Value ret;
    // ret["result"] = "Filter failed";
    // ret["token"] = drogon::utils::getUuid();
    // auto resp = HttpResponse::newHttpJsonResponse(ret);
    // fcb(resp);

    trantor::Date now = trantor::Date::date();
    LOG_TRACE << "";
    if (req->session()->find(VDate))
    {
        auto lastDate = req->session()->get<trantor::Date>(VDate);
        LOG_TRACE << "last:" << lastDate.toFormattedString(false);
        req->session()->modify<trantor::Date>(VDate,
                                              [now](trantor::Date &vdate)
                                              {
                                                  vdate = now;
                                              });
        LOG_TRACE << "update visitDate";
        if (now > lastDate.after(10))
        {
            // 10 sec later can visit again;
            fccb();
            return;
        }
        else
        {
            Json::Value json;
            json["result"] = "error";
            json["message"] = "Access interval should be at least 10 seconds";
            auto res = HttpResponse::newHttpJsonResponse(json);
            fcb(res);
            return;
        }
    }
    LOG_TRACE << "first access,insert visitDate";
    req->session()->insert(VDate, now);
    fccb();
}
