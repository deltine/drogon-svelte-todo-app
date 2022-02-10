/**
 *
 *  Sequelizemeta.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Sequelizemeta.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::mydb;

const std::string Sequelizemeta::Cols::_name = "name";
const std::string Sequelizemeta::primaryKeyName = "name";
const bool Sequelizemeta::hasPrimaryKey = true;
const std::string Sequelizemeta::tableName = "sequelizemeta";

const std::vector<typename Sequelizemeta::MetaData> Sequelizemeta::metaData_={
{"name","std::string","varchar(255)",255,0,1,1}
};
const std::string &Sequelizemeta::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Sequelizemeta::Sequelizemeta(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 1 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Sequelizemeta::Sequelizemeta(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 1)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
}

Sequelizemeta::Sequelizemeta(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("name"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

void Sequelizemeta::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 1)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
}

void Sequelizemeta::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("name"))
    {
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

const std::string &Sequelizemeta::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Sequelizemeta::getName() const noexcept
{
    return name_;
}
void Sequelizemeta::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[0] = true;
}
void Sequelizemeta::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[0] = true;
}
const typename Sequelizemeta::PrimaryKeyType & Sequelizemeta::getPrimaryKey() const
{
    assert(name_);
    return *name_;
}

void Sequelizemeta::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Sequelizemeta::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "name"
    };
    return inCols;
}

void Sequelizemeta::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Sequelizemeta::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    return ret;
}

void Sequelizemeta::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Sequelizemeta::toJson() const
{
    Json::Value ret;
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    return ret;
}

Json::Value Sequelizemeta::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 1)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[0]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    return ret;
}

bool Sequelizemeta::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(0, "name", pJson["name"], err, true))
            return false;
    }
    else
    {
        err="The name column cannot be null";
        return false;
    }
    return true;
}
bool Sequelizemeta::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                       const std::vector<std::string> &pMasqueradingVector,
                                                       std::string &err)
{
    if(pMasqueradingVector.size() != 1)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Sequelizemeta::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(0, "name", pJson["name"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    return true;
}
bool Sequelizemeta::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                     const std::vector<std::string> &pMasqueradingVector,
                                                     std::string &err)
{
    if(pMasqueradingVector.size() != 1)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Sequelizemeta::validJsonOfField(size_t index,
                                     const std::string &fieldName,
                                     const Json::Value &pJson,
                                     std::string &err,
                                     bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}