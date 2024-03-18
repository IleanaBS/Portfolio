/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Definición de la clase TanqueGasolina

*/

#ifndef TANQUEGASOLINA_HPP
#define TANQUEGASOLINA_HPP

class TanqueGasolina
{
private:
    const double capacidad = 42.0;
    double nivel;

public:
    TanqueGasolina(); // constructor por default
    void cargarTanque(double litros);
    void gastarGasolina(double litros);
    double getNivelGasolina();
    double getPorcentajeNivel();
};

#endif