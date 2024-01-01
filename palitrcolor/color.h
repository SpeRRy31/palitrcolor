#ifndef COLOR_H
#define COLOR_H

#include <QString>

class Color
{
    int id;
    QString name;
    QString code;
public:
    Color() : name(""), code("") {}
    Color(const Color& other);
    Color(QString name, QString code);

    QString getName()const;
    QString getCode()const;


    void setName(const QString& newName);
    void setCode(const QString& newCode);
    void setFromColor(Color& other);

    QString colorToString();

    int getID()const;
    void setID(int id);
};

#endif // COLOR_H
