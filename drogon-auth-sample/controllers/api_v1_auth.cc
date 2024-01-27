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
