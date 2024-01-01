#include "logfile.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>

LogFile::LogFile(QString filename)
{
    this->filename = filename;
}

LogFile::LogFile()
{
    this->filename = "log.txt";
}

void LogFile::logError(const QString& error) {
    QFile logFile(filename);
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream stream(&logFile);
        stream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ") << error << "\n";
        logFile.close();
    }
}
