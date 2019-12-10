#ifndef Software_h
#define Software_h

#include "Material.h"

class Software : public Material
{
  private:
    string sSistemaOper;

  public:
    Software();
    Software(int iIdMaterial, string sTitulo, string sSistemaOper);
    void setSistemaOper(string sSistemaOper);
    string getSistemaOper();
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Software::Software() : Material()
{
  sSistemaOper = "";
}

Software::Software(int iIdMaterial, string sTitulo, string sSistemaOper) : Material(iIdMaterial, sTitulo)
{
  this->sSistemaOper = sSistemaOper;
}

void Software::setSistemaOper(string sSistemaOper)
{
  this->sSistemaOper = sSistemaOper;
}

string Software::getSistemaOper()
{
  return sSistemaOper;
}

void Software::muestraDatos()
{
  cout << "ID: " << iIdMaterial << endl;
  cout << "Tipo de material: Software\n";
  cout << "Título: " << sTitulo << endl;
  cout << "Sistema operativo: " << sSistemaOper << endl;
}

int Software::cantidadDiasPrestamo()
{
  return 1;
}

#endif