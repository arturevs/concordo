/**
 * @file TextChannel.cpp
 * @brief Implementação da classe TextChannel
 */

#include <iostream>
#include <string>
#include "TextChannel.h"
#include <ctime>

/**
 * @brief Construtor de TextChannel
 * 
 */
TextChannel::TextChannel() : Channel(name)
{
    this->name = "";
}

/**
 * @brief Construtor de TextChannel
 * 
 * @param name 
 */
TextChannel::TextChannel(std::string name = "") : Channel(name)
{
    this->name = name;
}

/**
 * @brief Envia uma mensagem no canal
 * 
 * @param message 
 * @param logged_user_id 
 */
void TextChannel::send(std::string message, int logged_user_id)
{

    time_t now = time(0); /// pega o tempo atual
    tm *ltm = localtime(&now); /// converte para o tempo local
    std::string time = std::to_string(ltm->tm_mday) + "/" + std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(1900 + ltm->tm_year) + " " + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec);

    Message msg;
    msg.setSentBy(logged_user_id);
    msg.setSentAt(time);
    msg.setContent(message);
    messages.push_back(msg);
}

/**
 * @brief Lista todas as mensagens enviadas no canal
 * 
 */
void TextChannel::list_messages()
{
    for (int i = 0; i < messages.size(); i++)
    {
        std::cout << messages[i].getSentBy() << " " << messages[i].getSentAt() << " " << messages[i].getContent() << std::endl;
    }
}

/**
 * @brief Retorna todas as mensagens enviadas no canal
 * 
 * @return std::vector<Message> 
 */
std::vector<Message> TextChannel::getMessages()
{
    return messages;
}

/**
 * @brief Adiciona uma mensagem ao canal
 * 
 * @param message 
 */
void TextChannel::add_message(Message message)
{
    messages.push_back(message);
}