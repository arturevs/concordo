/**
 * @file Server.h
 * @brief Definição da classe Server
 */

#include <bits/stdc++.h>
#include "User.h"
#include "Channel.h"

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
        std::string name; //!< Variável que guarda o nome do servidor.
        std::string description; //!< Variável que guarda a descrição do servidor.
        std::string invite_code; //!< Variável que guarda o código de convite do servidor.
        std::vector<int> members; //!< Vetor que guarda os ids dos membros do servidor.
        std::vector<Channel*> channels; //!< Vetor que guarda os canais do servidor.
    public:
        Server(std::string name); //!< Construtor da classe Server.
        void server_clear(); //!< Método que limpa o servidor.
        int getOwner(); //!< Método que retorna o id do dono do servidor.
        std::string getName(); //!< Método que retorna o nome do servidor.
        std::string getDescription(); //!< Método que retorna a descrição do servidor.
        std::string getInviteCode(); //!< Método que retorna o código de convite do servidor.
        std::vector<int> getMembers(); //!< Método que retorna os ids dos membros do servidor.
        std::vector<Channel*> getChannels(); //!< Método que retorna os canais do servidor.
        bool getInviteCodeEnabled(); //!< Método que retorna se o código de convite está habilitado.
        void setOwner(int id); //!< Método que altera o id do dono do servidor.
        void setDescription(std::string description); //!< Método que altera a descrição do servidor.
        void setInviteCode(std::string invite_code); //!< Método que altera o código de convite do servidor.
        void removeInviteCode(); //!< Método que remove o código de convite do servidor.
        void addMember(int id); //!< Método que adiciona um membro ao servidor.
        void removeMember(int id); //!< Método que remove um membro do servidor.
        void listMembers(); //!< Método que lista os membros do servidor.
        bool memberExists(int id); //!< Método que verifica se um membro existe no servidor.
};

#endif