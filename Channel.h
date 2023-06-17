#include <iostream>
#include <string>

class Channel
{
protected:
    std::string name;

public:
    Channel(std::string name);
    std::string getName();
};