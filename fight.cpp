#include"fight.h"
#include<fstream>
#include<iostream>

using namespace std;




void fight::readInputFile(string input_file_name) {
    ifstream input;

    string buffer;

    input.open(input_file_name);

    getline(input, buffer, ';');
    while(input) {
    
        cout << buffer << endl;
        getline(input, buffer, ';');
    } 
        

    input.close();
}

void fight::turn() {

}