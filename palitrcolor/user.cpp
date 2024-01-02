#include "user.h"

User::User(QString login, QString password)
    : login(login), password(password) {}

QString User::getLogin() const{
    return login;
}

QString User::getPassword() const{
    return password;
}

int User::getID() const
{
    return id;
}

void User::setID(int id)
{
    this->id=id;
}
User::User(const User &other)
    : id(other.id), login(other.login), password(other.password) {}
