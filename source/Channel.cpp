#include <iostream>
#include <string>
#include "Channel.h"

Channel::Channel(std::string name)
{
    this->name = name;
}

std::string Channel::getName() { return name; }