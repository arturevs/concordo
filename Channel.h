#include <iostream>
#include <string>

class Channel
{
private:
    std::string name;

public:
    Channel(std::string name);
    std::string getName();
};