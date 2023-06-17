#include <iostream>
#include <string>

class Message
{
private:
    std::string sentAt;
    int sentBy;
    std::string content;

public:
    Message(std::string sentAt, int sentBy, std::string content);
    std::string getSentAt();
    int getSentBy();
    std::string getContent();
    bool operator==(const Message &other);
    Message operator=(const Message &other);
};