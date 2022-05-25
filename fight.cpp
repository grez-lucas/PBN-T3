#include"fight.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include <vector>


using namespace std;




void fight::readInputFile(string input_file_name) {
    ifstream input;

    vector<string> row;
    string line, word, buffer;

    bool firstFighterFlag = true;
    input.open(input_file_name);

    while(input) {
        row.clear();

        bool fighterFlag = false, objectFlag = false, arenaFlag = false;
        int counter = 0;
        
        getline(input, line);
        stringstream s(line);

        while(getline( s, word, ';')){
            if (word == "\"peleador" || word == "\"Peleador" ) fighterFlag = true;
            if (word == "\"objeto" || word == "\"Objeto" ) objectFlag = true;
            if (word == "\"arena" || word == "\"Arena" ) arenaFlag = true;

            //If attributes are over and only legend is left...
            if ( (counter == 6  && (fighterFlag || arenaFlag)) || (counter == 7 && objectFlag)  ) { 
                row.push_back(word);
                getline(s, word);
                row.push_back(word);
                break;
            }

            row.push_back(word);
            //cout << word << endl;
            counter ++;
        }

        if (fighterFlag) {
            if(firstFighterFlag) {
                cout << "primer peleador!!" << endl;
                this->fighter1.name = row[1];
                this->fighter1.health = stoi(row[2]);
                this->fighter1.strength = stoi(row[3]);
                this->fighter1.speed = stoi(row[4]);
                this->fighter1.intelligence = stoi(row[5]);
                this->fighter1.resistance = stoi(row[6]);
                this->fighter1.legend = row[7];
                firstFighterFlag = false;

            }
            else {
                cout << "segundo peleador!!" << endl;
                this->fighter2.name = row[1];
                this->fighter2.health = stoi(row[2]);
                this->fighter2.strength = stoi(row[3]);
                this->fighter2.speed = stoi(row[4]);
                this->fighter2.intelligence = stoi(row[5]);
                this->fighter2.resistance = stoi(row[6]);
                this->fighter2.legend = row[7];
    
            }
        }
        else if (objectFlag) {
            cout << "objeto!!" << endl;
        }
        else if (arenaFlag) {
            cout << "arena!!" << endl;
        }
        else{
            cout << "Formato de archivo incorrecto, porfavor reescribalo e intente nuevamente" << endl;
            break;
        }
        
        for (auto i = row.begin(); i != row.end(); ++i) cout << *i << endl;
        cout << endl;
        
    }
    //DEBUG:   
    cout << "Fighter1 is: " << this->fighter1.name << " Fighter2 is: " << this->fighter2.name << endl;
    cout << "Fighter1 health: " << this->fighter1.health << " Fighter2 health: " << this->fighter2.health << endl;

    input.close();
}

void fight::turn() {

}