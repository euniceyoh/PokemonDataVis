#include "inputwindow.h"

#include <iostream>




InputWindow::InputWindow(QWidget * parent):QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;

    /* Character Group*/

    QGroupBox *characterGroup = new QGroupBox(tr("Characters"));

    QLabel*characterLabel = new QLabel(tr("Choose:"));
    QComboBox *characterComboBox = new QComboBox;

    // populate with character names
    for(int i = 0; i < getCharData(io).size(); i++) {
        characterComboBox->addItem(QString::fromStdString(getCharData(io)[i].getName()));
    }

    connect(characterComboBox, QOverload<int>::of(&QComboBox::activated),this, &InputWindow::characterSelected);

    QGridLayout *characterLayout = new QGridLayout;
    characterLayout->addWidget(characterLabel, 0,0);
    characterLayout->addWidget(characterComboBox, 0, 1);
    characterGroup->setLayout(characterLayout);

    layout->addWidget(characterGroup,0,0);

    /* Sorting Group */

    QGroupBox *sortGroup = new QGroupBox(tr("Sorting"));

    QLabel *sortLabel = new QLabel(tr("Choose:"));
    QComboBox *sortComboBox = new QComboBox;

    sortComboBox->addItem(QString::fromStdString("Name"));
    sortComboBox->addItem(QString::fromStdString("HP"));
    sortComboBox->addItem(QString::fromStdString("Attack"));
    sortComboBox->addItem(QString::fromStdString("Defense"));

    connect(sortComboBox, QOverload<int>::of(&QComboBox::activated),this, &InputWindow::sortSelected);

    QGridLayout *sortLayout = new QGridLayout;
    sortLayout->addWidget(sortLabel, 0,0);
    sortLayout->addWidget(sortComboBox,0,1);
    sortGroup->setLayout(sortLayout);

    layout->addWidget(sortGroup,1,0);

    /* Name Search Group */

    QGroupBox *nameGroup = new QGroupBox(tr("Name"));

    QLabel *nameLabel = new QLabel(tr("Choose:"));

    minNameLineEdit = new QLineEdit;
    minNameLineEdit->setPlaceholderText("Min. Letter");
    minNameLineEdit->setFocus();

    maxNameLineEdit = new QLineEdit;
    maxNameLineEdit->setPlaceholderText("Max. Letter");
    maxNameLineEdit->setFocus();

    // add a BUTTON
    QPushButton *nameButt = new QPushButton;
    nameButt->setText("Save");

    // when button is clicked, call searchByName()
    connect(nameButt, SIGNAL(clicked()), this, SLOT(searchByName()));

    QGridLayout *nameLayout = new QGridLayout;
    nameLayout->addWidget(nameLabel, 0,0);
    // row, column row span, column span
    nameLayout->addWidget(minNameLineEdit, 1, 0, 1, 1);
    nameLayout->addWidget(maxNameLineEdit, 1, 1, 1, 1);
    nameLayout->addWidget(nameButt, 2, 0, 1, 2);
    nameGroup->setLayout(nameLayout);

    layout->addWidget(nameGroup,2,0);

    /* HP Search Group */

    QGroupBox *HPGroup = new QGroupBox(tr("HP"));

    QLabel*HPLabel = new QLabel(tr("Enter HP:"));
    QComboBox *HPComboBox = new QComboBox;

    // populate with option
    HPComboBox->addItem(QString::fromStdString("Greater"));
    HPComboBox->addItem(QString::fromStdString("Lesser"));
    HPComboBox->addItem(QString::fromStdString("Top"));
    HPComboBox->addItem(QString::fromStdString("Bottom"));


    HPValueLineEdit = new QLineEdit;
    HPValueLineEdit->setPlaceholderText("HP Value or Threshold");
    HPValueLineEdit->setFocus();

    connect(HPComboBox, QOverload<int>::of(&QComboBox::activated),this, &InputWindow::searchByHPSelected);

    QGridLayout *HPLayout = new QGridLayout;
    HPLayout->addWidget(HPLabel, 0,0);
    // row, column row span, column span
    HPLayout->addWidget(HPValueLineEdit, 1, 0, 1, 1);
    HPLayout->addWidget(HPComboBox, 1, 1);
    HPGroup->setLayout(HPLayout);

    layout->addWidget(HPGroup,3,0);

    /* Attack Search Group */
    QGroupBox *AttackGroup = new QGroupBox(tr("Attack"));

    QLabel *AttackLabel = new QLabel(tr("Enter Attack:"));
    QComboBox *AttackComboBox = new QComboBox;

    // populate with option
    AttackComboBox->addItem(QString::fromStdString("Greater"));
    AttackComboBox->addItem(QString::fromStdString("Lesser"));
    AttackComboBox->addItem(QString::fromStdString("Top"));
    AttackComboBox->addItem(QString::fromStdString("Bottom"));

    AttackValueLineEdit = new QLineEdit;
    AttackValueLineEdit->setPlaceholderText("Attack Value or Threshold");
    AttackValueLineEdit->setFocus();

    connect(AttackComboBox, QOverload<int>::of(&QComboBox::activated),this, &InputWindow::searchByAttackSelected);

    QGridLayout *AttackLayout = new QGridLayout;
    AttackLayout->addWidget(AttackLabel, 0,0);
    // row, column row span, column span
    AttackLayout->addWidget(AttackValueLineEdit, 1, 0, 1, 1);
    AttackLayout->addWidget(AttackComboBox, 1, 1);
    AttackGroup->setLayout(AttackLayout);

    layout->addWidget(AttackGroup,4,0);

    /* Defense Search Group */
    QGroupBox *DefenseGroup = new QGroupBox(tr("Defense"));

    QLabel *DefenseLabel = new QLabel(tr("Enter Defense:"));
    QComboBox *DefenseComboBox = new QComboBox;

    // populate with option
    DefenseComboBox->addItem(QString::fromStdString("Greater"));
    DefenseComboBox->addItem(QString::fromStdString("Lesser"));
    DefenseComboBox->addItem(QString::fromStdString("Top"));
    DefenseComboBox->addItem(QString::fromStdString("Bottom"));

    DefenseValueLineEdit = new QLineEdit;
    DefenseValueLineEdit->setPlaceholderText("Defense Value or Threshold");
    DefenseValueLineEdit->setFocus();

    connect(DefenseComboBox, QOverload<int>::of(&QComboBox::activated),this, &InputWindow::searchByDefenseSelected);

    QGridLayout *DefenseLayout = new QGridLayout;
    DefenseLayout->addWidget(DefenseLabel, 0,0);
    // row, column row span, column span
    DefenseLayout->addWidget(DefenseValueLineEdit, 1, 0, 1, 1);
    DefenseLayout->addWidget(DefenseComboBox, 1, 1);
    DefenseGroup->setLayout(DefenseLayout);

    layout->addWidget(DefenseGroup,5,0);


    /* end */
    setLayout(layout);
    setWindowTitle("Pokemon Data");
}

