#include "libro.h"
#include <string>

using namespace std;

Libro::Libro(int id, string nombre, string apellido, string correo) {
    this->id = id;
    strcpy_s(this->nombre, nombre.c_str());
    strcpy_s(this->apellido, apellido.c_str());
    strcpy_s(this->correo, apellido.c_str());
}

Libro::Libro() {
    this->id = 0;
    strcpy_s(this->nombre, "");
    strcpy_s(this->apellido, "");
    strcpy_s(this->correo, "");
}