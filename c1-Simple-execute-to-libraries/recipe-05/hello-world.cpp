#include "Message.hpp"

#include <cstdlib>
#include <iostream>

int main(void)
{
    Message say_hello("Hello, CMake world");
    std::cout << say_hello << std::endl;

    Message say_goodbye("Goodbye, CMake world");
    std::cout << say_goodbye << std::endl;

    return EXIT_SUCCESS;
}