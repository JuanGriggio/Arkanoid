#ifndef _MATRIXHANDLER_H_
#define _MATRIXHANDLER_H_

#include "globalVariables.h"
#include "structs.h"
#include "constants.h"
#include <Arduino.h>

#include <MaxMatrix.h>

void turnOnPixel(int x, int y);         // PRENDE EL PIXEL INDICADO, TRANSFORMANDOLO DE UNA MATRIZ DE 32x8 A UNA DE 16x16
void turnOffPixel(int x, int y);        // APAGA EL PIXEL INDICADO, TRANSFORMANDOLO DE UNA MATRIZ DE 32x8 A UNA DE 16x16
void displayPlayer();                   // MUESTRA EL JUGADOR SOLAMENTE SI SE MOVIO PARA PODER CONTRARRESTAR LA LENTITUD DE LAS MATRICES
void displayBall(ball * ball);          // MUESTRA A LA PELOTA CUANDO SE MUEVE
void displayBrokenBlock();              // APAGA EL BLOQUE QUE SE ROMPIO, SI ES QUE HUBO UN BLOQUE QUE SE ROMPIO
void initialDisplay(ball * ball);       // MUESTRA EL JUEGO EN SU ESTADO INICIAL, PARA SOLO DESPUES IR PRENDIENDO/APAGANDO LO QUE CAMBIA Y QUE ASI SEA MAS RAPIDO
void printCharStartingFromColumn(char c, int column);       // IMPRIME UN CHAR EN UNA MATRIZ, EMPEZANDO DESDE LA COLUMNA DADA (PARA IMPRIMIR EN LA MATRIZ QUE QUIERA)

#endif
