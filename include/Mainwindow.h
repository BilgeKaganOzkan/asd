#pragma once

#include <stdio.h>
#include <memory>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "Configuration.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() {};

private:
    QMenuBar *menuBar;
    QMenu *configureMenu;
    Configuration *configuration;
};