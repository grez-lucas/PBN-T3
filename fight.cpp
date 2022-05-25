#include"fight.h"
#include<fstream>
#include<iostream>


using namespace std;




void fight::readInputFile(string input_file_name) {
    ifstream input;

    string buffer;

    input.open(input_file_name);

    while(input) {
        getline(input, buffer, '\"');
        cout << buffer << endl;
        /*if( buffer == "\"peleador") {
            cout << "PELEADOR DETECTADO" << endl;
        } */
        //getline(input, buffer, '"');
    } 
        

    input.close();
}

void fight::turn() {

}