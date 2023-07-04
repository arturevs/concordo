/**
 * @file VoiceChannel.cpp
 * @brief Implementação da classe VoiceChannel
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "VoiceChannel.h"
#include "Message.h"
#include <ctime>

/**
 * @brief Construtor de VoiceChannel
 * 
 * @param name 
 */
VoiceChannel::VoiceChannel(std::string name = "") : Channel(name)
{
    this->name = name;
}


/**
 * @brief Retorna a última mensagem enviada no canal
 * 
 * @return Message 
 */
Message VoiceChannel::getLastMessage() { return last_message; }

/**
 * @brief Envia uma mensagem no canal
 * 
 * @param message 
 * @param logged_user_id 
 */
void VoiceChannel::send(std::string message, int logged_user_id)
{

    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string time = std::to_string(ltm->tm_mday) + "/" + std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(1900 + ltm->tm_year) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);

    Message msg;
    msg.setSentBy(logged_user_id);
    msg.setSentAt(time);
    msg.setContent(message);
    last_message = msg;
}