#ifndef Material_h
#define Material_h

#include <iostream>
#include <string>
using namespace std;

class Material
{
  protected:
    int iIdMaterial;
    string sTitulo;

  public:
    Material();
    Material(int iIdMaterial, string sTitulo);
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
    void setIdMaterial(int iIdMaterial);
    int getIdMaterial();
    void setTitulo(string sTitulo);
    string getTitulo();
};

Material::Material()
{
  iIdMaterial = -1;
  sTitulo = "";
}

Material::Material(int iIdMaterial, string sTitulo)
{
  this->iIdMaterial = iIdMaterial;
  this->sTitulo = sTitulo;
}

void Material::setIdMaterial(int iIdMaterial)
{
  this->iIdMaterial = iIdMaterial;
}

int Material::getIdMaterial()
{
  return iIdMaterial;
}

void Material::setTitulo(string sTitulo)
{
  this->sTitulo = sTitulo;
}

string Material::getTitulo()
{
  return sTitulo;
}

#endif