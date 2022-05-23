#include"fight.h"
#include<fstream>
#include<iostream>

using namespace std;


void fight::readInputFile(string input_file_name) {
    ifstream input;

    string s;

    input.open(input_file_name);

    input >> s;
    while(input) {

    }

    input.close();
}

void fight::turn() {
    
}