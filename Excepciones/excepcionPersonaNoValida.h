#pragma once

#ifndef ExcepcionPersonaNoValida_h
#define ExcepcionPersonaNoValida_h

#include <exception>

class ExcepcionPersonaNoValida :public std::exception {

	public:
	ExcepcionPersonaNoValida() noexcept = default;
	~ExcepcionPersonaNoValida() = default;

	virtual const char* what() const noexcept {
		return "Persona no valida";
	}

};






#endif // !ExcepcionPersonaNoValida_h
