/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Implementación de la clase Tablero
*/

#include "Llanta.hpp"
#include "Tablero.hpp"
#include "Luz.hpp"
#include <iostream>

Tablero::Tablero()
{
}

void Tablero::mostrarEstado(bool encendido, int velocidad, double nivelGasolina, bool lucesEncendidas, array<double, 4> &presionesLlantas)
{
    cout << "\n---------------- TABLERO ----------------" << endl;
    cout << "\nEstado del automobil: " << (encendido ? "Encendido" : "Apagado") << endl;
    cout << "Velocidad: " << velocidad << " km/h" << endl;
    if (velocidad > 160)
    {
        cout << "(Peligro!)" << endl;
    }
    cout << "Nivel de gasolina: " << nivelGasolina << " litros (" << (nivelGasolina / 42.0) * 100.0 << "%)" << endl;
    if (((nivelGasolina / 42.0) * 100.0) <= 15)
    {
        cout << "(Recordatorio! Llenar el tanque de gasolina)" << endl;
    }
    cout << "Luces: " << (lucesEncendidas ? "Encendidas" : "Apagadas") << endl;

    cout << "Estado de las llantas: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nLlanta " << (i + 1) << ": " << presionesLlantas[i] << " psi" << endl;
        /*
        se realizaron los cálculos a mano para obtener el 20% de 33 (6.6)
        6.6 + 33 = 39.3 = capacidad máxima permitida
        33 - 6.6 = 26.4 = capacidad mínima permitida
        */
        if (presionesLlantas[i] > 39.6 || presionesLlantas[i] < 26.4)
        {
            cout << " (Peligro!)" << endl;
        }
        cout << "  ";
    }
    cout << endl;
}

void Tablero::mostrarMensaje(const string &mensaje)
{
    cout << mensaje << endl;
}