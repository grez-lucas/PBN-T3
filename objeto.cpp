#include"objeto.h"

string object::show(){
    return ("==Objeto==\nNombre: " + this->name
            + "\nTipo: " + this->health
            + "\nSalud: " + this->health
            + "\nFuerza: " + this->strength
            + "\nVelocidad: " + this->speed
            + "\nInteligencia: " + this->intelligence
            + "\nResistencia: " + this->resistance
            + "\nLeyenda: " + this->legend
            );
};