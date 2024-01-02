#ifndef PALITR_H
#define PALITR_H

#include <QString>
#include "color.h"
#include "user.h"

class Palitr
{
    int id;
    QString name;
    Color colors[4];
    User* user;
public:
    Palitr(QString name, Color colors[], User* user);

    Palitr(QString name, User* user);

    QString getName()const;
    Color getColor(int index);
    void putColor(int index, Color *color);
    User* getUser()const;

    void setID(int id);
    int getID() const;
};

#endif // PALITR_H
