/*
Jocelyn Ileana Balderas Sánchez
*/

#include "Episodio.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Episodio::Episodio(int id, string tit, string tip, int dur, string gen, double rat, string nomEp, int temp) : Video{id, tit, tip, dur, gen, rat}, nomEpisodio{nomEp}, temporada{temp} {}
{
}

vector<string> Episodio::obtenerGeneros()
{
    stringstream stream(getGenero());
    vector<string> genero;
    string primerGenero;
    while (stream.peek() != EOF)
    {
        getline(stream, primerGenero, ',');
        genero.push_back(primerGenero);
    }
    return genero;
}

string Episodio::getNomEpisodio()
{
    return nomEpisodio;
}

int Episodio::getTemporada()
{
    return temporada;
}

void Episodio::calificarVideo(double nuevoRating)
{
    Video::calificarVideo(nuevoRating);
    cout << "\nEl episodio: " << nomEpisodio << " de la serie " << Video::getTitle() << " cambio de calificacion a: " << Video::getRating() << "\n" << endl;
}

double Episodio::getRating()
{
    int rat;
    cout << "Ingrese una calificacion para el video:";
    cin >> rat;
    rating = rat;
}

// virtuales
void Episodio::calificarVideo(double nuevoRating)
{
    double anterior;
    anterior = rating;
   
}
void Episodio::display()
{
    cout << "INFORMACION VIDEO" << endl;
    cout << "ID: " << Video::id;
    cout << "Titulo: " << Video::titulo << endl;
    cout << "Tipo: " << Video::tipo << endl;
    cout << "Duracion " << Video::duracion << " minutos" << endl;
    cout << "Genero: " << Video::genero << endl;
    cout << "Nombre del Episodio: " << nomEpisodio << endl;
    cout << "Temporada:  " << temporada << endl;
}