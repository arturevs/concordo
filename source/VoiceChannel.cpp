#include <iostream>
#include <string>
#include "VoiceChannel.h"
#include "Message.cpp"

VoiceChannel::VoiceChannel(std::string name = "") : Channel(name)
{
    this->name = name;
}

Message VoiceChannel::getLastMessage() { return last_message; }

void VoiceChannel::send(Message message)
{
    last_message = message;
}