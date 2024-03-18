/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Definición de la clase Tablero
*/

#include <iostream>
#include <string>
#include <array>

using namespace std;

#ifndef TABLERO_HPP
#define TABLERO_HPP

class Tablero
{
/*private:
    double indicadorNivelTanqueGasolina;
    string indicadorLuces;
    double indicadorVelocidadActual;
    string indicadorPeligroVelocidad;
    string recordatorioTanque;
*/
public:
    Tablero();
    void mostrarEstado(bool encendido, int velocidad, double nivelGasolina, bool lucesEncendidas, array<double, 4>& presionesLlantas);
    void mostrarMensaje(const string& mensaje);
};

#endif