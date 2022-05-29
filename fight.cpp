#include "fight.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include<cmath>
#include <limits>

using namespace std;

// SPECIAL ABILITIES: King of The Dead is declared in beginFight(), while Last Breath is declared in the turn() method

fight::fight() {
    this->turnNumber = 0;
}

string fight::show()
{
    return (
        "========PELEA========\nPeleador 1:\t" + this->fighter1.name + "\n" +
        "Objetos:\t" + "[ " + this->f1object1.name + " " + this->f1object2.name + "]\n" +
        "Peleador 2:\t" + this->fighter2.name + "\n" +
        "Objetos:\t" + "[ " + this->f2object1.name + " " + this->f2object2.name + "]\n" +
        "Arena: " + this->picked_arena.name + "\n");
}

void fight::applyBuffs()
    {
        //DETERMINE SPECIAL ABILITIES
        // DEBUG: UNCOMMENTING THIS BLOCK TRIGGERS AN ENDLESS LOOP, FIND OUT WHY!
        this->fighter1.hasKingOfDead = rand() % 2;
        this->fighter1.hasLastBreath = rand() % 2;
        this->fighter2.hasKingOfDead = rand() % 2;
        this->fighter2.hasLastBreath = rand() % 2; 
        //FIGHTER 1 OBJECT BUFFS
        if(this->f1object1.name != ""){
        this->fighter1.health += stoi(f1object1.health);
        this->fighter1.strength += stoi(f1object1.strength);
        this->fighter1.speed += stoi(f1object1.speed);
        this->fighter1.intelligence += stoi(f1object1.intelligence);
        this->fighter1.resistance += stoi(f1object1.resistance);
        }
        if(this->f1object2.name != ""){
        this->fighter1.health += stoi(f1object2.health);
        this->fighter1.strength += stoi(f1object2.strength);
        this->fighter1.speed += stoi(f1object2.speed);
        this->fighter1.intelligence += stoi(f1object2.intelligence);
        this->fighter1.resistance += stoi(f1object2.resistance);
        }
        //FIGHTER 2 OBJECT BUFFS
        if(this->f2object1.name != ""){
        this->fighter2.health += stoi(f2object1.health);
        this->fighter2.strength += stoi(f2object1.strength);
        this->fighter2.speed += stoi(f2object1.speed);
        this->fighter2.intelligence += stoi(f2object1.intelligence);
        this->fighter2.resistance += stoi(f2object1.resistance);
        }
        if(this->f2object2.name != ""){
        this->fighter2.health += stoi(f2object2.health);
        this->fighter2.strength += stoi(f2object2.strength);
        this->fighter2.speed += stoi(f2object2.speed);
        this->fighter2.intelligence += stoi(f2object2.intelligence);
        this->fighter2.resistance += stoi(f2object2.resistance);
        }
        //FIGHTER 1 ARENA BUFFS
        this->fighter1.health *= this->picked_arena.health;
        this->fighter1.strength *= this->picked_arena.strength;
        this->fighter1.speed *= this->picked_arena.speed;
        this->fighter1.intelligence *= this->picked_arena.intelligence;
        this->fighter1.resistance *= this->picked_arena.resistance;
        //FIGHTER 2 ARENA BUFFS
        this->fighter2.health *= this->picked_arena.health;
        this->fighter2.strength *= this->picked_arena.strength;
        this->fighter2.speed *= this->picked_arena.speed;
        this->fighter2.intelligence *= this->picked_arena.intelligence;
        this->fighter2.resistance *= this->picked_arena.resistance;
    }

