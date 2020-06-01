#include "log.h"

#include <iostream>
using namespace std;


Log::Log()
{
    count = 0;
    lastType = NORML;
    lastMsg = QString(" ");
}

void Log::logMessage(Type type, QString msg)
{
    QString line = *createLine(type, msg);
    string linestr = line.toStdString();// toUtf8().data();
    cout << linestr.data() << endl;
}

void Log::trackMessage(Type type, QString msg)
{
    if (type == lastType && msg == lastMsg) {
        count ++;
    }
    else {
        lastMsg = msg;
        lastType = type;
        if (count > 0) {
            cout << " . . . last line repeated " << count << " times.";
        }
        line = *createLine(type, msg);
        string linestr = line.toStdString();
        cout << linestr.data() << endl;
    }
}

QString *Log::createLine(Type type, QString msg)
{
    QString *ln = new QString();
    switch (type) {
    case NORML:
        ln->append("");
        break;
    case ERROR:
        ln->append("ERROR: ");
        break;
    case FORCE:
        ln->append("!! ");
        break;
    case DEBUG:
        ln->append("DEBUG: ");
        break;
    case FATAL:
        ln->append("FATAL ERROR: ");
        break;
    }
    ln->append(msg);
    return ln;
}
