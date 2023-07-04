/**
 * @file VoiceChannel.h
 * @brief Classe que representa um canal de voz
 */

#ifndef VOICECHANNEL_H
#define VOICECHANNEL_H

#include <iostream>
#include <string>
#include "Channel.h"
#include "Message.h"

class VoiceChannel : public Channel
{
    private:
        Message last_message; //!< Variável que guarda a última mensagem enviada no canal.
    public:
        VoiceChannel(std::string name); //!< Construtor da classe VoiceChannel.
        Message getLastMessage(); //!< Método que retorna a última mensagem enviada no canal.
        void send(std::string message, int logged_user_id); //!< Método que envia uma mensagem no canal.
};

#endif