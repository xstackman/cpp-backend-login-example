#include "api_v1_auth.h"
#include "../models/User.h"
#include <drogon/orm/Mapper.h>
#include <drogon/orm/Criteria.h>

using namespace api::v1;

void api::v1::auth::login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
    Json::Value response, jsonRequest;
    Json::Reader reader;
    Json::FastWriter fastwriter;
    auto resp = HttpResponse::newHttpResponse();

    try {
        bool requestParsing = reader.parse(std::string{req->getBody()},jsonRequest);
        if(requestParsing){
            auto db_client = drogon::app().getDbClient();
            drogon::orm::Mapper<drogon_model::drogondb::User> mapper(db_client);
            auto dbuser = mapper.findOne(drogon::orm::Criteria("username",drogon::orm::CompareOperator::EQ,jsonRequest.get("username","None").asString()));
            // Validate hashed password
            if(*((dbuser.getPassword()).get()) == jsonRequest.get("password","None").asString()){
                req->session()->insert(jsonRequest.get("username","None").asString(),"logged");
                LOG_DEBUG << "USER " << jsonRequest.get("username","None").asString() << " logged";
                response["msg"] = "User logged correctly";
                resp->setStatusCode(k200OK);
                resp->setContentTypeCode(CT_APPLICATION_JSON);
                resp->setBody(fastwriter.write(response));
                callback(resp);
            }else{
                LOG_DEBUG << "USER " << jsonRequest.get("username","None").asString() << " used wrong password";
                response["msg"] = "Wrong password";
                resp->setStatusCode(k401Unauthorized);
                resp->setContentTypeCode(CT_APPLICATION_JSON);
                resp->setBody(fastwriter.write(response));
                callback(resp);
            }
        }else{
            response["msg"] = "Something went wrong. Try again later";
            response["detail"] = "Cannot parsing body request";
            resp->setStatusCode(k400BadRequest);
            resp->setContentTypeCode(CT_APPLICATION_JSON);
            resp->setBody(fastwriter.write(response));
            callback(resp);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        response["msg"] = "Something went wrong. Try again later";
        response["detail"] = e.what();
        resp->setStatusCode(k400BadRequest);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(fastwriter.write(response));
        callback(resp);
    }
}

void api::v1::auth::signup(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
    Json::Value response, jsonRequest;
    Json::Reader reader;
    Json::FastWriter fastwriter;
    auto resp = HttpResponse::newHttpResponse();
    bool res = true;

    try {
        bool requestParsing = reader.parse(std::string{req->getBody()},jsonRequest);
        auto db_client = drogon::app().getDbClient();
        if(requestParsing){
            try {
                // If the username is not found in the database throw an exception and jump to catch
                drogon::orm::Mapper<drogon_model::drogondb::User> mapper(db_client);
                auto dbuser = mapper.findOne(drogon::orm::Criteria("username",drogon::orm::CompareOperator::EQ,jsonRequest.get("username","None").asString()));
                LOG_DEBUG << "USER " << *((dbuser.getPassword()).get());
                response["msg"] = "Username already exist";
                resp->setStatusCode(k400BadRequest);
                resp->setContentTypeCode(CT_APPLICATION_JSON);
                resp->setBody(fastwriter.write(response));
                callback(resp);

            } catch(const std::exception& e) {
                // Username don't exist in the database, then create it.
                // TODO:
                // Make all validations in all required fields
                // Implement bcrypt in password field before write in db

                auto user = drogon_model::drogondb::User(jsonRequest);
                // I still need to investigate for what is the res variable. ¯\_(ツ)_/¯
                db_client->execSqlAsync(user.sqlForInserting(res), 
                                        [](const drogon::orm::Result &result) {
                                            LOG_DEBUG << "User created!";
                                        },
                                        [](const drogon::orm::DrogonDbException &e) {
                                            LOG_ERROR << "error:" << e.base().what();
                                        },
                                        jsonRequest.get("first_name","None").asString(),
                                        jsonRequest.get("last_name","None").asString(),
                                        jsonRequest.get("username","None").asString(),
                                        jsonRequest.get("password","None").asString()
                                        );
                resp->setStatusCode(k200OK);
                resp->setContentTypeCode(CT_APPLICATION_JSON);
                resp->setBody(fastwriter.write(user.toJson()));
                callback(resp);
            } 
        }else{
            LOG_ERROR << "Cannot parse body";
            response["msg"] = "Cannot parse that body";
            resp->setStatusCode(k400BadRequest);
            resp->setContentTypeCode(CT_APPLICATION_JSON);
            resp->setBody(fastwriter.write(response));
            callback(resp);
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        response["msg"] = "Something went wrong. Try again later";
        response["detail"] = e.what();
        resp->setStatusCode(k400BadRequest);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(fastwriter.write(response));
        callback(resp);
    }
}
