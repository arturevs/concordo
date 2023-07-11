/**
 * @file TextChannel.h
 * @brief Classe que representa um canal de texto
 */

#ifndef TEXTCHANNEL_H
#define TEXTCHANNEL_H

#include <iostream>
#include <string>
#include <vector>
#include "Channel.h"
#include "Message.h"
#include <ctime>

/**
 * @brief Classe que representa um canal de texto
 * 
 */
class TextChannel : public Channel
{
    private:
        std::vector<Message> messages; //!< Vetor que guarda todas as mensagens enviadas no canal.
    public:
        TextChannel();
        std::vector<Message> getMessages(); //!< Método que retorna todas as mensagens enviadas no canal.
        TextChannel(std::string name); //!< Construtor da classe TextChannel.
        void send(std::string message, int logged_user_id); //!< Método que envia uma mensagem no canal.
        void list_messages();
        void add_message(Message message);
};

#endif