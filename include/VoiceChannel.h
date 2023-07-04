#ifndef VOICECHANNEL_H
#define VOICECHANNEL_H

#include <iostream>
#include <string>
#include "Channel.h"
#include "Message.h"

class VoiceChannel : public Channel
{
    private:
        Message last_message;
    public:
        VoiceChannel(std::string name);
        Message getLastMessage();
        void send(std::string message, int logged_user_id);
};

#endif