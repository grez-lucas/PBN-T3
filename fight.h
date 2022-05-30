#include"arena.h"
#include"peleador.h"
#include"objeto.h"
#include<fstream>


using namespace std;

class fight {
public:
    fight();
    string show();
    void applyBuffs();
    void turn();
    void beginFight();
    void readInputFile(string); //reads input file

    fighter fighter1;
    object f1object1;
    object f1object2;
    fighter fighter2;
    object f2object1;
    object f2object2;
    arena picked_arena;
    ofstream output;
    int turnNumber;
};
