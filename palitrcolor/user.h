#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    int id;
    QString login;
    QString password;
public:
    User(QString login, QString password);
    User(const User &other);

    QString getLogin() const;
    QString getPassword() const;

    int getID() const;
    void setID(int id);
};

#endif // USER_H
