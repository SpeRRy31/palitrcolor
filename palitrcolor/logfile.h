#ifndef LOGFILE_H
#define LOGFILE_H

#include <QString>

class LogFile
{
    QString filename;
public:
    LogFile(QString filename);
    LogFile();
    void logError(const QString& error);
};

#endif // LOGFILE_H
