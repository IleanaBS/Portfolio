/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Implementación de la clase TanqueGasolina

*/

#include "TanqueGasolina.hpp"

TanqueGasolina::TanqueGasolina()
{
    nivel = capacidad;
}

double TanqueGasolina::getNivelGasolina()
{
    return nivel;
}

double TanqueGasolina::getPorcentajeNivel()
{
    return nivel / capacidad;
}

void TanqueGasolina::cargarTanque(double litros)
{
    if (nivel + litros <= capacidad) 
    {
        nivel += litros;
    } else 
    {
        nivel = capacidad;
    }
}

void TanqueGasolina::gastarGasolina(double litros)
{
    if (nivel - litros >= 0) {
        nivel -= litros;
    } else {
        nivel = 0;
    }
}