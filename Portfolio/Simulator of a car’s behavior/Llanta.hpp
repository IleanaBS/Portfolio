/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Definición de la clase Llantas

*/

#ifndef LLANTA_HPP
#define LLANTA_HPP

#include <array>

using namespace std;

class Llanta
{
private:
    array<double, 4> presiones; //arreglo de tamaño 4 con tipo de dato double

public:
    Llanta(); //constructor por default
    double getPresion(int indice);
    void inflar(int indice, double presion);
    void desinflar(int indice, double presion);
};

#endif