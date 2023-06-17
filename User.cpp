#include <iostream>
#include <string>
#include "User.h"

User::User(int id, std::string name, std::string email, std::string password)
{
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

int User::getId() { return id; }

std::string User::getName() { return name; }

std::string User::getEmail() { return email; }

std::string User::getPassword() { return password; }

void User::updateName(std::string name) { this->name = name; }

void User::updateEmail(std::string email) { this->email = email; }

void User::updatePassword(std::string password) { this->password = password; }

bool User::operator==(const User &other)
{
    return (this->id == other.id);
}