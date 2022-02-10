/**
 *
 *  Migrations.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Migrations.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::mydb;

const std::string Migrations::Cols::_id = "id";
const std::string Migrations::Cols::_name = "name";
const std::string Migrations::Cols::_run_on = "run_on";
const std::string Migrations::primaryKeyName = "id";
const bool Migrations::hasPrimaryKey = true;
const std::string Migrations::tableName = "migrations";

const std::vector<typename Migrations::MetaData> Migrations::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"name","std::string","varchar(255)",255,0,0,1},
{"run_on","::trantor::Date","datetime",0,0,0,1}
};
const std::string &Migrations::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Migrations::Migrations(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["run_on"].isNull())
        {
            auto timeStr = r["run_on"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }

}

Migrations::Migrations(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[2]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

Migrations::Migrations(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("run_on"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["run_on"].isNull())
        {
            auto timeStr = pJson["run_on"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void Migrations::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            auto timeStr = pJson[pMasqueradingVector[2]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

void Migrations::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("run_on"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["run_on"].isNull())
        {
            auto timeStr = pJson["run_on"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            time_t t = mktime(&stm);
            size_t decimalNum = 0;
            if(p)
            {
                if(*p=='.')
                {
                    std::string decimals(p+1,&timeStr[timeStr.length()]);
                    while(decimals.length()<6)
                    {
                        decimals += "0";
                    }
                    decimalNum = (size_t)atol(decimals.c_str());
                }
                runOn_=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
            }
        }
    }
}

const int32_t &Migrations::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Migrations::getId() const noexcept
{
    return id_;
}
void Migrations::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Migrations::PrimaryKeyType & Migrations::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Migrations::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Migrations::getName() const noexcept
{
    return name_;
}
void Migrations::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Migrations::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}

const ::trantor::Date &Migrations::getValueOfRunOn() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(runOn_)
        return *runOn_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Migrations::getRunOn() const noexcept
{
    return runOn_;
}
void Migrations::setRunOn(const ::trantor::Date &pRunOn) noexcept
{
    runOn_ = std::make_shared<::trantor::Date>(pRunOn);
    dirtyFlag_[2] = true;
}

void Migrations::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Migrations::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "name",
        "run_on"
    };
    return inCols;
}

void Migrations::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
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
    if(dirtyFlag_[2])
    {
        if(getRunOn())
        {
            binder << getValueOfRunOn();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Migrations::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    return ret;
}

void Migrations::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
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
    if(dirtyFlag_[2])
    {
        if(getRunOn())
        {
            binder << getValueOfRunOn();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Migrations::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getRunOn())
    {
        ret["run_on"]=getRunOn()->toDbStringLocal();
    }
    else
    {
        ret["run_on"]=Json::Value();
    }
    return ret;
}

Json::Value Migrations::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getRunOn())
            {
                ret[pMasqueradingVector[2]]=getRunOn()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getRunOn())
    {
        ret["run_on"]=getRunOn()->toDbStringLocal();
    }
    else
    {
        ret["run_on"]=Json::Value();
    }
    return ret;
}

bool Migrations::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, true))
            return false;
    }
    else
    {
        err="The name column cannot be null";
        return false;
    }
    if(pJson.isMember("run_on"))
    {
        if(!validJsonOfField(2, "run_on", pJson["run_on"], err, true))
            return false;
    }
    else
    {
        err="The run_on column cannot be null";
        return false;
    }
    return true;
}
bool Migrations::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                    const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err)
{
    if(pMasqueradingVector.size() != 3)
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
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
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
bool Migrations::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, false))
            return false;
    }
    if(pJson.isMember("run_on"))
    {
        if(!validJsonOfField(2, "run_on", pJson["run_on"], err, false))
            return false;
    }
    return true;
}
bool Migrations::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                  const std::vector<std::string> &pMasqueradingVector,
                                                  std::string &err)
{
    if(pMasqueradingVector.size() != 3)
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
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
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
bool Migrations::validJsonOfField(size_t index,
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
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
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
        case 2:
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
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}