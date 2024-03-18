/*
Autor: Jocelyn Ileana Balderas Sánchez
Matrícula: A01798528

Proyecto Integrador TC1033
*/

#include <iostream>
#include "Automobil.hpp"
#include "Automobil.cpp"
#include "Llanta.hpp"
#include "Llanta.cpp"
#include "Luz.hpp"
#include "Luz.cpp"
#include "Tablero.hpp"
#include "Tablero.cpp"
#include "TanqueGasolina.hpp"
#include "TanqueGasolina.cpp"

using namespace std;

void menuPrincipal()
{
    cout << "\n---------------- MENU ----------------" << endl;
    cout << "\nSelecciona la opcion deseada: " << endl;
    cout << "\n1) Prender/Apagar el auto" << endl;
    cout << "2) Acelerar" << endl;
    cout << "3) Frenar" << endl;
    cout << "4) Prender luces" << endl;
    cout << "5) Apagar luces" << endl;
    cout << "6) Cargar gasolina" << endl;
    cout << "7) Inflar llanta" << endl;
    cout << "8) Desinflar llanta" << endl;
    cout << "9) Mostrar tablero" << endl;
    cout << "10) Salir" << endl;
    cout << "\n----------------------------------------" << endl;
}

int main()
{
    Automobil automobil;
    int x;
    double litros;
    int llanta;
    double presion;

    cout << "\nAutor: Jocelyn Ileana Balderas Sanchez" << endl;
    cout << "Matricula: A01798528" << endl;
    cout << "Carrera: ITD" << endl;

    do
    {
        menuPrincipal();
        cin >> x;

        switch (x)
        {
        case 1:
            automobil.prenderApagar();
            automobil.mostrarTablero();
            break;
        case 2:
            automobil.acelerar();
            automobil.mostrarTablero();
            break;
        case 3:
            automobil.frenar();
            automobil.mostrarTablero();
            break;
        case 4:
            automobil.prenderLuces();
            automobil.mostrarTablero();
            break;
        case 5:
            automobil.apagarLuces();
            automobil.mostrarTablero();
            break;
        case 6:
            cout << "Ingrese la cantidad de litros a cargar: " << endl;
            cin >> litros;
            automobil.cargarGasolina(litros);
            automobil.mostrarTablero();
            break;
        case 7:
            do
            {
                cout << "Escribe el numero de llanta que deseas inflar: " << endl;
                cin >> llanta;
                if (llanta >= 1 && llanta <= 4)
                {
                    cout << "Escribe cuantos psi de presion se inflara la llanta: " << endl;
                    cin >> presion;
                    automobil.inflarLlanta(llanta - 1, presion + 33.0);
                }
                else
                {
                    cout << "Numero de llanta invalido. Ingresa un numero del 1 al 4" << endl;
                }
            } while (llanta < 1 && llanta > 4);
            break;
        case 8:
            do
            {
                cout << "Escribe el numero de llanta que deseas desinflar: " << endl;
                cin >> llanta;
                if (llanta >= 1 && llanta <= 4)
                {
                    cout << "Escribe cuantos psi de presion se desinflara la llanta: " << endl;
                    cin >> presion;
                    automobil.desinflarLlanta(llanta - 1, -presion + 33.0);
                }
                else
                {
                    cout << "Numero de llanta invalido. Ingresa un numero del 1 al 4" << endl;
                }
            } while (llanta < 1 && llanta > 4);
            break;
        case 9:
            automobil.mostrarTablero();
            break;
        case 10:
            cout << "Adios! Vuelve pronto" << endl;
            break;
        default:
            cout << "Opcion invalida. Ingresa un numero del 1 al 10" << endl;
            break;
        }
        cout << endl;
    } while (x != 10);
    return 0;
}