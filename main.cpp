#include"fight.h"
#include<iostream>

int main() {
    fight mainFight;
    mainFight.readInputFile("data tarea 3.csv");
    mainFight.applyBuffs();
    cout << mainFight.show() << endl;
    mainFight.turn();
    cout << mainFight.fighter2.show() << endl;
    mainFight.turn();
    //cout << mainFight.fighter2.show() << endl;
    //mainFight.turn(mainFight.fighter2, mainFight.fighter1);
    return 0;
}