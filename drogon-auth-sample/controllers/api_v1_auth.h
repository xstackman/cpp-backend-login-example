#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
namespace v1
{
class auth : public drogon::HttpController<auth>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(auth::login, "/login",Post);
    METHOD_LIST_END

    void login(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback);
};
}
}
