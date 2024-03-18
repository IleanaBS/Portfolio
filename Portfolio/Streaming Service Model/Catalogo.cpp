/*
Andrea Doce Murillo
Jocelyn Ileana Balderas Sánchez 
*/

#include "Catalogo.hpp"
#include <iostream>
#include <string>

using namespace std;
Catalogo::Catalogo() : PlataformaStreaming(), categoria{""} {}
Catalogo::Catalogo(string cat) : PlataformaStreaming(), categoria{cat} {}

string Catalogo::toString()
{
    return "Catalogo (" to_string(cat) + " )";
}