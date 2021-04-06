#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settings = new RunSettings();

    connect (ui->actionExit, SIGNAL(triggered()), SLOT(exit()));
    connect (ui->actionHelp, SIGNAL(triggered()), SLOT(helpHelp()));
    connect (ui->actionAbout, SIGNAL(triggered()), SLOT(helpAbout()));

    connect (ui->comboBoxDebug, SIGNAL(currentTextChanged(QString)), this, SLOT(setDebug(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    close();
}

void MainWindow::helpHelp()
{

}

void MainWindow::helpAbout()
{

}

QString *MainWindow::chooseFile(QString name, QString filter)
{
    QString *file = new QString("");


    return file;
}

QString *MainWindow::chooseDir(QString name)
{
    QString *dir = new QString("");

    return dir;
}

void MainWindow::runConvert()
{

}

void MainWindow::setInputs(QString value)
{
    if (value.contains("ALL", Qt::CaseInsensitive)) {
        settings->setMod(ALL);
    }
    else if (value.contains("Spill", Qt::CaseInsensitive)) {
        settings->setMod(NOSPILL);
    }
}

void MainWindow::setDebug(QString value)
{
    if (value.contains("NONE", Qt::CaseInsensitive)) {
        settings->setDebug(NONE);
    }
    else if (value.contains("Temp", Qt::CaseInsensitive)) {
        settings->setDebug(TEMP);
    }
    else if (value.contains("Spill", Qt::CaseInsensitive)) {
        settings->setDebug(SPILL);
    }
    else if (value.contains("ALL", Qt::CaseInsensitive)) {
        settings->setDebug(ALL);
    }
}

void MainWindow::setTrans(QString value)
{
    if (value.contains("NONE", Qt::CaseInsensitive)) {
        settings->setTrans(NONE);
    }
    else if (value.contains("CONST", Qt::CaseInsensitive)) {
        settings->setTrans(CONST);
    }
    else if (value.contains("MAF", Qt::CaseInsensitive)) {
        settings->setTrans(MAF);
    }
    else if (value.contains("FLOW", Qt::CaseInsensitive)) {
        settings->setTrans(FLOW);
    }
    else if (value.contains("SPILL", Qt::CaseInsensitive)) {
        settings->setTrans(SPILL);
    }

}


