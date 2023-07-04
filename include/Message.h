/**
 * @file Message.h
 * @brief Definição da classe Message
 */

#include <iostream>
#include <string>
/**
 * @brief Classe que representa uma mensagem.
 * 
 */
class Message
{
private:
    std::string sentAt; //<! Variável que guarda o horário de envio da mensagem.
    int sentBy;        //<! Variável que guarda o id do usuário que enviou a mensagem.
    std::string content; //<! Variável que guarda o conteúdo da mensagem.

public:
    Message();
    Message(std::string sentAt, int sentBy, std::string content); //<! Construtor da classe Message.
    std::string getSentAt(); //<! Método que retorna o horário de envio da mensagem.
    int getSentBy();       //<! Método que retorna o id do usuário que enviou a mensagem.
    std::string getContent(); //<! Método que retorna o conteúdo da mensagem.
    bool operator==(const Message &other); //<! Sobrecarga do operador de comparação.
    Message operator=(const Message &other); //<! Sobrecarga do operador de atribuição.
};