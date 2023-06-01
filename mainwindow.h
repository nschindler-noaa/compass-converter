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

    void changeInputFile();
    void changeInputDir();
    void changeRuleName();
    void changeScenarioName();
    void changeDailyValues(bool checked);
    void changeRuleFileName();
    void changeDataFileName();
    void changeDataDir();
    void changeDataInput();

    void changeOutputDir();
    void changeFishTransport(int value);
    void changeDebugOutput(int value);

    void changeCompassExe();
    void changeTempExe();

    void startRun();
    void cancelRun();

    void runConvert();

    void setDebug(QString value);
    void setTrans(QString value);
    void setInputs(QString value);

private:
    Ui::MainWindow *ui;

    RunSettings *settings;
};

#endif // MAINWINDOW_H
