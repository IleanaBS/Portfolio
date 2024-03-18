#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "PlataformaStreaming.hpp"
#include <string>
using namespace std;

class Usuario /*: public PlataformaStreaming*/
{
private:
    int idU;
    string nombreU;

public:
    Usuario();
    Usuario(int, string);
    void setIdU(int);
    int getIdU();
    void setNombreU(string);
    string getNombreU();
    // string toString();
};
#endif