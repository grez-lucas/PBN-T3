#include"fight.h"
#include<iostream>

int main() {
    fight mainFight;
    mainFight.readInputFile("data tarea 3.csv");
    mainFight.applyBuffs();
    cout << mainFight.fighter1.hasKingOfDead << mainFight.fighter1.hasLastBreath << endl;
    cout << mainFight.fighter2.hasKingOfDead << mainFight.fighter2.hasLastBreath << endl;
    cout << mainFight.show() << endl;
    mainFight.beginFight();
    //cout << mainFight.fighter2.show() << endl;
    //mainFight.turn(mainFight.fighter2, mainFight.fighter1);
    return 0;
}