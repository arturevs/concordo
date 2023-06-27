/**
 * @file Channel.cpp
 * @brief Implementação da classe Channel 
 */

#include <iostream>
#include <string>
#include "Channel.h"

/**
 * @brief Construtor de Channel
 * 
 * @param name 
 */
Channel::Channel(std::string name)
{
    this->name = name;
}

std::string Channel::getName() { return name; }