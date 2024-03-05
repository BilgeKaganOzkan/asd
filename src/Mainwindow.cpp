#include "Mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    configuration = new Configuration(this);
    
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    configureMenu = menuBar->addMenu(tr("&Configure"));

    QAction *configureAction = new QAction(tr("&Configure"), this);
    configureMenu->addAction(configureAction);

    connect(configureAction, &QAction::triggered, configuration, &Configuration::show);

    QAction *saveAction = new QAction(tr("&Settings"), this);
    configureMenu->addAction(saveAction);
}
