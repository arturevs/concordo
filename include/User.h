/**
 * @file User.h
 * @brief Definição da classe User
 */

#include <iostream>
#include <string>
#ifndef USER_H
#define USER_H

/**
 * @brief Classe que representa um usuário.
 * 
 */
class User
{
private:
    int id; //!< Variável que guarda o id do usuário.
    std::string name; //!< Variável que guarda o nome do usuário.
    std::string email; //!< Variável que guarda o email do usuário.
    std::string password; //!< Variável que guarda a senha do usuário.

public:
    User(std::string name, std::string email, std::string password); //!< Construtor da classe User.
    User(int id, std::string name, std::string email, std::string password); //!< Construtor da classe User.
    int getId(); //!< Método que retorna o id do usuário.
    void setId(int id); //!< Método que altera o id do usuário.
    std::string getName(); //!< Método que retorna o nome do usuário.
    std::string getEmail(); //!< Método que retorna o email do usuário.
    std::string getPassword(); //!< Método que retorna a senha do usuário.
    void updateName(std::string name); //!< Método que altera o nome do usuário.
    void updateEmail(std::string email); //!< Método que altera o email do usuário.
    void updatePassword(std::string password); //!< Método que altera a senha do usuário.
    bool operator==(const User &other); //!< Sobrecarga do operador de igualdade.
};

#endif