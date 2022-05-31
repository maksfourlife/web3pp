#pragma once
#include "provider.hpp"
#include "httplib.h"
#include "nlohmann/json.hpp"

class HttpProvider : public Provider, private httplib::Client
{
public:
    HttpProvider(const std::string &rawurl) : Client(rawurl) {}
    std::string call(const std::string &method, const std::vector<std::string> &params) override
    {
        nlohmann::json j;
        j["jsonrpc"] = "2.0";
        j["method"] = method;
        j["params"] = params;
        auto raw = j.dump();
        auto res = this->Post("", raw.c_str(), raw.length(), "application/json");
        return res->body;
    }
};