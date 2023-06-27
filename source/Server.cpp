#include "Server.h"

Server::Server(std::string name)
{
    this->name = name;
}

void Server::server_clear()
{
    channels.clear();
    members.clear();
}

int Server::getOwner()
{
    return owner_id;
}

std::string Server::getName()
{
    return name;
}

std::string Server::getDescription()
{
    return description;
}

std::string Server::getInviteCode()
{
    return invite_code;
}

std::vector<int> Server::getMembers()
{
    return members;
}

std::vector<Channel *> Server::getChannels()
{
    return channels;
}

void Server::setOwner(int id)
{
    owner_id = id;
}

void Server::setDescription(std::string description)
{
    this->description = description;
}

void Server::setInviteCode(std::string invite_code)
{
    this->invite_code = invite_code;
    invite_code_enabled = true;
}

void Server::removeInviteCode()
{
    invite_code = "";
    invite_code_enabled = false;
}

void Server::addMember(int id)
{
    members.push_back(id);
}

void Server::removeMember(int id)
{
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i] == id)
        {
            members.erase(members.begin() + i);
            break;
        }
    }
}

void Server::listMembers()
{
    std::cout << name << " server users" << '\n';
    for (int i = 0; i < members.size(); i++)
    {
        std::cout << members[i] << '\n';
    }
}