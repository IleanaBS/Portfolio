/*
Jocelyn Ileana Balderas Sánchez 
*/

#ifndef SERIE_HPP
#define SERIE_HPP

#include <iostream>
#include <string>

using namespace std;

class Serie 
{
    private:
        string title;
        int numTemporada;
        //episodio capitulo;
    
    public:
        //Serie();
        Serie(string, int);
        string getTitle();
        void setTitle(string);
        int getNumTemporada();
        void setNumTemporada(int);

};

#endif