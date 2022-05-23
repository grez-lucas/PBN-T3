#include"arena.h"
#include"peleador.h"
#include"objeto.h"

using namespace std;

class fight {
private:
    fighter fighter1;
    object f1object1;
    object f1object1;
    fighter fighter2;
    object f1object2;
    object f1object2;
    arena arena;
public:
    fight(fighter,object,object,fighter,object,object,arena);
    void turn();
    void readInputFile(string); //reads input file

};
