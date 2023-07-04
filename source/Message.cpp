/**
 * @file Message.cpp
 * @brief Implementação da classe Message
 */

#include <iostream>
#include <string>
#include "Message.h"

/**
 * @brief Construtor de Message
 * 
 * @param sentAt 
 * @param sentBy 
 * @param content 
 */
Message::Message()
{
    this->sentAt = "";
    this->sentBy = 0;
    this->content = "";
}

Message::Message(std::string sentAt, int sentBy, std::string content)
{
    this->sentAt = sentAt;
    this->sentBy = sentBy;
    this->content = content;
}

/**
 * @brief Retorna a data de envio da mensagem
 * 
 * @return std::string 
 */
std::string Message::getSentAt() { return sentAt; }

/**
 * @brief Retorna o id de quem enviou a mensagem
 * 
 * @return int 
 */
int Message::getSentBy() { return sentBy; }

/**
 * @brief Retorna o conteúdo da mensagem
 * 
 * @return std::string 
 */
std::string Message::getContent() { return content; }

/**
 * @brief Sobrecarga do operador de comparação
 * 
 * @param sentAt 
 */
bool Message::operator==(const Message &other)
{
    return (this->sentAt == other.sentAt && this->sentBy == other.sentBy && this->content == other.content);
}

/**
 * @brief Sobrecarga do operador de atribuição
 * 
 * @param sentBy 
 */
Message Message::operator=(const Message &other)
{
    this->sentAt = other.sentAt;
    this->sentBy = other.sentBy;
    this->content = other.content;
    return *this;
}