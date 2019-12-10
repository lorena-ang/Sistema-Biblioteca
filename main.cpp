#include <iostream>
#include <fstream>
#include "Reserva.h"
#include "Fecha.h"
#include "Material.h"
#include "Libro.h"
#include "Software.h"
#include "Disco.h"
using namespace std;

int main() {

  // Declaración de variables
  Material *ArrMat[20];
  Reserva ArrRes[50];
  int iIdMaterial, iDuracion, iNumPag, iIdCliente, iDD, iMM, iAA;
  string sTitulo, sAutor, sSistemaOper;
  char cTipo, cOpcion;
  Material *m1;

  // Abrir los archivos
  ifstream ifMat;
  ifstream ifRes;
  ifMat.open("Material.txt");
  ifRes.open("Reserva.txt");
  ofstream ofRes;

  // Guardar datos de Material.txt en ArrMat
  int iContMat = 0;
  while (!ifMat.eof())
  {
    ifMat >> iIdMaterial >> sTitulo >> cTipo;

    if (cTipo == 'L')
    {
      ifMat >> iNumPag >> sAutor;
      ArrMat[iContMat] = new Libro(iIdMaterial, sTitulo, iNumPag, sAutor);
    }
    else if (cTipo == 'D')
    {
      ifMat >> iDuracion;
      ArrMat[iContMat] = new Disco(iIdMaterial, sTitulo, iDuracion);
    }
    else if (cTipo == 'S')
    {
      ifMat >> sSistemaOper;
      ArrMat[iContMat] = new Software(iIdMaterial, sTitulo, sSistemaOper);
    }
    iContMat++;
  }

  // Guardar datos de Reserva.txt en ArrRes
  int iContRes = 0;
  while (!ifRes.eof())
  {
    ifRes >> iDD >> iMM >> iAA >> iIdMaterial >> iIdCliente;
    Fecha fechaReservacion(iDD, iMM, iAA);
    Reserva r1(iIdMaterial, iIdCliente, fechaReservacion);   
    ArrRes[iContRes] = r1;
    iContRes++;
  }

  int iRes = iContRes;

  // Cerrar los archivos de los que se leyó
  ifMat.close();
  ifRes.close();

  do {
    // Desplegar menu
    cout << "SISTEMA DE RESERVACIONES\n";
    cout << "a) Consultar la lista de materiales \nb) Consultar la lista de reservaciones \nc) Consultar las reservaciones de un material dado \nd) Consultar las reservaciones de una fecha dada \ne) Hacer una reservación \nf) Terminar\n";
    cout << "Selecciona una opción: ";
    cin >> cOpcion;

    switch (cOpcion)
    {
      case 'a':
        {
          cout << "\nLISTA DE MATERIALES\n\n";
          // Mostrar datos de cada material de ArrMat
          for (int i = 0; i < iContMat; i++)
          {
            ArrMat[i]->muestraDatos();
            cout << endl;
          }
        }
        break;

      case 'b':
        {
          cout << "\nLISTA DE RESERVACIONES\n";
          for (int i = 0; i < iContRes; i++)
          {
            bool bContinuar = true;
            cout << "\nFecha de inicio de reservación: " << ArrRes[i].getFechaReservacion();
            cout << "\nFecha de fin de reservación: ";
            for (int j = 0; j < iContMat && bContinuar; j++)
            {
              // Si existen reservaciones de un ID
              if (ArrRes[i].getIdMaterial() == ArrMat[j]->getIdMaterial())
              {
                m1 = ArrMat[j];
                bContinuar = false;
              }
            }
            cout << ArrRes[i].calculaFechaFinReserva(m1->cantidadDiasPrestamo());
            cout << "\nNombre del material: " << m1->getTitulo() << endl;
            cout << "ID del cliente: " << ArrRes[i].getIdCliente() << endl;
          }
          cout << endl;
        }
        break;

      case 'c':
        {
          bool bExiste = true;
          cout << "\nCONSULTA RESERVACIÓN POR ID\n";

          // Dejar de pedir ID hasta que se ingrese uno válido
          do
          {
            // Si ID no existe, notificarlo
            if (!bExiste)
            {
              cout << "Error, ingresa un ID válido.\n";
            }
            cout << "Ingresa el ID del material: ";
            cin >> iIdMaterial;

            bool bContinuar = true;
            bool bExiste = false;

            // Si existe material con ese ID
            for (int i = 0; i < iContMat && bContinuar; i++)
            {
              if (iIdMaterial == ArrMat[i]->getIdMaterial())
              {
                m1 = ArrMat[i];
                bExiste = true;
                bContinuar = false;
              }
            }
          } while (!bExiste);
          
          bExiste = false;

          // Si existen reservaciones con ese ID
          for (int i = 0; i < iContRes; i++)
          {
            if (iIdMaterial == ArrRes[i].getIdMaterial())
            {
              cout << "Título: " << m1->getTitulo() << endl;
              cout << "Fecha de inicio de reservación: " << ArrRes[i].getFechaReservacion();
              cout << "\nFecha de fin de reservación: " << ArrRes[i].calculaFechaFinReserva(m1->cantidadDiasPrestamo());
              cout << endl << endl;
              bExiste = true;
            }
          }
          
          // Si no existen reservaciones con ese ID
          if (!bExiste)
          {
            cout << "No hay reservaciones con ese ID.\n\n";
          }
        }
        break;

      case 'd':
        {
          Fecha f1;
          bool bExiste = false;
          cout << "\nCONSULTA RESERVACIÓN POR FECHA\n";
          // Revisar si la fecha es válida y sino pedir otra
          do
          {
            cin >> f1;
            if (f1.diasMes(f1.getMM()) == -1 || f1.diasMes(f1.getMM()) < f1.getDD() || f1.getDD() < 0 || f1.getAA() < 0)
            {
              cout << "Error, ingresa una fecha válida.\n";
            }
          } while (f1.diasMes(f1.getMM()) == -1 || f1.diasMes(f1.getMM()) < f1.getDD() || f1.getDD() < 0 || f1.getAA() < 0);
          cout << "Reservaciones del día " << f1;

          // Si existe material con ese ID
          for (int i = 0; i < iContRes; i++)
          {
            bool bContinuar = true;
            for (int j = 0; j < iContMat && bContinuar; j++)
            {
              if (ArrRes[i].getIdMaterial() == ArrMat[j]->getIdMaterial())
              {
                m1 = ArrMat[j];
                bContinuar = false;
              }
            }

            // Si hay material reservado en esa fecha
            if (f1 >= ArrRes[i].getFechaReservacion() && f1 <= ArrRes[i].calculaFechaFinReserva(m1->cantidadDiasPrestamo()))
            {
              cout << "\nTítulo: " << m1->getTitulo() << endl;
              cout << "ID del cliente: " << ArrRes[i].getIdCliente() << endl;
              bExiste = true;
            }
          }

          // Si no se encontraron reservaciones
          if (!bExiste)
          {
            cout << "\nNo se encontraron reservaciones en esa fecha.\n";
          }
          cout << endl;
        }
        break;
      
      case 'e':
        {
          Fecha f1;
          bool bExiste = true, bReservado = false;

          cout << "\nRESERVAR MATERIAL\n";
          cout << "ID del cliente: ";
          cin >> iIdCliente;

          // Dejar de pedir ID hasta que se ingrese uno válido
          do
          {
            // Si ID no existe, notificarlo
            if (!bExiste)
            {
              cout << "Error, ingresa un ID válido.\n";
            }
            cout << "ID del material: ";
            cin >> iIdMaterial;

            bool bContinuar = true;
            bExiste = false;

            // Si existe material con ese ID
            for (int i = 0; i < iContMat && bContinuar; i++)
            {
              if (iIdMaterial == ArrMat[i]->getIdMaterial())
              {
                m1 = ArrMat[i];
                bExiste = true;
                bContinuar = false;
              }
            }
          } while (!bExiste);

          // Revisar si la fecha es válida y sino pedir otra
          do
          {
            cin >> f1;
            if (f1.diasMes(f1.getMM()) == -1 || f1.diasMes(f1.getMM()) < f1.getDD() || f1.getDD() < 0 || f1.getAA() < 0)
            {
              cout << "Error, ingresa una fecha válida.\n";
            }
          } while (f1.diasMes(f1.getMM()) == -1 || f1.diasMes(f1.getMM()) < f1.getDD() || f1.getDD() < 0 || f1.getAA() < 0);

          // Si existe material con ese ID
          for (int i = 0; i < iContMat; i++)
          {
            // Si hay material reservado en esa fecha
            if (ArrRes[i].getIdMaterial() == iIdMaterial && f1 >= ArrRes[i].getFechaReservacion() && f1 <= ArrRes[i].calculaFechaFinReserva(m1->cantidadDiasPrestamo()))
            {
              cout << "Material ocupado de " << ArrRes[i].getFechaReservacion();
              cout << " a " << ArrRes[i].calculaFechaFinReserva(m1->cantidadDiasPrestamo());
              cout << ".\n\n";
              bReservado = true;
            }
          }

          // Si el material no está ocupado, guardarlo en arreglo de reservaciones
          if (!bReservado)
          {
            ArrRes[iContRes] = Reserva(iIdMaterial, iIdCliente, f1);
            iContRes++;
            cout << "Reserva exitosa.\n\n";
          }
        }
        break;

      case 'f':
        {
          // Abrir archivo y escribir datos
          ofRes.open("Reserva.txt", ios::app);
          for (int i = iRes; i < iContRes; i++)
          {
            Fecha f1 = ArrRes[i].getFechaReservacion();
            ofRes << "\n" << f1.getDD() << " " << f1.getMM() << " " << f1.getAA() << " " << ArrRes[i].getIdMaterial() << " " << ArrRes[i].getIdCliente();
          }

          // Cerrar el archivo en el que se escribió
          ofRes.close();

          cout << "¡Hasta luego!\n";
        }
        break;

      default:
        cout << "Error, ingresa una opción válida.\n\n";
        break;
    }
  } while (cOpcion != 'f');

  return 0;
}