void InputWindow::characterSelected(int index) {
    // display character chart window

    character c = getCharData(io)[index];
    vector<character> v;
    v.push_back(c);

    io.write_to_file("PokemonOutput.txt", v);

    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(c);
    view->setMinimumSize(650,400);
    view->show();

}

void InputWindow::sortSelected(int index) {
    vector<character> v = getCharData(io);

    switch(index) {
    case 0: // name
        character::sortName(v);
        break;
    case 1: // HP
        character::sortHP(v);
        break;
    case 2: // Attack
        character::sortAttack(v);
        break;
    case 3: // Defense
        character::sortDefense(v);
        break;
    }
    io.write_to_file("PokemonOutput.txt", v);
}

void InputWindow::searchByName() {
    // sort by name
    vector<character> v = getCharData(io);
    character::sortName(v);

    // get & store inputs of min & max
    string min = (minNameLineEdit->text()).toStdString();
    string max = (maxNameLineEdit->text()).toStdString();

    // create a vector
    vector<character> name;

    // search vector & populate
    for(int i = 0; i < v.size(); i++) {
        if(toupper(v[i].getName()[0]) == toupper(min[0])) {
            while(toupper(v[i].getName()[0]) != toupper(max[0])) {
                name.push_back(v[i]);
                i++;
            }
            while(toupper(v[i].getName()[0]) == toupper(max[0])) {
                name.push_back(v[i]);
                i++;
            }
        }
    }

    io.write_to_file("PokemonOutput.txt", name);

    // pass vector to stacked bar
    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(name);
    view->setMinimumSize(1500,1000);
    view->show();
    // display
}

