#include "color.h"

Color::Color(QString name, QString code)
    : name(name), code(code) {}

QString Color::getName() const{
    return name;
}

QString Color::getCode() const{
    return code;
}

QString Color::colorToString() {
    return name + ": " + code;
}

void Color::setID(int id)
{
    this->id=id;
}
int Color::getID()const
{
    return id;;
}

void Color::setName(const QString& newName)
{
    name = newName;
}

void Color::setCode(const QString& newCode)
{
    code = newCode;
}

void Color::setFromColor(Color &other)
{
    this->code = other.code;
    this->name = other.name;
}

Color::Color(const Color& other)
    : id(other.id), name(other.name), code(other.code){}
