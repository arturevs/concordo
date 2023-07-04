/**
 * @file System.h
 * @brief Definição da classe System
 * 
 * 
 */

#include <bits/stdc++.h>
#include "User.h"
#include "Channel.h"
#include "Server.h"

#ifndef SYSTEM_H
#define SYSTEM_H


/**
 * @brief Classe que representa o sistema.
 * 
 * 
 */
class System
{
    private:
        int l_id_assigned = 1; //!< Variável que guarda o id do próximo usuário a ser criado.
        int logged_user = -1; //!< Variável que guarda o id do usuário logado.
        std::vector<User> users; //!< Vetor que guarda todos os usuários do sistema.
        std::vector<Server> servers; //!< Vetor que guarda todos os servidores do sistema.
        Server* current_server = nullptr; //!< Ponteiro para o servidor atual.
        Channel* current_channel; //!< Ponteiro para o canal atual.
    public:
        Channel* get_current_channel(); //!< Retorna o ponteiro para o canal atual.
        Server* get_current_server(); //!< Retorna o ponteiro para o servidor atual.
        std::string logged_user_name(); //!< Retorna o nome do usuário logado.
        std::string logged_email(); //!< Retorna o email do usuário logado.
        int increase_l_id(); //!< Aumenta o id do próximo usuário a ser criado.
        void executable(); //!< Método que executa o sistema.
        void create_user(std::string email, std::string password, std::string name); //!< Método que cria um usuário.
        void login(std::string email, std::string password); //!< Método que faz o login de um usuário.
        // here begins the logged in methods
        void disconnect(); //!< Método que faz o logout de um usuário.
        void create_server(std::string name); //!< Método que cria um servidor.
        void change_server_description(std::string name, std::string description); //!< Método que altera a descrição de um servidor.
        void set_server_invite_code(std::string name, std::string invite_code); //!< Método que altera o código de convite de um servidor.
        void list_servers(); //!< Método que lista os servidores.
        void remove_server(std::string name); //!< Método que remove um servidor.
        void join_server(std::string name, std::string invite_code); //!< Método que adiciona o usuário em um servidor.
        void enter_server(std::string name); //!< Método que entra em um servidor.
        void leave_server(); //!< Método que sai de um servidor.
        void enter_channel(std::string name); //!< Método que entra em um canal.
};

#endif