void fight::turn()
{   
    fighter attacker;
    fighter defender;
    int attackerHitMultiplier, crit, hit;

    if (this->turnNumber % 2 == 0) {
        attacker =  this->fighter1;
        defender = this-> fighter2;

    }else {
        attacker = this->fighter2;
        defender = this->fighter1;
    }
    cout << "\nTurno " << this->turnNumber << " COMENZADO!" << endl;

    //LAST BREATH
    if(attacker.hasLastBreath
     && (attacker.health < 10 && attacker.health > 1)
     && ( rand() % 10 + 1) <= 4)
     {
        cout << "ULTIMO ALIENTO ACTIVADO POR " << attacker.name << "!!" << endl;
        attacker.health = 1;
        attacker.hasLastBreath = false;
        attacker.strength *= 0.5;
        attacker.speed *= 0.5;
        attacker.resistance *= 0.5;
    }
    if(defender.hasLastBreath 
    && (attacker.health < 10 && attacker.health > 1)
    && ( rand() % 10 + 1) <= 4)
    {
        cout << "ULTIMO ALIENTO ACTIVADO POR " << attacker.name << "!!" << endl;
        defender.health = 1;
        defender.hasLastBreath = false;
        defender.strength *= 0.5;
        defender.speed *= 0.5;
        defender.resistance *= 0.5;
    }

    //WEAR
    if(attacker.resistance > 0) {
        attackerHitMultiplier =  (exp( (-20*this->turnNumber)/ attacker.resistance) )*(1+ (20*this->turnNumber)/ attacker.resistance);
        if(attackerHitMultiplier<=0) attacker.resistance = 0; //So fight doesnt go on for many more rounds
    }else {
        attackerHitMultiplier = 0;
        cout << attacker.name << " ESTA SIN RESISTENCIA Y NO PUEDE GOLPEAR!"<< endl;
        cout << "Salud restante de " << defender.name << ":\t" << defender.health << endl;
        this->turnNumber ++;
        attacker.resistance --;
        defender.resistance --;
        return;
    }
    attacker.resistance --;
    defender.resistance --;


    //HIT
    crit = rand() % 3;
    switch(crit){
        case 0:
        cout << "golpe fallado!" << endl;
        break;
        case 2:
        cout << "golpe CRITICO!" << endl;
        break;
    }
    hit =  crit * ( (attacker.speed * attacker.strength)/(attacker.speed + attacker.strength) + attacker.intelligence ) * attackerHitMultiplier;
    if(hit<0) hit =0;

    //DEBUG:
    //cout << attacker.show() << endl;
    //cout << defender.show() << endl;

    cout << attacker.name << " GOLPEA A " <<  defender.name << " POR " << hit << " DE DANO!" << endl;
    defender.health -= hit;
    cout << "Vida restante de " << defender.name << ":\t" << defender.health << endl;
    
    if (this->turnNumber % 2 == 0) {
        this->fighter1.health = attacker.health;
        this->fighter2.health =  defender.health;
        this->fighter1.resistance =  attacker.resistance;
        this->fighter2.resistance =  defender.resistance;
        this->fighter1.hasLastBreath =  attacker.hasLastBreath;
        this->fighter2.hasLastBreath =  defender.hasLastBreath;
    }else {
        this->fighter2.health = attacker.health;
        this->fighter1.health = defender.health;
        this->fighter2.resistance =  attacker.resistance;
        this->fighter1.resistance =  defender.resistance;
        this->fighter2.hasLastBreath =  attacker.hasLastBreath;
        this->fighter1.hasLastBreath =  defender.hasLastBreath;
    }


    this->turnNumber ++;
}

void fight::beginFight()
{
    int initHealthFighter1 = this->fighter1.health;
    int initHealthFighter2 = this->fighter2.health;

    while (this->fighter1.isAlive() && this->fighter2.isAlive())
    {
        turn();
        if (this->fighter1.resistance <= 0 && fighter2.resistance <= 0)
        {
            cout << "EMPATE: ambos peleadores se han quedado SIN RESISTENCIA!" << endl;
            return;
        }
        if (this->fighter1.isAlive() == false)
        {
            if (this->fighter1.hasKingOfDead && ( (rand() % 10 + 1) <= 3 ) )
            {
                this->fighter1.health = initHealthFighter1 / 2;
                this->fighter1.intelligence /= 2;
                this->fighter1.hasKingOfDead = false;
                cout << "REY DE LOS MUERTOS ACTIVADO POR " << this->fighter1.name << "!!" << endl;
                continue;
            }
            cout << this->fighter2.name << " HA GANADO!" << endl;
            return;
        }
        else if (this->fighter2.isAlive() == false)
        {
            if (this->fighter2.hasKingOfDead && ((rand() % 10 + 1) <= 3))
            {
                this->fighter2.health = initHealthFighter2 / 2;
                this->fighter2.intelligence /= 2;
                this->fighter2.hasKingOfDead = false;
                cout << "REY DE LOS MUERTOS ACTIVADO POR " << this->fighter2.name << "!!" << endl;
                continue;
            }
            cout << this->fighter1.name << " HA GANADO!" << endl;
            return;
        }
    }
}

