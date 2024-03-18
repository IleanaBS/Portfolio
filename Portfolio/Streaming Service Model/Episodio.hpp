/*
Jocelyn Ileana Balderas Sánchez
*/

#ifndef EPISODIO_HPP
#define EPISODIO_HPP

#include "Video.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Episodio: public Video
{
    private:
        int temporada;
        string nomEpisodio;

    public:
        //Episodio();
        Episodio(int id, string tit, string tip, int dur, string gen, double rat, string nomEp, int temp)
        vector<string> obtenerGenero();
        int getTemporada();
        void setTemporada(int);
        string getNomEpisodio();
        void setNomEpisodio(string);

        //virtuales
        void display(int i);
        void calificarVideo(double nuevoRating);
};

#endif