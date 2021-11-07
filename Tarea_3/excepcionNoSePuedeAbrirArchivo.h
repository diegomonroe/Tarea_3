#pragma once
#ifndef ExcepcionNoSePuedeAbrirArchivo_H
#define ExcepcionNoSePuedeAbrirArchivo_H

#include <exception>

class ExcepcionNoSePuedeAbrirArchivo : public std::exception
{
    string archivoError{};
    public:
    ExcepcionNoSePuedeAbrirArchivo(string archivoError) noexcept {
        this->archivoError = archivoError;
    };
    ~ExcepcionNoSePuedeAbrirArchivo() = default;

    virtual const char* what() const noexcept {
        string mensaje = "No se puede abrir archivo " + archivoError;
        const char* excepcion = mensaje.c_str();
        return excepcion;
    }

};

#endif