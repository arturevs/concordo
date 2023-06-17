#include <iostream>
#include <string>

class User
{
private:
    int id;
    std::string name;
    std::string email;
    std::string password;

public:
    User(int id, std::string name, std::string email, std::string password);
    int getId();
    std::string getName();
    std::string getEmail();
    std::string getPassword();
    void updateName(std::string name);
    void updateEmail(std::string email);
    void updatePassword(std::string password);
    bool operator==(const User &other);
};