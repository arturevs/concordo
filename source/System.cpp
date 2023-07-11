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
    return update_server;
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
            std::cout << "User id: " << logged_user << '\n';
            return;
        }
    }
    std::cout << "User not found" << '\n';
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
            if(servers[i] == current_server)
            {
                servers.erase(servers.begin() + i);
                current_server = Server();
                update_server = nullptr;
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
            else if(servers[i].memberExists(logged_user) == true)
            {
                std::cout << "You are already a member of this server" << '\n';
                return;
            }
            else
            {
                servers[i].addMember(logged_user);
                std::cout << "You joined the server " << name << " successfully" << '\n';
                return;
            }

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
            else if(current_server == servers[i])
            {
                std::cout << "You are already in this server" << '\n';
                return;
            }
            else
            {
                update_server = &servers[i];
                current_server = servers[i];
                std::cout << "Server " << name << " selected successfully" << '\n';
                return;
            }
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
    if(current_server == Server())
    {
        std::cout << "You are not in a server" << '\n';
        return;
    }
    current_server = Server();
    std::cout << "You left the server" << '\n';
}

/**
 * @brief entra em um canal do servidor atual
 * 
 */
void System::enter_channel(std::string name)
{
    if(!(update_server->find_channel(name)))
    {
        std::cout << "Channel not found" << '\n';
        return;
    }
    else
    {
        for(int i = 0; i < update_server->getTextChannels().size(); i++)
        {
            if(update_server->getTextChannels()[i].getName() == name)
            {
                current_channel = &update_server->getTextChannels()[i];
                std::cout << "Channel " << name << " selected successfully" << '\n';
                return;
            }
        }
        for(int i = 0; i < update_server->getVoiceChannels().size(); i++)
        {
            if(update_server->getVoiceChannels()[i].getName() == name)
            {
                current_channel = &update_server->getVoiceChannels()[i];
                std::cout << "Channel " << name << " selected successfully" << '\n';
                return;
            }
        }
    }
}

/**
 * @brief Envia uma mensagem para o canal atual.
 * 
 */
void System::send_message()
{
    std::string message;
    std::getline(std::cin, message, '\n');
    current_channel->send_message(message, logged_user);
}

/**
 * @brief Salva os usuários do sistema
 * 
 */
void System::salvarUsuarios()
{
    std::ofstream file;
    file.open("usuarios.txt");
    file << users.size() << '\n';
    for(int i = 0; i < users.size(); i++)
    {
        file << users[i].getId()<< '\n';
        file << users[i].getName() << '\n';
        file << users[i].getEmail() << '\n';
        file << users[i].getPassword() << '\n';
    }
    file.close();
}

/**
 * @brief Salva os servidores do sistema
 * 
 */
void System::salvarServidores()
{
    std::ofstream file;
    file.open("servidores.txt");
    for(int i = 0; i < servers.size(); i++)
    {
        file << servers.size() << '\n';
        file << servers[i].getOwner() << '\n';
        file << servers[i].getName() << '\n';
        file << servers[i].getDescription() << '\n';
        file << servers[i].getInviteCode() << '\n';
        file << servers[i].getMembers().size() << '\n';
        for(int j = 0; j < servers[i].getMembers().size(); j++)
        {
            file << servers[i].getMembers()[j] << '\n';
        }
        file << servers[i].getVoiceChannels().size() + servers[i].getTextChannels().size() << '\n';
        for(int j = 0; j < servers[i].getVoiceChannels().size(); j++)
        {
            file << ((servers[i].getVoiceChannels())[j]).getName() << '\n';
            file << "VOZ" << '\n';
            file << 1 << '\n';
            file << servers[i].getVoiceChannels()[i].getLastMessage().getSentBy() << '\n';
            file << servers[i].getVoiceChannels()[i].getLastMessage().getSentAt() << '\n';
            file << servers[i].getVoiceChannels()[i].getLastMessage().getContent() << '\n';
        }
        for(int j = 0; j < servers[i].getTextChannels().size(); j++)
        {
            file << ((servers[i].getTextChannels())[j]).getName() << '\n';
            file << "TEXTO" << '\n';
            file << servers[i].getTextChannels()[i].getMessages().size() << '\n';
            for(int k = 0; k < servers[i].getTextChannels()[i].getMessages().size(); k++)
            {
                file << servers[i].getTextChannels()[i].getMessages()[k].getSentBy() << '\n';
                file << servers[i].getTextChannels()[i].getMessages()[k].getSentAt() << '\n';
                file << servers[i].getTextChannels()[i].getMessages()[k].getContent() << '\n';
            }
        }
    }
    file.close();
}

/**
 * @brief Salva os dados do sistema
 * 
 */
