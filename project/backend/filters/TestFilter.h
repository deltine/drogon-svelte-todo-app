/**
 *
 *  TestFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;

class TestFilter : public HttpFilter<TestFilter>
{
public:
    TestFilter() {}
    virtual void doFilter(const HttpRequestPtr &req,
                          FilterCallback &&fcb,
                          FilterChainCallback &&fccb) override;
};
