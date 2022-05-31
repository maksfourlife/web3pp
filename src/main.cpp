#include <iostream>
#include <string>

#include "nlohmann/json.hpp"

int main(void)
{
    nlohmann::json j;
    j["pi"] = 3.14;
    std::cout << j << std::endl;
    try
    {
        std::cin >> j;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << j << std::endl;
}
