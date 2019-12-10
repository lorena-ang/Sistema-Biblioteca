#ifndef Libro_h
#define Libro_h

#include "Material.h"

class Libro : public Material
{
  private:
    int iNumPag;
    string sAutor;

  public:
    Libro();
    Libro(int iIdMaterial, string sTitulo, int iNumPag, string sAutor);
    void setNumPag(int iNumPag);
    int getNumPag();
    void setAutor(string sAutor);
    string getAutor();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Libro::Libro() : Material()
{
  iNumPag = -1;
  sAutor = "";
}

Libro::Libro(int iIdMaterial, string sTitulo, int iNumPag, string sAutor) : Material(iIdMaterial, sTitulo)
{
  this->iNumPag = iNumPag;
  this->sAutor = sAutor;
}

void Libro::setNumPag(int iNumPag)
{
  this->iNumPag = iNumPag;
}

int Libro::getNumPag()
{
  return iNumPag;
}

void Libro::setAutor(string sAutor)
{
  this->sAutor = sAutor;
}

string Libro::getAutor()
{
  return sAutor;
}

void Libro::muestraDatos()
{
  cout << "ID: " << iIdMaterial << endl;
  cout << "Tipo de material: Libro\n";
  cout << "Título: " << sTitulo << endl;
  cout << "Autor: " << sAutor << endl;
  cout << "Número de páginas: " << iNumPag << endl;
}

int Libro::cantidadDiasPrestamo()
{
  return 10;
}

#endif