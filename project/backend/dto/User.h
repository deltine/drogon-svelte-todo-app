#pragma once
#include <drogon/HttpRequest.h>

namespace dto
{
    struct User
    {
        std::string userName;
        std::string email;
        std::string address;
    };
}
namespace drogon
{
    template <>
    inline dto::User fromRequest(const HttpRequest &req)
    {
        auto json = req.getJsonObject();
        dto::User user;
        if (json)
        {
            user.userName = (*json)["name"].asString();
            user.email = (*json)["email"].asString();
            user.address = (*json)["address"].asString();
        }
        return user;
    }
}