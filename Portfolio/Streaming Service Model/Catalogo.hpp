/*
Jocelyn Ileana Balderas Sánchez
*/

#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <iostream>
#include <string>
using namespace std;

class Catalogo
{
private:
    string categoria;

public:
    Catalogo();
    Catalogo(string);
    void setCategoria(string);
    string getCategoria();
};
#endif