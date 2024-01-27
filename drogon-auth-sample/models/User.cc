/**
 *
 *  User.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "User.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::drogondb;

const std::string User::Cols::_id = "id";
const std::string User::Cols::_first_name = "first_name";
const std::string User::Cols::_last_name = "last_name";
const std::string User::Cols::_username = "username";
const std::string User::Cols::_password = "password";
const std::string User::primaryKeyName = "id";
const bool User::hasPrimaryKey = true;
const std::string User::tableName = "user";

const std::vector<typename User::MetaData> User::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"first_name","std::string","varchar(30)",30,0,0,1},
{"last_name","std::string","varchar(30)",30,0,0,1},
{"username","std::string","varchar(20)",20,0,0,1},
{"password","std::string","binary(60)",0,0,0,1}
};
const std::string &User::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
User::User(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["first_name"].isNull())
        {
            firstName_=std::make_shared<std::string>(r["first_name"].as<std::string>());
        }
        if(!r["last_name"].isNull())
        {
            lastName_=std::make_shared<std::string>(r["last_name"].as<std::string>());
        }
        if(!r["username"].isNull())
        {
            username_=std::make_shared<std::string>(r["username"].as<std::string>());
        }
        if(!r["password"].isNull())
        {
            password_=std::make_shared<std::string>(r["password"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 5 > r.size())
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
            firstName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            lastName_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            username_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            password_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

User::User(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
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
            firstName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            lastName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            username_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

User::User(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("first_name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["first_name"].isNull())
        {
            firstName_=std::make_shared<std::string>(pJson["first_name"].asString());
        }
    }
    if(pJson.isMember("last_name"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["last_name"].isNull())
        {
            lastName_=std::make_shared<std::string>(pJson["last_name"].asString());
        }
    }
    if(pJson.isMember("username"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["username"].isNull())
        {
            username_=std::make_shared<std::string>(pJson["username"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
}

void User::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
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
            firstName_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            lastName_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            username_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            password_=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
        }
    }
}

void User::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("first_name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["first_name"].isNull())
        {
            firstName_=std::make_shared<std::string>(pJson["first_name"].asString());
        }
    }
    if(pJson.isMember("last_name"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["last_name"].isNull())
        {
            lastName_=std::make_shared<std::string>(pJson["last_name"].asString());
        }
    }
    if(pJson.isMember("username"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["username"].isNull())
        {
            username_=std::make_shared<std::string>(pJson["username"].asString());
        }
    }
    if(pJson.isMember("password"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["password"].isNull())
        {
            password_=std::make_shared<std::string>(pJson["password"].asString());
        }
    }
}

const int32_t &User::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &User::getId() const noexcept
{
    return id_;
}
void User::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}
const typename User::PrimaryKeyType & User::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &User::getValueOfFirstName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(firstName_)
        return *firstName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getFirstName() const noexcept
{
    return firstName_;
}
void User::setFirstName(const std::string &pFirstName) noexcept
{
    firstName_ = std::make_shared<std::string>(pFirstName);
    dirtyFlag_[1] = true;
}
void User::setFirstName(std::string &&pFirstName) noexcept
{
    firstName_ = std::make_shared<std::string>(std::move(pFirstName));
    dirtyFlag_[1] = true;
}

const std::string &User::getValueOfLastName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(lastName_)
        return *lastName_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getLastName() const noexcept
{
    return lastName_;
}
void User::setLastName(const std::string &pLastName) noexcept
{
    lastName_ = std::make_shared<std::string>(pLastName);
    dirtyFlag_[2] = true;
}
void User::setLastName(std::string &&pLastName) noexcept
{
    lastName_ = std::make_shared<std::string>(std::move(pLastName));
    dirtyFlag_[2] = true;
}

const std::string &User::getValueOfUsername() const noexcept
{
    const static std::string defaultValue = std::string();
    if(username_)
        return *username_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getUsername() const noexcept
{
    return username_;
}
void User::setUsername(const std::string &pUsername) noexcept
{
    username_ = std::make_shared<std::string>(pUsername);
    dirtyFlag_[3] = true;
}
void User::setUsername(std::string &&pUsername) noexcept
{
    username_ = std::make_shared<std::string>(std::move(pUsername));
    dirtyFlag_[3] = true;
}

const std::string &User::getValueOfPassword() const noexcept
{
    const static std::string defaultValue = std::string();
    if(password_)
        return *password_;
    return defaultValue;
}
const std::shared_ptr<std::string> &User::getPassword() const noexcept
{
    return password_;
}
void User::setPassword(const std::string &pPassword) noexcept
{
    password_ = std::make_shared<std::string>(pPassword);
    dirtyFlag_[4] = true;
}
void User::setPassword(std::string &&pPassword) noexcept
{
    password_ = std::make_shared<std::string>(std::move(pPassword));
    dirtyFlag_[4] = true;
}

void User::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &User::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "first_name",
        "last_name",
        "username",
        "password"
    };
    return inCols;
}

void User::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getFirstName())
        {
            binder << getValueOfFirstName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getLastName())
        {
            binder << getValueOfLastName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getUsername())
        {
            binder << getValueOfUsername();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> User::updateColumns() const
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
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    return ret;
}

void User::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getFirstName())
        {
            binder << getValueOfFirstName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getLastName())
        {
            binder << getValueOfLastName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getUsername())
        {
            binder << getValueOfUsername();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPassword())
        {
            binder << getValueOfPassword();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value User::toJson() const
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
    if(getFirstName())
    {
        ret["first_name"]=getValueOfFirstName();
    }
    else
    {
        ret["first_name"]=Json::Value();
    }
    if(getLastName())
    {
        ret["last_name"]=getValueOfLastName();
    }
    else
    {
        ret["last_name"]=Json::Value();
    }
    if(getUsername())
    {
        ret["username"]=getValueOfUsername();
    }
    else
    {
        ret["username"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    return ret;
}

Json::Value User::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 5)
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
            if(getFirstName())
            {
                ret[pMasqueradingVector[1]]=getValueOfFirstName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getLastName())
            {
                ret[pMasqueradingVector[2]]=getValueOfLastName();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getUsername())
            {
                ret[pMasqueradingVector[3]]=getValueOfUsername();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getPassword())
            {
                ret[pMasqueradingVector[4]]=getValueOfPassword();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
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
    if(getFirstName())
    {
        ret["first_name"]=getValueOfFirstName();
    }
    else
    {
        ret["first_name"]=Json::Value();
    }
    if(getLastName())
    {
        ret["last_name"]=getValueOfLastName();
    }
    else
    {
        ret["last_name"]=Json::Value();
    }
    if(getUsername())
    {
        ret["username"]=getValueOfUsername();
    }
    else
    {
        ret["username"]=Json::Value();
    }
    if(getPassword())
    {
        ret["password"]=getValueOfPassword();
    }
    else
    {
        ret["password"]=Json::Value();
    }
    return ret;
}

bool User::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("first_name"))
    {
        if(!validJsonOfField(1, "first_name", pJson["first_name"], err, true))
            return false;
    }
    else
    {
        err="The first_name column cannot be null";
        return false;
    }
    if(pJson.isMember("last_name"))
    {
        if(!validJsonOfField(2, "last_name", pJson["last_name"], err, true))
            return false;
    }
    else
    {
        err="The last_name column cannot be null";
        return false;
    }
    if(pJson.isMember("username"))
    {
        if(!validJsonOfField(3, "username", pJson["username"], err, true))
            return false;
    }
    else
    {
        err="The username column cannot be null";
        return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(4, "password", pJson["password"], err, true))
            return false;
    }
    else
    {
        err="The password column cannot be null";
        return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                              const std::vector<std::string> &pMasqueradingVector,
                                              std::string &err)
{
    if(pMasqueradingVector.size() != 5)
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
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[3] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
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
bool User::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("first_name"))
    {
        if(!validJsonOfField(1, "first_name", pJson["first_name"], err, false))
            return false;
    }
    if(pJson.isMember("last_name"))
    {
        if(!validJsonOfField(2, "last_name", pJson["last_name"], err, false))
            return false;
    }
    if(pJson.isMember("username"))
    {
        if(!validJsonOfField(3, "username", pJson["username"], err, false))
            return false;
    }
    if(pJson.isMember("password"))
    {
        if(!validJsonOfField(4, "password", pJson["password"], err, false))
            return false;
    }
    return true;
}
bool User::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err)
{
    if(pMasqueradingVector.size() != 5)
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
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
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
bool User::validJsonOfField(size_t index,
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
            if(pJson.isString() && pJson.asString().length() > 30)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 30)";
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
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 30)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 30)";
                return false;
            }

            break;
        case 3:
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
            if(pJson.isString() && pJson.asString().length() > 20)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 20)";
                return false;
            }

            break;
        case 4:
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
    }
    return true;
}