void System::salvar()
{
    salvarUsuarios();
    salvarServidores();
}

/**
 * @brief Carrega os usuários do sistema
 * 
 */
void System::carregarUsuarios()
{
    std::ifstream file;
    file.open("usuarios.txt");
    int size;
    file >> size;
    file.ignore();
    for(int i = 0; i < size; i++)
    {
        int id;
        std::string name, email, password;
        file >> id;
        file.ignore();
        std::getline(file, name);
        file >> email;
        file.ignore();
        file >> password;
        file.ignore();
        User user(id, name, email, password);
        users.push_back(user);
        l_id_assigned = id;
    }
    file.close();
}

/**
 * @brief Carrega os servidores do sistema
 * 
 */
void System::carregarServidores()
{
    std::ifstream file;
    file.open("servidores.txt");
    int size;
    file >> size;
    file.ignore();
    for(int i = 0; i < size; i++)
    {
        int owner;
        std::string name, description, invite_code;
        file >> owner;
        file.ignore();
        file >> name;
        file.ignore();
        std::getline(file, description);
        file >> invite_code;
        file.ignore();
        Server server(owner, name, description, invite_code);
        int size_members;
        file >> size_members;
        file.ignore();
        for(int j = 0; j < size_members; j++)
        {
            int member;
            file >> member;
            file.ignore();
            server.addMember(member);
        }
        int size_channels;
        file >> size_channels;
        file.ignore();
        for(int j = 0; j < size_channels; j++)
        {
            std::string name, type;
            file >> name;
            file.ignore();
            file >> type;
            file.ignore();
            if(type == "VOZ")
            {
                VoiceChannel* voice_channel = new VoiceChannel(name);
                int size_messages;
                file >> size_messages;
                file.ignore();
                for(int k = 0; k < size_messages; k++)
                {
                    int sent_by;
                    std::string sent_at, content;
                    file >> sent_by;
                    file.ignore();
                    file >> sent_at;
                    file.ignore();
                    std::getline(file, content, '\n');
                    Message message(sent_at, sent_by, content);
                    voice_channel->add_message(message);
                }
                server.add_VoiceChannel(*voice_channel);
            }
            else if(type == "TEXTO")
            {
                TextChannel* text_channel = new TextChannel(name);
                int size_messages;
                file >> size_messages;
                file.ignore();
                for(int k = 0; k < size_messages; k++)
                {
                    int sent_by;
                    std::string sent_at, content;
                    file >> sent_by;
                    file.ignore();
                    file >> sent_at;
                    file.ignore();
                    std::getline(file, content);
                    Message message(sent_at, sent_by, content);
                    text_channel->add_message(message);
                }
                server.add_TextChannel(*text_channel);
            }
        }
        servers.push_back(server);
    }
    file.close();
}

/**
 * @brief Carrega os dados salvos em arquivos de texto.
 * 
 */
void System::carregar()
{
    carregarUsuarios();
    carregarServidores();
}

//=============================================================================================

/**
 * @brief A função chamada para executar o sistema.
 * 
 */
void System::executable()
{
    carregar();
    std::string command;
    std::string file;   
    while(true)
    {
        bool LOGGED = logged_user != -1;
        std::cin >> command;
        if(command == "quit")
        {
            std::cout << "Quitting Concordo" << '\n';
            salvar();
            return;
        }
        else if(command == "create-user" && !LOGGED)
        {
            std::string email, password, name;
            std::cin >> email >> password;
            std::getline(std::cin, name, '\n');
            create_user(email, password, name);
            std::cout << users.size() << '\n';
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
            else if(command == "list-channels" && LOGGED && !(current_server == Server()))
            {
                current_server.list_channels();
            }
            else if(command == "create-channel" && LOGGED && !(current_server == Server()))
            {
                std::string name, type;
                std::cin >> name >> type;
                update_server->create_channel(name, type);
                std::cout << "Channel created successfully" << '\n';
            }
            else if(command == "leave-channel" && LOGGED && !(current_server == Server()) && current_channel != nullptr)
            {
                current_channel = nullptr;
                std::cout << "left the channel succsessfully" << '\n';
            }
            else if(command == "enter-channel" && LOGGED && !(current_server == Server()))
            {
                //using enter_channel
                std::string name;
                std::cin >> name;
                enter_channel(name);
            }
            else if(command == "send-message" && LOGGED && !(current_server == Server()) && current_channel != nullptr)
            {
                send_message();
            }
            else if(command == "list-messages" && LOGGED && !(current_server == Server()) && current_channel != nullptr)
            {
                current_channel->list_messages();
            }
            else std::cout << "Invalid command" << '\n';

    }
}