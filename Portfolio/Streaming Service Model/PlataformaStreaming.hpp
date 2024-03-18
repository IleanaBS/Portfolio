/*
Jocelyn Ileana Balderas Sánchez
*/

#ifndef PLATAFORMASTREAMING_HPP
#define PLATAFORMASTREAMING_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Pelicula.hpp"
#include "Serie.hpp"
#include "Video.hpp"

using namespace std;

class PlataformaStreaming
{
    private:
    vector<Serie> Series;
    vector<Pelicula> Peliculas;
    string Compania;
    
    public:
    PlataformaStreaming();
    string getCompania();
    void setCompania(string);
    void iniciar();
    void leerArchivo();
    void resumen();
    void imprimirGenero(string gen);
    void mostrar_apartir_cal(double rat);
    void mostrarEpisodios_Serie_Calificacion(string nom, double rat);
    void mostrarPelicula_Calificacion(double rat);
    void mostrarPeliculas();
    void mostrarSeries();
    void mostrarEpsSerie(string nombreSerie);
    void calificarVideoEsp(string nom, double rat);
    void ultiMensaje();
};

#endif