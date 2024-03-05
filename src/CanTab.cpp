#include "CanTab.h"

CanTab::CanTab(QWidget *parent)
    : QWidget(parent)
{
    canMainLayout = new QHBoxLayout();
    canPortGroupLayout = new QHBoxLayout*[canComboBoxCount];
    canPortLayout = new QVBoxLayout();

    canComboBoxCount = 0;

    canCheckBox = new QCheckBox("Can");
    canCheckBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    canMainLayout->addWidget(canCheckBox);

    canSpinBox = new QSpinBox();
    canSpinBox->setMinimum(1);
    canSpinBox->setMaximum(6);
    canSpinBox->setEnabled(false);
    canSpinBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    canMainLayout->addWidget(canSpinBox);

    canPortGroupLayout[0] = new QHBoxLayout();
    QLabel* label = new QLabel(QString("Can Port %1").arg(1));
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QComboBox* comboBox = new QComboBox();
    comboBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    canPortGroupLayout[0]->addWidget(label);
    canPortGroupLayout[0]->addWidget(comboBox);
    canPortLayout->addLayout(canPortGroupLayout[0]);

    canMainLayout->addLayout(canPortLayout);
    connect(canCheckBox, &QCheckBox::stateChanged, this, &CanTab::canCheckBoxStateChanged);
    connect(canSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &CanTab::canSpinBoxValueChanged);

    setLayout(canMainLayout);
}

void CanTab::canCheckBoxStateChanged(int state) {
    if (state == Qt::Checked) 
    {
        canSpinBox->setEnabled(true);
        canComboBoxCount = canSpinBox->value();
        for (int i = 0; i < canComboBoxCount; ++i)
        {
            canPortGroupLayout[i]->setEnabled(true);
        }
    } 
    else 
    {
        canSpinBox->setEnabled(false);
        for (int i = 0; i < canComboBoxCount; ++i)
        {
            canPortGroupLayout[i]->setEnabled(false);
        }
    }
}

void CanTab::canSpinBoxValueChanged(int newValue) {
    if(newValue > canComboBoxCount) 
    {
        for (int i = canComboBoxCount; i < newValue; ++i) 
        {
            canPortGroupLayout[i] = new QHBoxLayout();
            QLabel* label = new QLabel(QString("Can Port %1").arg(i+1));
            label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            QComboBox* comboBox = new QComboBox();
            comboBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            canPortGroupLayout[i]->addWidget(label);
            canPortGroupLayout[i]->addWidget(comboBox);
            canPortLayout->addLayout(canPortGroupLayout[i]);
        }
    }
    else if(newValue < canComboBoxCount)
    {
        for (int i = canComboBoxCount - 1; i >= newValue; --i) 
        {
            if(i != 0)
            {
                while (QLayoutItem *item = canPortGroupLayout[i]->takeAt(0)) 
                {
                    if (QWidget *widget = item->widget()) 
                    {
                        delete widget;
                    }
                    delete item;
                }
                canPortLayout->takeAt(-1);
            }
        }
    }
    canComboBoxCount = canSpinBox->value();
}