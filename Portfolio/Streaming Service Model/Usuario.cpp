/*
Andrea Doce Murillo
Jocelyn Ileana Balderas Sánchez
*/

#include "Usuario.hpp"
#include <iostream>
#include <string>

using namespace std;

Usuario::Usuario(): idU{0}, nombreU{""}{}

Usuario::Usuario(int idU, string nomU){
	idU = 0;
	nombreU = nomU;
}

int Usuario::getNombreU(){
    cout << "Ingresa tu nombre" << endl;
    return nombreU
}

int Usuario::getIdU(){
    cout << "Ingresa tu id para identificarte como usuario" << endl;
    return idU
}

void Usuario::setNombreU(){
    cout << "Bienvenido" << nombreU << endl;
}

void Usuario::setIdU(){
	cout << "Tu id de usuario es" << idU << endl;;
}


