/**
 * @file Server.cpp
 * @brief Implementação da classe Server
 * 
 */

#include "Server.h"
#include "Channel.h"
#include "VoiceChannel.h"
#include "TextChannel.h"

/**
 * @brief Construtor de Server
 * 
 * @param name nome do server
 */
Server::Server(std::string name)
{
    this->name = name;
}

/**
 * @brief Limpa o servidor de channels e members
 * 
 */
void Server::server_clear()
{
    text_channels.clear();
    voice_channels.clear();
    members.clear();
}

/**
 * @brief Retorna o id do dono do servidor
 * 
 * @return int
 */
int Server::getOwner()
{
    return owner_id;
}

/**
 * @brief Retorna o nome do servidor
 * 
 * @return std::string
 */
std::string Server::getName()
{
    return name;
}

/**
 * @brief Retorna a descrição do servidor
 * 
 * @return std::string
 */
std::string Server::getDescription()
{
    return description;
}

/**
 * @brief Retorna o código de convite do servidor
 * 
 * @return std::string
 */
std::string Server::getInviteCode()
{
    return invite_code;
}

/**
 * @brief Retorna os membros do servidor
 * 
 * @return std::vector<int>
 */
std::vector<int> Server::getMembers()
{
    return members;
}

/**
 * @brief Retorna voice channels do servidor
 * 
 * @return std::vector<VoiceChannel *>
 */
std::vector<Channel *> Server::getVoiceChannels()
{
    return voice_channels;
}

/**
 * @brief Retorna os text channels do servidor
 * 
 * @return std::vector<TextChannel *>
 */
std::vector<Channel *> Server::getTextChannels()
{
    return text_channels;
}

/**
 * @brief Retorna se o código de convite está habilitado
 * 
 * @return true 
 * @return false 
 */
bool Server::getInviteCodeEnabled()
{
    return invite_code_enabled;
}

/**
 * @brief Seta o id do dono do servidor
 * 
 * @param id 
 */
void Server::setOwner(int id)
{
    owner_id = id;
}

/**
 * @brief Seta a descrição do servidor
 * 
 * @param description 
 */
void Server::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Seta o código de convite do servidor
 * 
 * @param invite_code 
 */
void Server::setInviteCode(std::string invite_code)
{
    this->invite_code = invite_code;
    invite_code_enabled = true;
}

/**
 * @brief Remove o código de convite do servidor
 * 
 */
void Server::removeInviteCode()
{
    invite_code = "";
    invite_code_enabled = false;
}

/**
 * @brief Adiciona um membro ao servidor
 * 
 * @param id 
 */
void Server::addMember(int id)
{
    members.push_back(id);
}

/**
 * @brief Remove um membro do servidor
 * 
 * @param id 
 */
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

/**
 * @brief Lista os membros do servidor
 * 
 */
void Server::listMembers()
{
    std::cout << name << " server users" << '\n';
    for (int i = 0; i < members.size(); i++)
    {
        std::cout << members[i] << '\n';
    }
}

/**
 * @brief Verifica se um membro existe no servidor
 * 
 * @param id 
 * @return true 
 * @return false 
 */

bool Server::memberExists(int id)
{
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i] == id)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Adiciona um channel ao servidor
 * 
 * @param channel 
 */
void Server::create_channel(std::string name, std::string type)
{
    if(type == "text")
    {
        Channel* canal = new TextChannel(name);

        text_channels.push_back(canal);
    }
    else if(type == "voice")
    {
        Channel* canal = new VoiceChannel(name);
        voice_channels.push_back(canal);
    }
}

/**
 * @brief Lista os channels do servidor
 * 
 */
void Server::list_channels()
{
    std::cout << name << " server channels" << '\n';
    for (int i = 0; i < text_channels.size(); i++)
    {
        std::cout << text_channels[i]->getName() << " text channel" << '\n';
    }
    for (int i = 0; i < voice_channels.size(); i++)
    {
        std::cout << voice_channels[i]->getName() << " voice channel" << '\n';
    }
}

/**
 * @brief Verifica se um channel existe no servidor
 * 
 * @param name 
 * @return Channel* 
 */
Channel* Server::find_channel(std::string name)
{
    for (int i = 0; i < text_channels.size(); i++)
    {
        if (text_channels[i]->getName() == name)
        {
            return text_channels[i];
        }
    }
    for (int i = 0; i < voice_channels.size(); i++)
    {
        if (voice_channels[i]->getName() == name)
        {
            return voice_channels[i];
        }
    }
    return nullptr;
}