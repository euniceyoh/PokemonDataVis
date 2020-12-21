#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QComboBox>
#include <QChartView>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QPushButton>

#include <cctype>

#include "character.h"
#include "iorunner.h"
#include "stackedbar.h"

#include <QGridLayout>

// get user input to choose character
// get user input to choose sort
// get user input to search for information
// search by name
// search by HP
// search by Attack or Defense

class InputWindow : public QWidget
{
    Q_OBJECT
public:
    InputWindow(QWidget * parent = nullptr);
    iorunner io;

public slots:
    void characterSelected(int);
    void sortSelected(int);
    void searchByName();
    void searchByHPSelected(int);
    void searchByAttackSelected(int);
    void searchByDefenseSelected(int);

private:
    QLineEdit *minNameLineEdit;
    QLineEdit *maxNameLineEdit;
    QLineEdit *HPValueLineEdit;
    QLineEdit *AttackValueLineEdit;
    QLineEdit *DefenseValueLineEdit;



    vector<character> getCharData(iorunner io);
    void top(int, string);
    void bottom(int, string);
    void greater(int, string);
    void lesser(int, string);
};

#endif // INPUTWINDOW_H
