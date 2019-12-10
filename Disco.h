#ifndef Disco_h
#define Disco_h

#include "Material.h"

class Disco : public Material 
{
  private:
    int iDuracion;

  public:
    Disco();
    Disco(int iIdMaterial, string sTitulo, int iDuracion);
    void setDuracion(int iDuracion);
    int getDuracion();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Disco::Disco() : Material()
{
  iDuracion = -1;
}

Disco::Disco(int iIdMaterial, string sTitulo, int iDuracion) : Material(iIdMaterial, sTitulo)
{
  this->iDuracion = iDuracion;
}

void Disco::setDuracion(int iDuracion)
{
  this->iDuracion = iDuracion;
}

int Disco::getDuracion()
{
  return iDuracion;
}

void Disco::muestraDatos()
{
  cout << "ID: " << iIdMaterial << endl;
  cout << "Tipo de material: Disco\n";
  cout << "Título: " << sTitulo << endl;
  cout << "Duración: " << iDuracion << endl;
}

int Disco::cantidadDiasPrestamo()
{
  return 3;
}

#endif