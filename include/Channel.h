/**
 * @file Channel.h
 * @brief Definição da classe Channel
 * 
 */

#include <iostream>
#include <string>
#ifndef CHANNEL_H
#define CHANNEL_H

/**
 * @brief Classe que representa um canal.
 * 
 */
class Channel
{
protected:
    std::string name; //!< Variável que guarda o nome do canal.
public:
    Channel(std::string name); //!< Construtor da classe Channel.
    std::string getName(); //!< Método que retorna o nome do canal.
};

#endif