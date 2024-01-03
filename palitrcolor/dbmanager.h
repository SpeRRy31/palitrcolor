#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "user.h"
#include "color.h"
#include "palitr.h"
#include "palitrcolor.h"
#include <QSqlDatabase>
#include <QVector>

// Абстрактний клас (інтерфейс) для роботи з базою даних
class DBManager {
public:
    virtual void connectToDataBase() = 0;

    virtual QSqlDatabase getDB() = 0;

    virtual bool inserIntoTable(const User& user) = 0;
    virtual bool inserIntoTable(const Color& color) = 0;
    virtual bool inserIntoTable(const Palitr& palette) = 0;
    virtual bool insertIntoTable(const PalitrColor& palitrcolor) = 0;

    virtual bool userExists(const QString& login) = 0;
    virtual User* getUser(const QString& login) = 0;

    virtual QVariant getLastInsertId() = 0;

    virtual User* getUserById(int userId) = 0;
    virtual Color* getColorById(int colorId) = 0;
    virtual QVector<int> getColorIdsByPalitrId(int palitrId) = 0;



};

#endif // DBMANAGER_H
