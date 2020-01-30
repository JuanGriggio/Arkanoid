#ifndef _SERIALCOMMUNICATOR_H_
#define _SERIALCOMMUNICATOR_H_

#include "constants.h"
#include "globalVariables.h"
#include "structs.h"
#include "timeHandler.h"
#include "parameterModifier.h"
#include <Arduino.h>


void printEndGame();                    // IMPRIME COSAS AL TERMINAR EL JUEGO
int readTwoDigitIntFromSerial();        // LEE POR EL PUERTO SERIE UN ENTERO DE DOS DIGITOS, LO DEVUELVE COMO ENTERO Y VACIA LO QUE SOBRA DEL SERIAL
char readCharFromSerial();              // FUNCION PARA LEER UN CHAR POR EL PUERTO SERIE Y VACIAR EL RESTO. UTIL PARA INGRESAR OPCIONES
void shellInteraction();                // INTERACCION CON LA SHELL DEL YOCTO LINUX
void interrupt();                       // SE EJECUTA AL SER INTERRUMPIDO EL JUEGO. MANEJA LAS OPCIONES


#endif
