/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Implementación de la clase Automobil
*/

#include "Automobil.hpp"

#include <iostream>
#include <array>

using namespace std;

Automobil::Automobil()
{
    estado = false;
    velocidadActual = 0;
}

void Automobil::prenderApagar()
{
    estado = !estado;
    if (estado)
    {
        tablero.mostrarMensaje("El automobil se ha encendido");
    }
    else
    {
        tablero.mostrarMensaje("El automobil se ha apagado");
    }
}

void Automobil::acelerar()
{
    if (estado)
    {
        velocidadActual += 15;
        tanqueGasolina.gastarGasolina(0.005 * velocidadActual);

        if (velocidadActual > 230)
        {
            velocidadActual = 230;
            cout << "La velocidad maxima permitida es 230 km/h" << endl;
        }

        if (velocidadActual > 160)
        {
            tablero.mostrarMensaje("Warning Velocidad");
        }

        if (tanqueGasolina.getPorcentajeNivel() < 0.15)
        {
            tablero.mostrarMensaje("Reminder Tanque Gasolina");
        }
    }
    else
    {
        tablero.mostrarMensaje("El automobil esta apagado. No se puede acelerar");
    }
}

void Automobil::frenar()
{
    if (estado)
    {
        velocidadActual -= 25;

        if (velocidadActual < 0)
        {
            velocidadActual = 0;
        }
    }
    else
    {
        tablero.mostrarMensaje("El automobil esta apagado. No se puede frenar");
    }
}

void Automobil::prenderLuces() 
{
    if (estado)
    {
        luz.prenderLuces();
        tablero.mostrarMensaje("Las luces del automobil han sido encendidas");
    }
    else
    {
        tablero.mostrarMensaje("El automobil esta apagado. No se pueden encender las luces");
    }
}

void Automobil::apagarLuces()
{
    luz.apagarLuces();
    if (estado)
    {
        luz.prenderLuces();
        tablero.mostrarMensaje("Las luces del automobil han sido apagadas");
    }
    else
    {
        tablero.mostrarMensaje("El automobil esta apagado. No se pueden apagar las luces porque ya se encuentran apagadas");
    }
}

void Automobil::cargarGasolina(double litros)
{
    if (litros > 0)
    {
        if (tanqueGasolina.getNivelGasolina() + litros <= 42.0)
        {
            tanqueGasolina.cargarTanque(litros);
            tablero.mostrarMensaje("Se han cargado " + to_string(litros) + " litros de gasolina");
        }
        else
        {
            tablero.mostrarMensaje("No se puede cargar esa cantidad de gasolina porque excede la capacidad maxima del tanque");
        }
    }
    else
    {
        tablero.mostrarMensaje("No se puede cargar una cantidad igual o menor a cero de litros de gasolina");
    }
}

void Automobil::mostrarTablero()
{
    array<double, 4> presionesLlantas;
    presionesLlantas[0] = llanta.getPresion(0);
    presionesLlantas[1] = llanta.getPresion(1);
    presionesLlantas[2] = llanta.getPresion(2);
    presionesLlantas[3] = llanta.getPresion(3);

    tablero.mostrarEstado(estado, velocidadActual, tanqueGasolina.getNivelGasolina(), luz.getEstadoLuces(), presionesLlantas);
}

void Automobil::inflarLlanta(int indice, double presion)
{
    double presionActual = llanta.getPresion(indice);
    if (presionActual >0 && presion > 0)
    {
        llanta.inflar(indice, presion);
        tablero.mostrarMensaje("La llanta " + to_string(indice + 1) + " ha sido inflada a " + to_string(presion) + " psi");
        array<double, 4> presionesLlantas;
        presionesLlantas[0] = llanta.getPresion(0);
        presionesLlantas[1] = llanta.getPresion(1);
        presionesLlantas[2] = llanta.getPresion(2);
        presionesLlantas[3] = llanta.getPresion(3);

        tablero.mostrarEstado(estado, velocidadActual, tanqueGasolina.getNivelGasolina(), luz.getEstadoLuces(), presionesLlantas);
    }
    else
    {
        tablero.mostrarMensaje("No se puede inflar la llanta " + to_string(indice + 1) + " con una cantidad igual o menor a cero psi");
    }
}

void Automobil::desinflarLlanta(int indice, double presion)
{
    double presionActual = llanta.getPresion(indice);
    if (presionActual >0 && presion > 0)
    {
        llanta.desinflar(indice, presion);
        tablero.mostrarMensaje("La llanta " + to_string(indice + 1) + " ha sido desinflada a " + to_string(presion) + " psi");
        array<double, 4> presionesLlantas;
        presionesLlantas[0] = llanta.getPresion(0);
        presionesLlantas[1] = llanta.getPresion(1);
        presionesLlantas[2] = llanta.getPresion(2);
        presionesLlantas[3] = llanta.getPresion(3);

        tablero.mostrarEstado(estado, velocidadActual, tanqueGasolina.getNivelGasolina(), luz.getEstadoLuces(), presionesLlantas);
    }
    else
    {
        tablero.mostrarMensaje("No se puede desinflar la llanta " + to_string(indice + 1) + " con una cantidad igual o menor a cero psi");
    }
}