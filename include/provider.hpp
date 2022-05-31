#pragma once
#include <string>
#include <vector>

class Provider
{
public:
    virtual std::string call(const std::string &method, const std::vector<std::string> &params)
    {
        throw std::runtime_error("Can't use call() in base Provider");
    }
};
