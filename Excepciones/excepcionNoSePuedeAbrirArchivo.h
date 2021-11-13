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
        const char* excepcion = archivoError.c_str();
        return excepcion;
    }
};

#endif