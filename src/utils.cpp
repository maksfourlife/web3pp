#include "utils.hpp"

uint64_t web3::utils::hexToUint64(const std::string &s)
{
    return std::stoul(s, nullptr, 16);
}