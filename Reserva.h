#ifndef Reserva_h
#define Reserva_h

#include "Fecha.h"

class Reserva 
{
  private:
    int iIdMaterial;
    int iIdCliente;
    Fecha fechaReservacion;

  public:
    Reserva();
    Reserva(int iIdMaterial, int iIdCliente, Fecha fechaReservacion);
    void setIdMaterial(int iIdMaterial);
    int getIdMaterial();
    void setIdCliente(int iIdCliente);
    int getIdCliente();
    void setFechaReservacion(Fecha fechaReservacion);
    Fecha getFechaReservacion();
    Fecha calculaFechaFinReserva(int iCantDias);
};

Reserva::Reserva()
{
  Fecha f1;
  iIdMaterial = -1;
  iIdCliente = -1;
  fechaReservacion = f1;
}

Reserva::Reserva(int iIdMaterial, int iIdCliente, Fecha fechaReservacion)
{
  this->iIdMaterial = iIdMaterial;
  this->iIdCliente = iIdCliente;
  this->fechaReservacion = fechaReservacion;
}

void Reserva::setIdMaterial(int iIdMaterial)
{
  this->iIdMaterial = iIdMaterial;
}

int Reserva::getIdMaterial()
{
  return iIdMaterial;
}

void Reserva::setIdCliente(int iIdCliente)
{
  this->iIdCliente = iIdCliente;
}

int Reserva::getIdCliente()
{
  return iIdCliente;
}

void Reserva::setFechaReservacion(Fecha fechaReservacion)
{
  this->fechaReservacion = fechaReservacion;
}

Fecha Reserva::getFechaReservacion()
{
  return fechaReservacion;
}

Fecha Reserva::calculaFechaFinReserva(int iCantDias)
{
  return fechaReservacion + iCantDias;
}

#endif