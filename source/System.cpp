#include <bits/stdc++.h>
#include "System.h"

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

int System::increase_l_id()
{
    return l_id_assigned++;
}

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
}

void System::login(std::string email, std::string password)
{
    if(logged_user != -1)
    {
        std::cout << "Usuário já logado" << '\n';
        return;
    }
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getEmail() == email && users[i].getPassword() == password)
        {
            logged_user = users[i].getId();
            std::cout << "Usuário logado com sucesso" << '\n';
            return;
        }
    }
    std::cout << "Usuário não encontrado" << '\n';
}

void System::disconnect()
{   
    std::cout << "User " << logged_user_name() << " disconnected sucsessfully" << '\n';
    logged_user = -1;
}

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
}

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

void System::list_servers()
{
    std::cout << "=== Servers ===" << '\n';
    for(int i = 0; i < servers.size(); i++)
    {
        std::cout << servers[i].getName() << '\n';
    }
}

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
            servers[i].server_clear();
            servers.erase(servers.begin() + i);
            std::cout << "Server removed successfully" << '\n';
            return;
        }
        i++;
    }
    std::cout << "Server not found" << '\n';    
}


//================================================================================

void System::executable()
{
    std::string command;
    while(true)
    {
        bool LOGGED = logged_user != -1;
        std::cin >> command;
        if(command == "quit")
        {
            std::cout << "Saindo do Concordo" << '\n';
        }
        else if(command == "create-user")
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
        if(LOGGED)
        {
            if(command == "disconnect") disconnect();

            else if(command == "create-server")
            {
                std::string name;
                std::cin >> name;
                create_server(name);
            }

            else if(command == "set-server-desc")
            {
                std::string name, description;
                std::cin >> name;
                std::getline(std::cin, description, '\n');
                change_server_description(name, description);
            }

            else if(command == "set-server-invite-code")
            {
                std::string name, invite_code;
                std::cin >> name >> invite_code;
                set_server_invite_code(name, invite_code);
            }

            else if(command == "list-servers") list_servers();

            else if(command == "remove-server")
            {
                std::string name;
                std::cin >> name;
                remove_server(name);
            }

            
        }
    }
}