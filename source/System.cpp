/**
 * @file System.cpp
 * @brief Implementação dos métodos da classe System.
 * 
 */

#include <bits/stdc++.h>
#include <fstream>
#include "System.h"

/**
 * @brief Retona o ponteiro para o canal atual.
 * 
 * @return Channel* 
 */
Channel* System::get_current_channel()
{
    return current_channel;
}

/**
 * @brief Retorna o ponteiro para o servidor atual.
 * 
 * @return Server* 
 */
Server* System::get_current_server()
{
    return current_server;
}

/**
 * @brief Retorna o nome do usuário logado.
 * 
 * @return std::string 
 */
std::string System::logged_user_name()
{
    int i = 0;
    while(i < users.size())
    {
        if(users[i].getId() == logged_user)
        {
            return users[i].getName();
        }
        i++;
    }
    return " ";
}

/**
 * @brief Retorna o email do usuário logado.
 * 
 * @return std::string 
 */
std::string System::logged_email()
{
    int i = 0;
    while(i < users.size())
    {
        if(users[i].getId() == logged_user)
        {
            return users[i].getEmail();
        }
        i++;
    }
    return " ";
}

/**
 * @brief Atualiza o id que deve ser implementado em um novo usuário.
 * 
 * @return int 
 */
int System::increase_l_id()
{
    return l_id_assigned++;
}

/**
 * @brief Cria o usuário e o adiciona na lista de usuários do sistema.
 * 
 */
void System::create_user(std::string email, std::string password, std::string name)
{
    if(find(users.begin(), users.end(), User(name, email, password)) != users.end())
    {
        std::cout << "Usuário já cadastrado" << '\n';
        return;
    }
    User user = User(name, email, password);
    user.setId(increase_l_id());
    users.push_back(user);
    std::cout << "User created successfully" << '\n';
}

/**
 * @brief Realiza o login do usuário.
 * 
 * @param email do usuário tentando login
 * @param password do usuário tentando login
 */
void System::login(std::string email, std::string password)
{
    if(logged_user != -1)
    {
        std::cout << "User already logged" << '\n';
        return;
    }
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getEmail() == email && users[i].getPassword() == password)
        {
            logged_user = users[i].getId();
            std::cout << "User "<< users[i].getName() << " logged in succsessfully" << '\n';
            return;
        }
    }
    std::cout << "Usuário não encontrado" << '\n';
}

/**
 * @brief Desconecta o usuário logado.
 * 
 */
void System::disconnect()
{   
    std::cout << "User " << logged_user_name() << " disconnected sucssessfully" << '\n';
    logged_user = -1;
}

/**
 * @brief Cria um novo servidor.
 * 
 * @param name nome do servidor
 */
void System::create_server(std::string name)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            std::cout << "Servidor já existente" << '\n';
            return;
        }
        i++;
    }
    Server server = Server(name);
    server.addMember(logged_user);
    server.setOwner(logged_user);
    servers.push_back(server);
    std::cout << "Server created successfully" << '\n';
}

/**
 * @brief Altera a descrição do servidor.
 * 
 * @param name nome do servidor
 * @param description nova descrição do servidor
 */
void System::change_server_description(std::string name, std::string description)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            if(servers[i].getOwner() != logged_user)
            {
                std::cout << "You don't have permission to change this server description" << '\n';
                return;
            } 
            servers[i].setDescription(description);
            std::cout << "Server description changed successfully" << '\n';
            return;
        }
        i++;
    }
    std::cout << "Server not found" << '\n';
}

/**
 * @brief Altera o código de convite do servidor.
 * 
 * @param name nome do servidor
 * @param invite_code novo código de convite
 */
void System::set_server_invite_code(std::string name, std::string invite_code)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            if(servers[i].getOwner() != logged_user)
            {
                std::cout << "You don't have permission to change this server invite code" << '\n';
                return;
            }
            if(invite_code == "")
            {
                servers[i].removeInviteCode();
                return;
            }
            servers[i].setInviteCode(invite_code);
            std::cout << "Server invite code changed successfully" << '\n';
            return;
        }
        i++;
    }
    std::cout << "Server not found" << '\n';
}

/**
 * @brief Lista os servidores do sistema.
 * 
 */
