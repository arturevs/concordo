/**
 * @file User.cpp
 * @brief Implementação da classe User

 * 
 */

#include <iostream>
#include <string>
#include "User.h"

/**
 * @brief Construtor de User
 * 
 * @param name 
 * @param email 
 * @param password 
 */
User::User(std::string name, std::string email, std::string password)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}
User::User(int id, std::string name, std::string email, std::string password)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

/**
 * @brief Retorna o id do usuário
 * 
 * @return int 
 */
int User::getId() { return id; }

/**
 * @brief Seta o id do usuário
 * 
 * @param id 
 */
void User::setId(int id) { this->id = id; }

/**
 * @brief Retorna o nome do usuário
 * 
 * @return std::string 
 */
std::string User::getName() { return name; }

/**
 * @brief Retorna o email do usuário
 * 
 * @return std::string 
 */
std::string User::getEmail() { return email; }

/**
 * @brief Retorna a senha do usuário
 * 
 * @return std::string 
 */
std::string User::getPassword() { return password; }

/**
 * @brief Atualiza o nome do usuário
 * 
 * @param name 
 */
void User::updateName(std::string name) { this->name = name; }

/**
 * @brief Atualiza o email do usuário
 * 
 * @param email 
 */
void User::updateEmail(std::string email) { this->email = email; }

/**
 * @brief Atualiza a senha do usuário
 * 
 * @param password 
 */
void User::updatePassword(std::string password) { this->password = password; }

/**
 * @brief Sobrecarga do operador de comparação
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool User::operator==(const User &other)
{
    return (this->id == other.id);
}