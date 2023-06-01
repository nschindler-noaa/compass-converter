#include "log.h"

#include <QMessageBox>
#include <QStringList>
#include <QByteArray>

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
//    string linestr = line.toStdString();
    cout << line.toUtf8().data() << endl;
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
//        string linestr = line.toStdString();
        cout << line.toUtf8().data() << endl;
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

void conMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s \n", localMsg.constData());//, file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}


void guiMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMessageBox mbox;
    QString title;
    QString text(msg);
    QByteArray localMsg = msg.toLocal8Bit();
    QString file = context.file ? QString(context.file) : QString();
    QString line = QString::number(context.line);
    QString function = context.function ? QString(context.function) : QString();
    QString details = QString("file: %1: %2, function: %3").arg(file, line, function);
    switch (type) {
    case QtDebugMsg:
        mbox.setIcon(QMessageBox::Information);
        mbox.setWindowTitle(QString("Debug Message"));
        text.prepend(QString("Debug: "));
        break;
    case QtInfoMsg:
        mbox.setIcon(QMessageBox::Information);
        mbox.setWindowTitle(QString("Information Message"));
        text.prepend(QString("Info: "));
        break;
    case QtWarningMsg:
        mbox.setIcon(QMessageBox::Warning);
        mbox.setWindowTitle(QString("Warning Message"));
        text.prepend(QString("Warning: "));
        break;
    case QtCriticalMsg:
        mbox.setIcon(QMessageBox::Critical);
        mbox.setWindowTitle(QString("Critical Message"));
        text.prepend(QString("Critical: "));
        break;
    case QtFatalMsg:
        mbox.setIcon(QMessageBox::Critical);
        mbox.setWindowTitle(QString("Fatal Message"));
        text.prepend(QString("Fatal: "));
        break;
    }
    mbox.setText(msg);
    mbox.setDetailedText(details);
    mbox.exec();
}

