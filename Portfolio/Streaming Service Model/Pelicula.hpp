/*
Jocelyn Ileana Balderas Sánchez
*/

#ifndef PELICULA_HPP
#define PELICULA_HPP

#include "Video.hpp"
#include <iostream>
#include <string>

using namespace std;

class Pelicula : public Video
{
    private:
        int ano;
        string director;

    public:
        //Pelicula();
        Pelicula(int id, string titulo, string tipo, int duracion, string genero, double rating, int ano, string director);
        Pelicula();
        int getAno();
        void setAno(int);
        string getDirector();
        void setDirector(string);

        //virtuales
        void display();
        void calificarVideo(double nuevoRating);
};

#endif