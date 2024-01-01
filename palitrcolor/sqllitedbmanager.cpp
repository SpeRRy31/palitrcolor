#include "sqllitedbmanager.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDate>
#include <QDebug>


SqliteDBManager* SqliteDBManager::instance = nullptr;

SqliteDBManager::SqliteDBManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOST_NAME);
    db.setDatabaseName(DATABASE_FILE_NAME);
}

// Метод для отримання екземпляру даного класу (патерн Singleton)
SqliteDBManager* SqliteDBManager::getInstance() {
    if (instance == nullptr) {
        instance = new SqliteDBManager();
    }
    return instance;
}

// Метод для підключення до бази даних
void SqliteDBManager::connectToDataBase() {
    /* Перед підключенням до бази даних виконуємо перевірку на її існування.
     * В залежності від результату виконуємо відкриття бази даних або її відновлення
     * */
    try {
        if (QFile(DATABASE_FILE_NAME).exists()) {
            this->openDataBase();
        } else {
            this->restoreDataBase();
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
    }

}

// Метод для отримання обробника підключення до БД
QSqlDatabase SqliteDBManager::getDB() {
    return db;
}

// Метод відновлення бази даних
bool SqliteDBManager::restoreDataBase() {
    try {
        if (this->openDataBase()) {
            if (!this->createTables()) {
                return false;
            } else {
                return true;
            }
        } else {
            qDebug() << "Не вдалось відновити базу даних";
            return false;
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}

// Метод для відкриття бази даних
bool SqliteDBManager::openDataBase() {
    /* База даних відкривається по вказаному шляху
     * та імені бази даних, якщо вона існує
     * */
    try {
        if (db.open()) {
            return true;
        } else
            return false;
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}

// Метод закриття бази даних
void SqliteDBManager::closeDataBase() {
    db.close();
}

// Метод для створення таблиці в базі даних
bool SqliteDBManager::createTables() {
    QSqlQuery query;

    try {
        // Таблиця Users
        if (!query.exec("CREATE TABLE " TABLE_USER " ("
                        TABLE_USER_ID       " INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TABLE_USER_LOGIN    " VARCHAR(255) NOT NULL, "
                        TABLE_USER_PASSWORD " VARCHAR(255) NOT NULL"
                        " )"
                        )) {
            qDebug() << "DataBase: error of create " << TABLE_USER;
            qDebug() << query.lastError().text();
            return false;
        }

        // Таблиця Colors
        if (!query.exec("CREATE TABLE " TABLE_COLOR " ("
                        TABLE_COLOR_ID   " INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TABLE_COLOR_NAME " VARCHAR(255) NOT NULL, "
                        TABLE_COLOR_CODE " VARCHAR(255) NOT NULL"
                        " )"
                        )) {
            qDebug() << "DataBase: error of create " << TABLE_COLOR;
            qDebug() << query.lastError().text();
            return false;
        }

        // Таблиця Palitrs
        if (!query.exec("CREATE TABLE " TABLE_PALITR " ("
                        TABLE_PALITR_ID      " INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TABLE_PALITR_NAME    " VARCHAR(255) NOT NULL, "
                        TABLE_PALITR_USER_ID " INTEGER, "
                        "FOREIGN KEY(" TABLE_PALITR_USER_ID ") REFERENCES " TABLE_USER "(" TABLE_USER_ID ")"
                        " )"
                        )) {
            qDebug() << "DataBase: error of create " << TABLE_PALITR;
            qDebug() << query.lastError().text();
            return false;
        }

        // Таблиця PalitrColors
        if (!query.exec("CREATE TABLE " TABLE_PALITR_COLOR " ("
                        TABLE_PALITR_COLOR_ID    " INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TABLE_PALITR_COLOR_PALITR_ID " INTEGER, "
                        TABLE_PALITR_COLOR_COLOR_ID  " INTEGER, "
                        "FOREIGN KEY(" TABLE_PALITR_COLOR_PALITR_ID ") REFERENCES " TABLE_PALITR "(" TABLE_PALITR_ID "), "
                        "FOREIGN KEY(" TABLE_PALITR_COLOR_COLOR_ID ") REFERENCES " TABLE_COLOR "(" TABLE_COLOR_ID ")"
                        " )"
                        )) {
            qDebug() << "DataBase: error of create " << TABLE_PALITR_COLOR;
            qDebug() << query.lastError().text();
            return false;
        }

        return true;

    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}

// Метод для вставки записів у таблицю Users
bool SqliteDBManager::inserIntoTable(const User& user) {
    QSqlQuery query;

    try {
        query.prepare("INSERT INTO " TABLE_USER " ( "
                      TABLE_USER_LOGIN     ", "
                      TABLE_USER_PASSWORD " ) "
                      "VALUES (:login, :password )");
        query.bindValue(":login", user.getLogin());
        query.bindValue(":password", user.getPassword());

        if (!query.exec()) {
            qDebug() << "Error insert into " << TABLE_USER;
            qDebug() << query.lastError().text();
            qDebug() << query.lastQuery();
            return false;
        } else {
            return true;
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}
// Метод для вставки записів у таблицю Colors
bool SqliteDBManager::inserIntoTable(const Color& color) {
    QSqlQuery query;

    try {
        query.prepare("INSERT INTO " TABLE_COLOR " ( "
                      TABLE_COLOR_NAME     ", "
                      TABLE_COLOR_CODE " ) "
                      "VALUES (:name, :code )");
        query.bindValue(":name", color.getName());
        query.bindValue(":code", color.getCode());

        if (!query.exec()) {
            qDebug() << "Error insert into " << TABLE_COLOR;
            qDebug() << query.lastError().text();
            qDebug() << query.lastQuery();
            return false;
        } else {
            return true;
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}
// Метод для вставки записів у таблицю Palitrs
bool SqliteDBManager::inserIntoTable(const Palitr& palette) {
    QSqlQuery query;

    try {
        query.prepare("INSERT INTO " TABLE_PALITR " ( "
                      TABLE_PALITR_NAME     ", "
                      TABLE_PALITR_USER_ID " ) "
                      "VALUES (:name, :user_id )");
        query.bindValue(":name", palette.getName());
        query.bindValue(":user_id", palette.getUser()->getID());

        if (!query.exec()) {
            qDebug() << "Error insert into " << TABLE_PALITR;
            qDebug() << query.lastError().text();
            qDebug() << query.lastQuery();
            return false;
        } else {
            return true;
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}

bool SqliteDBManager::insertIntoTable(const PalitrColor& palitrColor) {
    QSqlQuery query;

    try {
        query.prepare("INSERT INTO " TABLE_PALITR_COLOR " ( "
                      TABLE_PALITR_COLOR_PALITR_ID ", "
                      TABLE_PALITR_COLOR_COLOR_ID " ) "
                      "VALUES (:palitr_id, :color_id )");
        query.bindValue(":palitr_id", palitrColor.getPalitrId());
        query.bindValue(":color_id", palitrColor.getColorId());

        if (!query.exec()) {
            qDebug() << "Error insert into " << TABLE_PALITR_COLOR;
            qDebug() << query.lastError().text();
            qDebug() << query.lastQuery();
            return false;
        } else {
            return true;
        }
    } catch (const std::exception& e) {
        l.logError(e.what());
        return false;
    }
}

