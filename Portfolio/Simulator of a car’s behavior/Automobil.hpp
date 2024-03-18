/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Definición de la clase Automobil

*/

#include "Llanta.hpp"
#include "Luz.hpp"
#include "Tablero.hpp"
#include "TanqueGasolina.hpp"

#ifndef AUTOMOBIL_HPP
#define AUTOMOBIL_HPP

class Automobil
{
private:
    double velocidadActual;
    bool estado;

    //declarando la composición
    Luz luz;
    Llanta llanta;
    Tablero tablero;
    TanqueGasolina tanqueGasolina;

public:
    Automobil(); // constructor por default
    void prenderApagar();
    void acelerar();
    void frenar();
    void prenderLuces();
    void apagarLuces();
    void cargarGasolina(double litros);
    void mostrarTablero();
    void inflarLlanta(int indice, double presion);
    void desinflarLlanta(int indice, double presion);
};
#endif