void fight::readInputFile(string input_file_name)
{
    ifstream input;

    vector<string> row;
    string line, word, buffer;

    // firstFighterAuxFlag is used to detect when a fighter's objects are currently being read
    // only when another fighter is detected and the firstFighterAuxFlag is false,
    //  will firstFighterFlag turn to false as well
    bool firstFighterFlag = true, firstFighterAuxFlag = true;
    bool firstObjectFlag = true;

    input.open(input_file_name);
    getline(input, line);

    while (input)
    {
        row.clear();

        bool fighterFlag = false, objectFlag = false, arenaFlag = false;
        int counter = 0;

        stringstream s(line);

        while (getline(s, word, ';'))
        {
            if (word == "\"peleador" || word == "\"Peleador")
                fighterFlag = true;
            if (word == "\"objeto" || word == "\"Objeto")
                objectFlag = true;
            if (word == "\"arena" || word == "\"Arena")
                arenaFlag = true;

            // If attributes are over and only legend is left...
            if ((counter == 6 && (fighterFlag || arenaFlag)) || (counter == 7 && objectFlag))
            {
                row.push_back(word);
                getline(s, word);
                row.push_back(word);
                break;
            }

            row.push_back(word);
            // cout << word << endl;
            counter++;
        }
        // SAVE FIGHTER BLOCK
        if (fighterFlag)
        {
            firstObjectFlag = true;
            if (!firstFighterAuxFlag)
                firstFighterFlag = false;

            if (firstFighterFlag)
            {
                this->fighter1.name = row[1];
                this->fighter1.health = stoi(row[2]);
                this->fighter1.strength = stoi(row[3]);
                this->fighter1.speed = stoi(row[4]);
                this->fighter1.intelligence = stoi(row[5]);
                this->fighter1.resistance = stoi(row[6]);
                this->fighter1.legend = row[7];
                firstFighterAuxFlag = false;
            }
            else
            {
                this->fighter2.name = row[1];
                this->fighter2.health = stoi(row[2]);
                this->fighter2.strength = stoi(row[3]);
                this->fighter2.speed = stoi(row[4]);
                this->fighter2.intelligence = stoi(row[5]);
                this->fighter2.resistance = stoi(row[6]);
                this->fighter2.legend = row[7];
            }
        }
        // SAVE OBJECT BLOCK
        else if (objectFlag)
        {
            if (firstFighterFlag)
            {
                if (firstObjectFlag)
                {
                    this->f1object1.name = row[1];
                    this->f1object1.type = row[2];
                    this->f1object1.health = row[3];
                    this->f1object1.strength = row[4];
                    this->f1object1.speed = row[5];
                    this->f1object1.intelligence = row[6];
                    this->f1object1.resistance = row[7];
                    this->f1object1.legend = row[8];
                    firstObjectFlag = false; // TODO: Think of what happens if second object is NULL and there's more objects later
                }
                else
                {
                    this->f1object2.name = row[1];
                    this->f1object2.type = row[2];
                    this->f1object2.health = row[3];
                    this->f1object2.strength = row[4];
                    this->f1object2.speed = row[5];
                    this->f1object2.intelligence = row[6];
                    this->f1object2.resistance = row[7];
                    this->f1object2.legend = row[8];
                }
            }
            else
            {
                if (firstObjectFlag)
                {
                    this->f2object1.name = row[1];
                    this->f2object1.type = row[2];
                    this->f2object1.health = row[3];
                    this->f2object1.strength = row[4];
                    this->f2object1.speed = row[5];
                    this->f2object1.intelligence = row[6];
                    this->f2object1.resistance = row[7];
                    this->f2object1.legend = row[8];
                    firstObjectFlag = false;
                }
                else
                {
                    this->f2object2.name = row[1];
                    this->f2object2.type = row[2];
                    this->f2object2.health = row[3];
                    this->f2object2.strength = row[4];
                    this->f2object2.speed = row[5];
                    this->f2object2.intelligence = row[6];
                    this->f2object2.resistance = row[7];
                    this->f2object2.legend = row[8];
                }
            }
        }
        // SAVE ARENA BLOCK
        else if (arenaFlag)
        {
            this->picked_arena.name = row[1];
            this->picked_arena.health = stod(row[2].substr(0, row[2].find("%"))) / 100 + 1.0;
            this->picked_arena.strength = stod(row[3].substr(0, row[3].find("%"))) / 100 + 1.0;
            this->picked_arena.speed = stod(row[4].substr(0, row[4].find("%"))) / 100 + 1.0;
            this->picked_arena.intelligence = stod(row[5].substr(0, row[5].find("%"))) / 100 + 1.0;
            this->picked_arena.resistance = stod(row[6].substr(0, row[6].find("%"))) / 100 + 1.0;
            this->picked_arena.legend = row[7];
        }
        else
        {
            // DEBUG
            cout << "Formato de archivo incorrecto, porfavor reescribalo e intente nuevamente" << endl;
            break;
        }

        /*for (auto i = row.begin(); i != row.end(); ++i) cout << *i << endl;
        cout << endl;*/
        getline(input, line);
    }
    // DEBUG:
    //cout << this->fighter1.show() << endl;
    //cout << this->fighter2.show() << endl;
    // cout << this-> to_string(f2object2.name == "") << endl;
    // cout << "Peleador 1 objetos:\n"<<this->f1object1.name << endl;
    // cout << this->f1object2.name << endl;
    // cout << "Peleador 2 objetos:\n"<<this->f2object1.name << endl;
    // cout << this->f2object2.name << endl;

    input.close();
}