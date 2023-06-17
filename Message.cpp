#include <iostream>
#include <string>
#include "Message.h"

Message::Message(std::string sentAt, int sentBy, std::string content)
{
    this->sentAt = sentAt;
    this->sentBy = sentBy;
    this->content = content;
}

std::string Message::getSentAt() { return sentAt; }

int Message::getSentBy() { return sentBy; }

std::string Message::getContent() { return content; }

bool Message::operator==(const Message &other)
{
    return (this->sentAt == other.sentAt && this->sentBy == other.sentBy && this->content == other.content);
}