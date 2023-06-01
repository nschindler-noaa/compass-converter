#ifndef LOG_H
#define LOG_H

#include <QStringList>

enum Type {
    NORML,
    ERROR,
    FORCE,
    DEBUG,
    FATAL
};

class Log
{
public:
    Log();

public:
    static void logMessage(Type type, QString msg);

    void trackMessage(Type type, QString msg);

private:
    int count;
    Type lastType;
    QString lastMsg;
    QString line;

    static QString *createLine(Type type, QString msg);

};

void conMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
void guiMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // LOG_H
