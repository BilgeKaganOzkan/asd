#include "Configuration.h"

Configuration::Configuration(QWidget *parent)
    : QDialog(parent)
{
    mainLayout = new QVBoxLayout(this);

    mainTabWidget = new QTabWidget();
    mainLayout->addWidget(mainTabWidget);

    canTab = new CanTab();
    mainTabWidget->addTab(canTab, "Can");

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    saveButton = new QPushButton("Save");
    saveButton->setFixedSize(70, 30);
    buttonLayout->addWidget(saveButton);
    mainLayout->addLayout(buttonLayout);

    connect(saveButton, &QPushButton::clicked, this, &Configuration::onSaveButtonClicked);

    setLayout(mainLayout);
    setWindowTitle("Configuration");
    setFixedSize(800, 600);
}

void Configuration::onSaveButtonClicked()
{
    accept();
}