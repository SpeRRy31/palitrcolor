#ifndef USER_H
#define USER_H

#include <QString>

class User
{
    QString login;
    QString password;
public:
    User(QString login, QString password);

    QString getLogin();
    QString getPassword();
};

#endif // USER_H
