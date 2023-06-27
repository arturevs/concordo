#include <bits/stdc++.h>
#include "User.h"
#include "Channel.h"
#include "Server.h"

#ifndef SYSTEM_H
#define SYSTEM_H

class System
{
    private:
        int l_id_assigned = 1;
        int logged_user = 0;
        std::vector<User> users;
        std::vector<Server> servers;
        Server* current_server;
        Channel* current_channel;
    public:
        std::string logged_user_name();
        std::string logged_email();
        int increase_l_id();
        void executable();
        void create_user(std::string email, std::string password, std::string name);
        void login(std::string email, std::string password);
        // here begins the logged in methods
        void disconnect();
        void create_server(std::string name);
        void change_server_description(std::string name, std::string description);
        void set_server_invite_code(std::string name, std::string invite_code);
        void list_servers();
        void remove_server(std::string name);
};

#endif

