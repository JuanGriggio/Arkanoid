#include <MaxMatrix.h>

#ifndef _GLOBALVARIABLES_H_
#define _GLOBALVARIABLES_H_

#include "constants.h"
#include "structs.h"
#include <MaxMatrix.h>

extern MaxMatrix m;      // PARA CONTROLAR LAS MATRICES

extern char blocks[FIELDSIZE/2];           // LOS BLOQUES A ROMPER. ES FIELDSIZE / 2 PORQUE CADA BLOQUE OCUPA 2 PIXELES
extern char player[FIELDSIZE];       // EL JUGADOR, VECTOR DE FIELDSIZE POSICIONES QUE COMIENZA EN 0 PORQUE DESPUES SE INICIALIZA AL AZAR
extern int playerStartsAt;                 // INDICA RAPIDAMENTE DONDE ESTA EL JUGADOR PARA PODER MOSTRARLO RAPIDAMENTE POR LAS MATRICES
extern int gameOver;                   // INDICA SI SE SIGUE JUGANDO O SE PERDIO
extern int brokenBlock;               // -1 SI NO SE ROMPIO NINGUN BLOQUE, SINO INDICA EL BLOQUE QUE SE ROMPIO, ES PARA MOSTRAR MAS RAPIDO POR LAS MATRICES
extern int playerMoved;                // 0 SI NO SE MOVIO, -1 SI SE MOVIO A LA IZQ, 1 SI SE MOVIO A LA DER, ES PARA MOSTRAR MAS RAPIDO POR LAS MATRICES
extern ball b;                             // LA PELOTA DEL JUEGO 
extern unsigned long startTime, endTime;   // PARA MEDIR EL TIEMPO DE JUEGO
extern unsigned long currentTime, lastTime;    // PARA MEDIR EL INTERVALO DE 15 SEGUNDOS POR EL CUAL SE INCREMENTA LA VELOCIDAD DE LA PELOTA
extern int hasToPrint;                 // PARA VER SI HAY QUE IMPRIMIR LA INFO AL TERMINAR EL JUEGO
extern int blocksLeft;     // CANTIDAD DE BLOQUES QUE QUEDAN
extern unsigned long pauseTime;            // PARA DESCONTAR EL TIEMPO AL INTERACTUAR CON LA TERMINAL / VIENDO LA HORA / ETC
extern char font8x8_basic[129][8];

#endif
