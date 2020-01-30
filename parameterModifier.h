#ifndef _PARAMETERMODIFIER_H_
#define _PARAMETERMODIFIER_H_

#include "globalVariables.h"
#include "constants.h"
#include "structs.h"
#include "Arkanoid.h"
#include "matrixHandler.h"
#include "serialCommunicator.h"

#include <Arduino.h>

#include <MaxMatrix.h>

void modifyPlayerPosition();                    // FUNCION QUE ES LLAMADA AL QUERER MODIFICAR LA POSICION DEL JUGADOR
void modifyBallPosition(int i, ball * ball);    // MODIFICA LA POSICION DE LA PELOTA. SI RECIBE COMO PRIMER PARAMETRO 2, MODIFICA LA COORDENADA X, SI RECIBE 3, MODIFICA LA COORDENADA Y
void destroyBlock();                            // DESTRUYE UN BLOQUE A ELECCION    
void createBlock();                             // CREA UN BLOQUE A ELECCION
void destroyAllBlocks();                        // DESTRUYE TODOS LOS BLOQUES
void createAllBlocks();                         // CREA TODOS LOS BLOQUES
void modifyTime();                              // MODIFICA EL CONTADOR TIEMPO JUGADO HASTA EL MOMENTO
void modifyParameters();                        // FUNCION LLAMADA CUANDO EN LA INTERRUPCION SE ELIGE LA OPCION DE MODIFICAR PARAMETROS DEL JUEGO

#endif
