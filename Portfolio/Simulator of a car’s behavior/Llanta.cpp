/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Implementación de la clase Llantas

*/

#include "Llanta.hpp"

Llanta::Llanta()
{
    presiones.fill(33.00);
}

double Llanta::getPresion(int indice)
{
    return presiones[indice];
}

void Llanta::inflar(int indice, double presion)
{
    presiones[indice] = presion;
}

void Llanta::desinflar(int indice, double presion)
{
    presiones[indice] = presion;
}