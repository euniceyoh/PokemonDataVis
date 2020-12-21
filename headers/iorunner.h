#ifndef IORUNNER_H
#define IORUNNER_H

#include <vector>
#include <iostream>
#include "character.h"
using namespace std;

class FileIO
{

    virtual vector<character> read_from_file(string file_name) = 0; /* part 2 - change to linked list type */

    virtual int write_to_file(string file_name, vector<character> input_data) = 0; /* part 2 - change to linked list type */
    // return of 0 means success, and return 1 or greater means some failure.
    // For now, return 0 (we'll assume that any write is okay)
};

class iorunner:FileIO
{
public:
    vector<character> read_from_file(string file_name);
    int write_to_file(string file_name, vector<character> input_data);
    vector<character> returnVector();

    iorunner() {}

};

#endif // IORUNNER_H
