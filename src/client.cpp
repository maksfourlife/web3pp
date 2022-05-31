#include "client.hpp"
#include "http_provider.hpp"
#include "nlohmann/json.hpp"
#include "utils.hpp"

web3::Client::Client(const std::string &rawurl)
{
    if (rawurl.find("http://") == 0 || rawurl.find("https://") == 0)
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
    return web3::utils::hexToUint64(nlohmann::json::parse(res)["result"]);
}

uint64_t web3::Client::chainId()
{
    auto res = this->provider->call("eth_chainId", {});
    return web3::utils::hexToUint64(nlohmann::json::parse(res)["result"]);
}

uint64_t web3::Client::gasPrice()
{
    auto res = this->provider->call("eth_gasPrice", {});
    return web3::utils::hexToUint64(nlohmann::json::parse(res)["result"]);
}