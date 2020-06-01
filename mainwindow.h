#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QFile>
#include <QFileInfo>
#include <QDir>

#include "runsettings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void exit();
    void helpHelp();
    void helpAbout();

    QString *chooseFile(QString name, QString filter);
    QString *chooseDir(QString name);

    void runConvert();

    void setDebug(QString value);
    void setTrans(QString value);
    void setInputs(QString value);

private:
    Ui::MainWindow *ui;

    RunSettings *settings;
};

#endif // MAINWINDOW_H
