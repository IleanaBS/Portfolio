/*
Jocelyn Ileana Balderas Sánchez
*/

#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string>
#include <iostream>
using namespace std;

class Video { //: public Catalogo  {
private:
  int id;
  string titulo;
  string tipo;
  int duracion;
  string genero;
  double rating;

public:
  Video();
  Video(int, string, string, int, string, double);
  void setId(int);
  int getId();
  void setTitulo(string);
  string getTitulo();
  void setTipo(string);
  string getTipo();
  void setDuracion(int);
  int getDuracion();
  void setGenero(string);
  string getGenero();
  //void setRating(double);
  double getRating();
  void pausar();
  void reproducir();
  void adelantar();

  //virtuales
  virtual void display();
  virtual void calificarVideo(double nuevoRating);
  bool operator>= (double rat);


  /*private: 
  string titulo;

  public:
  Video();
  Video(string);
  void MostrarInformacion();
  */
};
#endif 