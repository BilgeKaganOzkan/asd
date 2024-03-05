#pragma once

#include <QCheckBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QWidget>

class CanTab : public QWidget
{
    Q_OBJECT

public:
    CanTab(QWidget *parent = nullptr);
    virtual ~CanTab() {};
private:
    QHBoxLayout *canMainLayout;
    QVBoxLayout *canPortLayout;
    QHBoxLayout **canPortGroupLayout;
    QCheckBox *canCheckBox;
    QSpinBox *canSpinBox;

    int canComboBoxCount = 6;

    void canCheckBoxStateChanged(int state);
    void canSpinBoxValueChanged(int newValue);
};