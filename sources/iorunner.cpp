#include "iorunner.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

vector<character> characterData;

vector<character> iorunner::read_from_file(string file_name)
{
    string comma_token(",");
    string rdata;

    ifstream read_file(file_name);

    if(!read_file.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }

    getline(read_file, rdata);

    while(getline(read_file, rdata)) {

        size_t found = rdata.find(comma_token);
        if(found != string::npos) {
            stringstream s_stream(rdata);
            vector<string> vec_data;

            while(s_stream.good())
            {
                string sub_string;
                getline(s_stream, sub_string, ',');
                vec_data.push_back(sub_string);
            }

            bool legendary;
            if(vec_data[12] == "False")
                legendary = false;
            else
                legendary = true;

            character c(vec_data[1],vec_data[2], vec_data[3], stoi(vec_data[4]), stoi(vec_data[5]), stoi(vec_data[6]), stoi(vec_data[7]),
                    stoi(vec_data[8]), stoi(vec_data[9]), stoi(vec_data[10]), stoi(vec_data[11]), legendary);

            characterData.push_back(c);
        }
    }

    read_file.close();
    return characterData;
}

int iorunner::write_to_file(string file_name, vector<character> input_data)
{
    ofstream myfile(file_name, ios_base::app);
       if (myfile.is_open())
       {
           for(int i = 0; i < input_data.size(); i++) {
               myfile << input_data[i].getName();
           }
           myfile.close();
       }
       else cout << "Unable to open file";
       return 0;
}


vector<character> iorunner::returnVector() {
    return characterData;
}

