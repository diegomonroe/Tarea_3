#include "libro.h"
#include <string>

using namespace std;

Libro::Libro(int id, string nombre, string apellido, string correo) {
    this->id = id;
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->apellido, apellido.c_str());
    strcpy(this->correo, apellido.c_str());
}

Libro::Libro() {
    this->id = 0;
    strcpy(this->nombre, "");
    strcpy(this->apellido, "");
    strcpy(this->correo, "");
}