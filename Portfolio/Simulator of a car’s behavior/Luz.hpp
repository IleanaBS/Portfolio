/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Definición de la clase Luces

*/

#include <iostream>
#include <string>

using namespace std;

#ifndef LUZ_HPP
#define LUZ_HPP

class Luz {
    private:
        //string lugar;
        bool estadoLuces;

    public:
        Luz(); // constructor por default
        void apagarLuces();
        void prenderLuces();
        bool getEstadoLuces();

};

#endif 