#include<string>

using namespace std;

class fighter {
public:
    fighter();
    string show();
    bool isAlive();
    string name;
    int health;
    int strength;
    int speed;
    int intelligence;
    int resistance;
    string legend;
    bool hasKingOfDead;
    bool hasLastBreath;
};