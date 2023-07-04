#ifndef TEXTCHANNEL_H
#define TEXTCHANNEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Channel.h"
#include "Message.h"
#include <ctime>

class TextChannel : public Channel
{
    private:
        Message last_message;
        std::vector<Message> messages;
    public:
        TextChannel(std::string name);
        void send(std::string message, int logged_user_id);
};

#endif