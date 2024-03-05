#pragma once

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include "CanTab.h"

class Configuration : public QDialog
{
    Q_OBJECT

public:
    Configuration(QWidget *parent = nullptr);
    virtual ~Configuration() {};
private:
    QVBoxLayout *mainLayout;
    QTabWidget *mainTabWidget;
    QPushButton *saveButton;
    CanTab *canTab;

    void onSaveButtonClicked();
};