#include <bits/stdc++.h>
#include "User.h"
#include "Channel.h"

#ifndef SERVER_H
#define SERVER_H

class Server
{
    protected:
        int owner_id;
        bool invite_code_enabled = false;
        std::string name;
        std::string description;
        std::string invite_code;
        std::vector<int> members;
        std::vector<Channel*> channels;
    public:
        Server(std::string name);
        void server_clear();
        int getOwner();
        std::string getName();
        std::string getDescription();
        std::string getInviteCode();
        std::vector<int> getMembers();
        std::vector<Channel*> getChannels();
        void setOwner(int id);
        void setDescription(std::string description);
        void setInviteCode(std::string invite_code);
        void removeInviteCode();
        void addMember(int id);
        void removeMember(int id);
        void listMembers();
};

#endif