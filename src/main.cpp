#include <iostream>
#include <string>

#include "client.hpp"

int main(void)
{
    web3::Client client("http://127.0.0.1:8000");
    std::cout << "block_number: " << client.blockNumber() << std::endl;
    std::cout << "chain_id: " << client.chainId() << std::endl;
    std::cout << "gas_price: " << client.gasPrice() << std::endl;
}
