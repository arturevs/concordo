/**
 * @file Server.h
 * @brief Definição da classe Server
 */

#include <bits/stdc++.h>
#include "User.h"
#include "Channel.h"
#include "VoiceChannel.h"
#include "TextChannel.h"

#ifndef SERVER_H
#define SERVER_H

/**
 * @brief Classe que representa um servidor.
 * 
 */
class Server
{
    protected:
        int owner_id; //!< Variável que guarda o id do dono do servidor.
        bool invite_code_enabled = false; //!< Variável que guarda se o código de convite está habilitado.
        std::string name = ""; //!< Variável que guarda o nome do servidor.
        std::string description = ""; //!< Variável que guarda a descrição do servidor.
        std::string invite_code = ""; //!< Variável que guarda o código de convite do servidor.
        std::vector<int> members; //!< Vetor que guarda os ids dos membros do servidor.
        std::vector<VoiceChannel> voice_channels; //!< Vetor que guarda os canais do servidor.
        std::vector<TextChannel> text_channels; //!< Vetor que guarda os canais do servidor.
    public:
        Server(); //!< Construtor da classe Server.
        Server(std::string name); //!< Construtor da classe Server.
        Server(int owner, std::string name, std::string description, std::string invite_code); //!< Construtor da classe Server.
        void server_clear(); //!< Método que limpa o servidor.
        int getOwner(); //!< Método que retorna o id do dono do servidor.
        std::string getName(); //!< Método que retorna o nome do servidor.
        std::string getDescription(); //!< Método que retorna a descrição do servidor.
        std::string getInviteCode(); //!< Método que retorna o código de convite do servidor.
        std::vector<int> getMembers(); //!< Método que retorna os ids dos membros do servidor.
        std::vector<VoiceChannel> getVoiceChannels(); //!< Método que retorna os canais do servidor.
        std::vector<TextChannel> getTextChannels(); //!< Método que retorna os canais do servidor.
        bool getInviteCodeEnabled(); //!< Método que retorna se o código de convite está habilitado.
        void setOwner(int id); //!< Método que altera o id do dono do servidor.
        void setDescription(std::string description); //!< Método que altera a descrição do servidor.
        void setInviteCode(std::string invite_code); //!< Método que altera o código de convite do servidor.
        void removeInviteCode(); //!< Método que remove o código de convite do servidor.
        void addMember(int id); //!< Método que adiciona um membro ao servidor.
        void removeMember(int id); //!< Método que remove um membro do servidor.
        void listMembers(); //!< Método que lista os membros do servidor.
        bool memberExists(int id); //!< Método que verifica se um membro existe no servidor.
        void create_channel(std::string name, std::string type); //!< Método que adiciona um canal ao servidor.
        void list_channels(); //!< Método que lista os canais do servidor.
        bool find_channel(std::string name); //!< Método que encontra um canal do servidor.
        void add_TextChannel(TextChannel channel); //!< Método que adiciona um canal de texto ao servidor.
        void add_VoiceChannel(VoiceChannel channel); //!< Método que adiciona um canal de voz ao servidor.
        bool operator ==(Server server) //!< Operador de igualdade.
        {
            return (this->name == server.name);
        }
};

#endif