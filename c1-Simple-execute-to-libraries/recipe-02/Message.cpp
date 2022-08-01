#include "Message.hpp"

#include <iostream>
#include <string>

std::ostream &Message::printObject(std::ostream &os)
{
    os << "This is very nice message: " << std::endl;
    os << message_;
    return os;
}