#include <iostream>
#include <string>
#include "Channel.cpp"
#include "Message.cpp"

class VoiceChannel : protected Channel
{
    private:
        Message last_message;
    public:
        VoiceChannel(std::string name);
        Message getLastMessage();
        void send(Message message);
};