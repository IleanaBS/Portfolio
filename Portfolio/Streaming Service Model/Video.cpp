/*
Jocelyn Ileana Balderas Sánchez
*/

#include "Video.hpp"

Video::Video(int id, string tit, string tip, int dur, string gen, double rat){
	id = 0;
	titulo = tit;
    tipo = tip;
	duracion = dur;
	genero = gen;
	rating = rat;
}

bool Video::operator>=(double rat){
    bool resultado;
    resultado = rating >= rat;
    return resultado;
}


void Video::reproducir(){
	cout << "El video se esta reproduciendo con calidad estandar" << endl;
}

void Video::pausar(){
	cout << "El video se ha pausado" << endl;
}

void Video::adelantar(){
	cout << "El video se ha adelantado" << endl;
}

double Video::getRating(){
	int rat;
	cout << "Ingrese una calificacion para el video:"; cin >> rat;
	rating = rat;
}

//virtuales
void Video::display(){
}

void Video::calificarVideo(double nuevoRating){
    double anterior;
    anterior = rating;
    rating = (nuevoRating + anterior)/2 ;
}


/*Video::Video(){}
Video::Video(string nombre) : titulo{nombre}{}
void Video::MostrarInformacion(){
	cout<<"el titulo es: "<<titulo<<endl;
}
*/