#ifndef Fecha_h
#define Fecha_h

#include <iostream>
#include <string>
using namespace std;

class Fecha 
{
  private:
    int iDD;
    int iMM;
    int iAA;
    string nombreMes();
    bool esBisiesto();

  public:
    Fecha();
    Fecha(int iDD, int iMM, int iAA);
    void setDD(int iDD);
    int getDD();
    void setMM(int iMM);
    int getMM();
    void setAA(int iAA);
    int getAA();
    void setFecha(int iDD, int iMM, int iAA);
    int diasMes(int iMM);
    Fecha operator+(int iCantDias);
    bool operator>(Fecha f1);
    bool operator>=(Fecha f1);
    bool operator<(Fecha f1);
    bool operator<=(Fecha f1);
    bool operator==(Fecha f1);
    friend void operator>>(istream &is, Fecha &f1);
    friend void operator<<(ostream &os, Fecha f1);
};

Fecha::Fecha()
{
  iDD = -1;
  iMM = -1;
  iAA = -1;
}

Fecha::Fecha(int iDD, int iMM, int iAA)
{
  this->iDD = iDD;
  this->iMM = iMM;
  this->iAA = iAA;
}

void Fecha::setDD(int iDD)
{
  this->iDD = iDD;
}

int Fecha::getDD()
{
  return iDD;
}

void Fecha::setMM(int iMM)
{
  this->iMM = iMM;
}

int Fecha::getMM()
{
  return iMM;
}

void Fecha::setAA(int iAA)
{
  this->iAA = iAA;
}

int Fecha::getAA()
{
  return iAA;
}

void Fecha::setFecha(int iDD, int iMM, int iAA)
{
  this->iDD = iDD;
  this->iMM = iMM;
  this->iAA = iAA;
}

Fecha Fecha::operator+(int iCantDias)
{
  int iDiasMax, iDiasNuevos;
  int iA = iAA, iM = iMM, iD = iDD;
  Fecha f1;

  iDiasMax = f1.diasMes(iM);

  if (iCantDias + iD > iDiasMax)
  {
    iDiasNuevos = iCantDias + iD;
    iDiasNuevos -= iDiasMax;
    iD = iDiasNuevos;
    if (iM != 12)
    {
      iM++;
    }
    else
    {
      iM = 1;
      iA++;
    }
  }
  else
  {
    iD += iCantDias;
  }
  
  f1.setDD(iD);
  f1.setMM(iM);
  f1.setAA(iA);

  return f1;
}

bool Fecha::operator>=(Fecha f1)
{
  if (iAA > f1.iAA)
  {
    return true;
  }
  else if (iAA == f1.iAA)
  {
    if (iMM > f1.iMM)
    {
      return true;
    }
    else if (iMM == f1.iMM)
    {
      if (iDD > f1.iDD)
      {
        return true;
      }
      else if (iDD == f1.iDD)
      {
        return true;
      }
    }
  }
  return false;
}


bool Fecha::operator<=(Fecha f1)
{
  if (iAA < f1.iAA)
  {
    return true;
  }
  else if (iAA == f1.iAA)
  {
    if (iMM < f1.iMM)
    {
      return true;
    }
    else if (iMM == f1.iMM)
    {
      if (iDD < f1.iDD)
      {
        return true;
      }
      else if (iDD == f1.iDD)
      {
        return true;
      }
    }
  }
  return false;
}

bool Fecha::operator>(Fecha f1)
{
  if ((iAA > f1.iAA) || (iAA == f1.iAA && iMM > f1.iMM) || (iAA == f1.iAA && iMM == f1.iMM && iDD > f1.iDD))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Fecha::operator<(Fecha f1)
{
  if ((iAA < f1.iAA) || (iAA == f1.iAA && iMM < f1.iMM) || (iAA == f1.iAA && iMM == f1.iMM && iDD < f1.iDD))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Fecha::operator==(Fecha f1)
{
  if (iAA == f1.iAA && iMM == f1.iMM && iDD == f1.iDD)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void operator>>(istream &is, Fecha &f1)
{
  cout << "Día: ";
  is >> f1.iDD;
  cout << "Mes: ";
  is >> f1.iMM;
  cout << "Año: ";
  is >> f1.iAA;
}

void operator<<(ostream &os, Fecha f1)
{
  os << f1.getDD() << "/" << f1.nombreMes() << "/" << f1.getAA();
}

string Fecha::nombreMes()
{
  switch (iMM)
  {
    case 1:
      return "Ene";
      break;
    case 2:
      return "Feb";
      break;
    case 3:
      return "Mar";
      break;
    case 4:
      return "Abr";
      break;
    case 5:
      return "May";
      break;
    case 6:
      return "Jun";
      break;
    case 7:
      return "Jul";
      break;
    case 8:
      return "Ago";
      break;
    case 9:
      return "Sep";
      break;
    case 10:
      return "Oct";
      break;
    case 11:
      return "Nov";
      break;
    case 12:
      return "Dic";
      break;
    default:
      return "inválido";
      break;
  }
}

bool Fecha::esBisiesto()
{
  if (iAA % 4 == 0 && (iAA % 100 != 0 || iAA % 400 == 0))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int Fecha::diasMes(int iMM)
{
  Fecha f1(iDD, iMM, iAA);
  switch (iMM)
  {
    case 1:
      return 31;
      break;
    case 2:
      if (f1.esBisiesto())
      {
        return 29;
      }
      else
      {
        return 28;
      }
      break;
    case 3:
      return 31;
      break;
    case 4:
      return 30;
      break;
    case 5:
      return 31;
      break;
    case 6:
      return 30;
      break;
    case 7:
      return 31;
      break;
    case 8:
      return 31;
      break;
    case 9:
      return 30;
      break;
    case 10:
      return 31;
      break;
    case 11:
      return 30;
      break;
    case 12:
      return 31;
      break;
    default:
      return -1;
      break;
  }
}

#endif