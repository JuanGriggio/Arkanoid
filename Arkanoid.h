#ifndef _GLOBALVARIABLES_H_
#define _GLOBALVARIABLES_H_

#include "globalVariables.h"
#include "structs.h"
#include "constants.h"
#include "matrixHandler.h"
#include "serialCommunicator.h"
#include <Arduino.h>

void changeBallDir(ball * ball, int hor, int vert);     // MODIFICA LA DIRECCION DE LA PELOTA
void checkBallBump(ball* ball);                         // CHEQUEA SI LA PELOTA CHOCA CON ALGO, YA SEA BORDES, BLOQUES O EL JUGADOR
void moveBall(ball * ball);                             // SE EJECUTA CONSTANTEMENTE. MUEVE LA PELOTA ACORDE A SU VELOCIDAD Y SE FIJA SI TIENE QUE MODIFICAR SU DIRECCION
void movePlayerRight();                                 // MUEVE EL JUGADOR A LA DERECHA
void movePlayerLeft();                                  // MUEVE EL JUGADOR A LA IZQUIERDA
void increaseBallSpeed(ball * ball);                    // AUMENTA LA VELOCIDAD DE LA PELOTA
void initializeGame(ball * ball);                       // INICIALIZA EL JUEGO ARKANOID


#endif
