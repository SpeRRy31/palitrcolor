#ifndef SQLITEDBMANAGER_H
#define SQLITEDBMANAGER_H

#include <QSqlDatabase>
#include "dbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QVector>


#include <logfile.h>


#define DATABASE_HOST_NAME   "ExampleDataBase"
#define DATABASE_FILE_NAME   "DataBase.sqlite"

#define TABLE_USER       "Users"
#define TABLE_USER_ID   "id"
#define TABLE_USER_LOGIN  "login"
#define TABLE_USER_PASSWORD  "password"

#define TABLE_COLOR       "Colors"
#define TABLE_COLOR_ID   "id"
#define TABLE_COLOR_NAME  "name"
#define TABLE_COLOR_CODE  "code"

#define TABLE_PALITR         "Palitrs"
#define TABLE_PALITR_ID      "id"
#define TABLE_PALITR_NAME    "name"
#define TABLE_PALITR_USER_ID "user_id"

#define TABLE_PALITR_COLOR   "PalitrColors"
#define TABLE_PALITR_COLOR_ID    "id"
#define TABLE_PALITR_COLOR_PALITR_ID "palitr_id"
#define TABLE_PALITR_COLOR_COLOR_ID  "color_id"

class SqliteDBManager : public DBManager {

public:

    static SqliteDBManager* getInstance();


    void connectToDataBase() override;


    QSqlDatabase getDB() override;


    bool inserIntoTable(const User& user) override;
    bool inserIntoTable(const Color& color) override;
    bool inserIntoTable(const Palitr& palette) override;
    bool insertIntoTable(const PalitrColor& palitrcolor) override;

    User* getUser(const QString& login) override;
    bool userExists(const QString& login) override;

    QVariant getLastInsertId() override;

    virtual User* getUserById(int userId) override;
    virtual Color* getColorById(int colorId) override;
    virtual QVector<int> getColorIdsByPalitrId(int palitrId) override;


private:

    QSqlDatabase db;

    static SqliteDBManager* instance;

    SqliteDBManager();


    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTables();

    LogFile l;

};

#endif // SQLITEDBMANAGER_H