void System::list_servers()
{
    std::cout << "=== Servers ===" << '\n';
    for(int i = 0; i < servers.size(); i++)
    {
        std::cout << servers[i].getName() << '\n';
    }
}

/**
 * @brief Remove um servidor do sistema.
 * 
 * @param name nome do servidor
 */
void System::remove_server(std::string name)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            if(servers[i].getOwner() != logged_user)
            {
                std::cout << "You don't have permission to remove this server" << '\n';
                return;
            }
            if(&servers[i] == current_server)
            {
                current_server = nullptr;
            }
            servers[i].server_clear();
            servers.erase(servers.begin() + i);
            std::cout << "Server removed successfully" << '\n';
            return;
        }
        i++;
    }
    std::cout << "Server not found" << '\n';    
}

/**
 * @brief Adiciona o usuário ao servidor name.
 * 
 * @param name nome do servidor
 * @param invite_code código de convite do servidor
 */
void System::join_server(std::string name, std::string invite_code)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            if(servers[i].getInviteCodeEnabled() == true && servers[i].getInviteCode() != invite_code)
            {
                std::cout << "Invite code invalid" << '\n';
                return;
            }
            if(find(servers[i].getMembers().begin(), servers[i].getMembers().end(), logged_user) != servers[i].getMembers().end())
            {
                std::cout << "You are already a member of this server" << '\n';
                return;
            }
            servers[i].addMember(logged_user);
        }
    }
}

/**
 * @brief Entra em um servidor.
 * 
 * @param name nome do servidor.
 */
void System::enter_server(std::string name)
{
    int i = 0;
    while(i < servers.size())
    {
        if(servers[i].getName() == name)
        {
            if(find(servers[i].getMembers().begin(), servers[i].getMembers().end(), logged_user) == servers[i].getMembers().end())
            {
                std::cout << "You are not a member of this server" << '\n';
                return;
            }
            current_server = &servers[i];
            std::cout << "Server " << name << " selected successfully" << '\n';
            return;
        }
        i++;
    }
    std::cout << "Server not found" << '\n';
}

/**
 * @brief Sai do servidor atual.
 * 
 */
void System::leave_server()
{
    if(current_server == nullptr)
    {
        std::cout << "You are not in a server" << '\n';
        return;
    }
    current_server = nullptr;
    std::cout << "You left the server" << '\n';
}

//================================================================================

/**
 * @brief A função chamada para executar o sistema.
 * 
 */
void System::executable()
{
    std::string command;
    std::string file;
    while(true)
    {
        bool LOGGED = logged_user != -1;
        std::cin >> command;
        if(command == "quit")
        {
            std::cout << "Quitting Concordo" << '\n';
            return;
        }
        else if(command == "create-user" && !LOGGED)
        {
            std::string email, password, name;
            std::cin >> email >> password;
            std::getline(std::cin, name, '\n');
            create_user(email, password, name);
        }
        else if(command == "login")
        {
            std::string email, password;
            std::cin >> email >> password;
            login(email, password);
        }
            else if(command == "disconnect" && LOGGED) disconnect();

            else if(command == "create-server" && LOGGED)
            {
                std::string name;
                std::cin >> name;
                create_server(name);
            }

            else if(command == "set-server-desc" && LOGGED)
            {
                std::string name, description;
                std::cin >> name;
                std::getline(std::cin, description, '\n');
                change_server_description(name, description);
            }

            else if(command == "set-server-invite-code" && LOGGED)
            {
                std::string name, invite_code;
                std::cin >> name >> invite_code;
                set_server_invite_code(name, invite_code);
            }

            else if(command == "list-servers" && LOGGED) list_servers();

            else if(command == "remove-server" && LOGGED)
            {
                std::string name;
                std::cin >> name;
                remove_server(name);
            }
            else if(command == "join-server" && LOGGED)
            {
                std::string name, invite_code;
                std::cin >> name >> invite_code;
                join_server(name, invite_code);
            }
            else if(command == "enter-server" && LOGGED)
            {
                std::string name;
                std::cin >> name;
                enter_server(name);
            }
            else if(command == "leave-server" && LOGGED)
            {
                leave_server();
            }
            else std::cout << "Invalid command" << '\n';

    }
}