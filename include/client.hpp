#pragma once
#include <string>
#include "provider.hpp"

class Client
{
private:
    Provider *provider;

public:
    Client(const std::string &rawurl);
    Client(Provider *provider);
    uint64_t blockNumber();
};
