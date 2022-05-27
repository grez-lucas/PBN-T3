#include"peleador.h"

string fighter::show(){
    return ("==Peleador==\nNombre: " + this->name
            + "\nSalud: " + to_string(this->health)
            + "\nFuerza: " + to_string(this->strength)
            + "\nVelocidad: " + to_string(this->speed)
            + "\nInteligencia: " + to_string(this->intelligence)
            + "\nResistencia: " + to_string(this->resistance)
            + "\nLeyenda: " + this->legend + "\n"
            );
};

bool fighter::isAlive(){
    return this->health > 0;
}