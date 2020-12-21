#include "mainwindow.h"
#include <iostream>
#include "character.h"
#include "iorunner.h"
#include "inputwindow.h"
#include <QDir>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * updated project's working directory path to current directory instead of build directory
     * to be able to read / write to file
     */
    const string FILEPATH = "Pokemon.csv";
    iorunner io;

    vector<character> charData = io.read_from_file(FILEPATH);

    InputWindow w;
    w.show();
    return a.exec();
}


