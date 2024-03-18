/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Implementación de la clase Luces

*/

#include "Luz.hpp"

Luz::Luz()
{
    estadoLuces = false;
}

//checar si es true o false
void Luz::prenderLuces()
{
    estadoLuces = true;
}

//checar si es true o false
void Luz::apagarLuces()
{
    // original: estadoLuces = true;
    estadoLuces = false;
}

bool Luz::getEstadoLuces()
{
    return estadoLuces;
}