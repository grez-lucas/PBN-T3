#include<string>

using namespace std;

class fighter {
public:
    string show();
    bool isAlive();
    string name;
    int health;
    int strength;
    int speed;
    int intelligence;
    int resistance;
    string legend;
};