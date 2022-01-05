/**
 *
 *  Account.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Account.h"
#include "TodoTask.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::mydb;

const std::string Account::Cols::_account_id = "account_id";
const std::string Account::Cols::_account_name = "account_name";
const std::string Account::primaryKeyName = "account_id";
const bool Account::hasPrimaryKey = true;
const std::string Account::tableName = "account";

const std::vector<typename Account::MetaData> Account::metaData_={
{"account_id","uint32_t","int(10) unsigned",4,1,1,1},
{"account_name","std::string","varchar(255)",255,0,0,0}
};
const std::string &Account::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Account::Account(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["account_id"].isNull())
        {
            accountId_=std::make_shared<uint32_t>(r["account_id"].as<uint32_t>());
        }
        if(!r["account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(r["account_name"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            accountId_=std::make_shared<uint32_t>(r[index].as<uint32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            accountName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Account::Account(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            accountId_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

Account::Account(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("account_id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["account_id"].isNull())
        {
            accountId_=std::make_shared<uint32_t>((uint32_t)pJson["account_id"].asUInt64());
        }
    }
    if(pJson.isMember("account_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson["account_name"].asString());
        }
    }
}

void Account::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            accountId_=std::make_shared<uint32_t>((uint32_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
}

void Account::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("account_id"))
    {
        if(!pJson["account_id"].isNull())
        {
            accountId_=std::make_shared<uint32_t>((uint32_t)pJson["account_id"].asUInt64());
        }
    }
    if(pJson.isMember("account_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["account_name"].isNull())
        {
            accountName_=std::make_shared<std::string>(pJson["account_name"].asString());
        }
    }
}

const uint32_t &Account::getValueOfAccountId() const noexcept
{
    const static uint32_t defaultValue = uint32_t();
    if(accountId_)
        return *accountId_;
    return defaultValue;
}
const std::shared_ptr<uint32_t> &Account::getAccountId() const noexcept
{
    return accountId_;
}
void Account::setAccountId(const uint32_t &pAccountId) noexcept
{
    accountId_ = std::make_shared<uint32_t>(pAccountId);
    dirtyFlag_[0] = true;
}
const typename Account::PrimaryKeyType & Account::getPrimaryKey() const
{
    assert(accountId_);
    return *accountId_;
}

const std::string &Account::getValueOfAccountName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(accountName_)
        return *accountName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Account::getAccountName() const noexcept
{
    return accountName_;
}
void Account::setAccountName(const std::string &pAccountName) noexcept
{
    accountName_ = std::make_shared<std::string>(pAccountName);
    dirtyFlag_[1] = true;
}
void Account::setAccountName(std::string &&pAccountName) noexcept
{
    accountName_ = std::make_shared<std::string>(std::move(pAccountName));
    dirtyFlag_[1] = true;
}
void Account::setAccountNameToNull() noexcept
{
    accountName_.reset();
    dirtyFlag_[1] = true;
}

void Account::updateId(const uint64_t id)
{
    accountId_ = std::make_shared<uint32_t>(static_cast<uint32_t>(id));
}

const std::vector<std::string> &Account::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "account_name"
    };
    return inCols;
}

void Account::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getAccountName())
        {
            binder << getValueOfAccountName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Account::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    return ret;
}

void Account::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getAccountName())
        {
            binder << getValueOfAccountName();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Account::toJson() const
{
    Json::Value ret;
    if(getAccountId())
    {
        ret["account_id"]=getValueOfAccountId();
    }
    else
    {
        ret["account_id"]=Json::Value();
    }
    if(getAccountName())
    {
        ret["account_name"]=getValueOfAccountName();
    }
    else
    {
        ret["account_name"]=Json::Value();
    }
    return ret;
}

Json::Value Account::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getAccountId())
            {
                ret[pMasqueradingVector[0]]=getValueOfAccountId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getAccountName())
            {
                ret[pMasqueradingVector[1]]=getValueOfAccountName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getAccountId())
    {
        ret["account_id"]=getValueOfAccountId();
    }
    else
    {
        ret["account_id"]=Json::Value();
    }
    if(getAccountName())
    {
        ret["account_name"]=getValueOfAccountName();
    }
    else
    {
        ret["account_name"]=Json::Value();
    }
    return ret;
}

bool Account::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("account_id"))
    {
        if(!validJsonOfField(0, "account_id", pJson["account_id"], err, true))
            return false;
    }
    if(pJson.isMember("account_name"))
    {
        if(!validJsonOfField(1, "account_name", pJson["account_name"], err, true))
            return false;
    }
    return true;
}
bool Account::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                 const std::vector<std::string> &pMasqueradingVector,
                                                 std::string &err)
{
    if(pMasqueradingVector.size() != 2)
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
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Account::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("account_id"))
    {
        if(!validJsonOfField(0, "account_id", pJson["account_id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("account_name"))
    {
        if(!validJsonOfField(1, "account_name", pJson["account_name"], err, false))
            return false;
    }
    return true;
}
bool Account::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 2)
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
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Account::validJsonOfField(size_t index,
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
            if(!pJson.isUInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
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
void Account::getTodoTask(const DbClientPtr &clientPtr,
                          const std::function<void(std::vector<TodoTask>)> &rcb,
                          const ExceptionCallback &ecb) const
{
    const static std::string sql = "select * from todo_task where account_id = ?";
    *clientPtr << sql
               << *accountId_
               >> [rcb = std::move(rcb)](const Result &r){
                   std::vector<TodoTask> ret;
                   ret.reserve(r.size());
                   for (auto const &row : r)
                   {
                       ret.emplace_back(TodoTask(row));
                   }
                   rcb(ret);
               }
               >> ecb;
}