void InputWindow::searchByHPSelected(int index) {
    int HPValue = stoi((HPValueLineEdit->text()).toStdString());

    switch(index) {
    case 0:
        // get characters greater than HP
        greater(HPValue, "HP");
        break;
    case 1:
        // get characters lesser than HP
        lesser(HPValue, "HP");
        break;
    case 2:
        // get top HP
        top(HPValue, "HP");
        break;
    case 3:
        // get bottom HP
        bottom(HPValue, "HP");
        break;
    }

    // testing
    // cout << v[0].getName() << endl;
}

void InputWindow::searchByAttackSelected(int index) {
    int attackValue = stoi((AttackValueLineEdit->text()).toStdString());

    switch(index) {
    case 0:
        // get characters greater than Attack
        greater(attackValue, "Attack");
        break;
    case 1:
        // get characters lesser than Attack
        lesser(attackValue, "Attack");
        break;
    case 2:
        // get top Attack
        top(attackValue, "Attack");
        break;
    case 3:
        // get bottom Attack
        bottom(attackValue, "Attack");
        break;
    }
}

void InputWindow::searchByDefenseSelected(int index) {
    int defenseValue = stoi((DefenseValueLineEdit->text()).toStdString());

    switch(index) {
    case 0:
        // get characters greater than Defense
        greater(defenseValue, "Defense");
        break;
    case 1:
        // get characters lesser than Defense
        lesser(defenseValue, "Defense");
        break;
    case 2:
        // get top Defense
        top(defenseValue, "Defense");
        break;
    case 3:
        // get bottom Defense
        bottom(defenseValue, "Defense");
        break;
    }
}


vector<character> InputWindow::getCharData(iorunner io) {
    return io.returnVector();
}

void InputWindow::top(int val, string sortType) {
    vector<character> v = getCharData(io);
    vector<character> c;

    // sort correctly
    if(sortType == "HP")
        character::sortHP(v);
    else if(sortType == "Attack")
        character::sortAttack(v);
    else
        character::sortDefense(v);

    for(int i = v.size()-1; i > (v.size()-1)-val; i--) {
        c.push_back(v[i]);
    }

    io.write_to_file("PokemonOutput.txt", c);

    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(c);
    view->setMinimumSize(1500,1000);
    view->show();
}

void InputWindow::bottom(int val, string sortType) {
    vector<character> v = getCharData(io);
    vector<character> c;

    // sort correctly
    if(sortType == "HP")
        character::sortHP(v);
    else if(sortType == "Attack")
        character::sortAttack(v);
    else
        character::sortDefense(v);

    for(int i = 0; i < val; i++) {
        c.push_back(v[i]);
    }

    io.write_to_file("PokemonOutput.txt", c);

    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(c);
    view->setMinimumSize(1500,1000);
    view->show();
}

void InputWindow::greater(int val, string sortType) {
    vector<character> v = getCharData(io);
    vector<character> c;

    if(sortType == "HP") {
        character::sortHP(v);
        // greater than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getHP() > val) {
                c.push_back(v[i]);
            }
        }
    }
    else if(sortType == "Attack") {
        character::sortAttack(v);
        // greater than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getAttack() > val) {
                c.push_back(v[i]);
            }
        }
    }
    else {
        character::sortDefense(v);
        // greater than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getDefense() > val) {
                c.push_back(v[i]);
            }
        }
    }
    io.write_to_file("PokemonOutput.txt", c);

    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(c);
    view->setMinimumSize(1500,1000);
    view->show();
}

void InputWindow::lesser(int val, string sortType) {
    vector<character> v = getCharData(io);
    vector<character> c;

    if(sortType == "HP") {
        character::sortHP(v);
        // less than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getHP() < val) {
                c.push_back(v[i]);
            }
        }
    }
    else if(sortType == "Attack") {
        character::sortAttack(v);
        // less than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getAttack() < val) {
                c.push_back(v[i]);
            }
        }
    }
    else {
        character::sortDefense(v);
        // less than val
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getDefense() < val) {
                c.push_back(v[i]);
            }
        }
    }

    io.write_to_file("PokemonOutput.txt", c);

    stackedbar stackedbar;

    QChartView *view = stackedbar.show_bar(c);
    view->setMinimumSize(1500,1000);
    view->show();

}


