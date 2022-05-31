#include "client.hpp"
#include "http_provider.hpp"
#include "nlohmann/json.hpp"

web3::Client::Client(const std::string &rawurl)
{
    if (rawurl.find("http://") == 0)
    {
        this->provider = new HttpProvider(rawurl);
    }
    else
    {
        throw std::runtime_error("unkown url format.");
    }
}

web3::Client::Client(Provider *provider)
{
    this->provider = provider;
}

uint64_t web3::Client::blockNumber()
{
    auto res = this->provider->call("eth_blockNumber", {});
    auto j = nlohmann::json::parse(res);
    return j["result"];
}