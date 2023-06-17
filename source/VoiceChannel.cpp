#include <iostream>
#include <string>
#include "VoiceChannel.h"
#include "Message.cpp"

Message VoiceChannel::getLastMessage() { return last_message; }

void VoiceChannel::send(Message message)
{
    last_message = message;
}