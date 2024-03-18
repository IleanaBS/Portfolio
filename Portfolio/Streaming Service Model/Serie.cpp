/* 
Andrea Doce Murillo
Jocelyn Ileana Balderas Sánchez 
*/

#include "Serie.hpp"
#include <iostream>
#include <string>

using namespace std;

//Serie::Serie(): title{""}, numTemporada{""}{}

Serie::Serie(string titl, int numTemp){
	title = titl;
	numTemporada = numTemp;
}

void Serie::setTitle(){
    cout << "El título de la serie es" << title << endl;
}

void Serie::setNumTemporada(){
	cout << "El número de temporada es" << numTemporada << endl;;
}