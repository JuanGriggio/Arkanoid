#include "matrixHandler.h"

void turnOnPixel(int x, int y) {        // PRENDE EL PIXEL INDICADO, TRANSFORMANDOLO DE UNA MATRIZ DE 32x8 A UNA DE 16x16
  if(y < 8)
    m.setDot(x, 7 - y, ON_INTENSITY);
  else if (y >= 8)
    m.setDot(x + 16, 15 - y, ON_INTENSITY);
}

void turnOffPixel(int x, int y) {       // APAGA EL PIXEL INDICADO, TRANSFORMANDOLO DE UNA MATRIZ DE 32x8 A UNA DE 16x16
  if(y < 8)
    m.setDot(x, 7 - y, OFF_INTENSITY);
  else if (y >= 8)
    m.setDot(x + 16, 15 - y, OFF_INTENSITY);
}

void displayPlayer() {                  // MUESTRA EL JUGADOR, SOLAMENTE SI SE MOVIO PARA PODER CONTRARRESTAR LA LENTITUD DE LAS MATRICES
    if(playerMoved == 0)                // SI NO SE MOVIO, NO HACE NADA
        return;

    if(playerMoved == -1) {                     // SI SE MOVIO A LA DERECHA, APAGA EL PIXEL EN DONDE EMPEZABA Y PRENDE EL PIXEL DE MAS A LA DERECHA DE DONDE ESTABA
        turnOnPixel(playerStartsAt, 0);
        turnOffPixel(playerStartsAt + 2, 0);
    } else if(playerMoved == 1) {               // SI SE MOVIO A LA IZQUIERDA, APAGA EL PIXEL EN DONDE TERMINABA Y PRENDE EL PIXEL DE MAS A LA IZQUIERDA DE DONDE ESTABA
        turnOnPixel(playerStartsAt + 1, 0);
        turnOffPixel(playerStartsAt - 1, 0);
    }
    playerMoved = 0;                      // E INDICA QUE NO SE MOVIO PARA QUE NO VUELVA A MODIFICAR LA PANTALLA
}

void displayBall(ball * ball) {                         // MUESTRA A LA PELOTA CUANDO SE MUEVE
    turnOnPixel(ball->pos.x, ball->pos.y);              // PRENDE DONDE ESTA AHORA
    turnOffPixel(ball->prevPos.x, ball->prevPos.y);     // Y APAGA DONDE ESTABA ANTES
}

void displayBrokenBlock() {         // APAGA EL BLOQUE QUE SE ROMPIO, SI ES QUE HUBO UN BLOQUE QUE SE ROMPIO
    if(brokenBlock == -1)           // SI VALE -1 NO SE ROMPIO NINGUN BLOQUE
        return;

    turnOffPixel(2 * brokenBlock, BLOCKSHEIGHT);            // SINO, APAGA LOS DOS PIXELES CORRESPONDIENTES AL BLOQUE QUE SE ROMPIO
    turnOffPixel(2 * brokenBlock + 1, BLOCKSHEIGHT);
    brokenBlock = -1;               // PONE QUE NINGUN BLOQUE SE ROMPIO DESPUES DEL QUE ACABA DE ROMPERSE
    blocksLeft--;                   // Y PONE QUE QUEDA UN BLOQUE MENOS
}

void initialDisplay(ball * ball) {          // MUESTRA EL JUEGO EN SU ESTADO INICIAL, PARA SOLO DESPUES IR PRENDIENDO/APAGANDO LO QUE CAMBIA Y QUE ASI SEA MAS RAPIDO
  for(int i = 0; i < FIELDSIZE; i++) {      // PRIMERO MUESTRA AL JUGADOR
      if(player[i] == 1) {
        turnOnPixel(i, 0);
        turnOnPixel(i + 1, 0);
        break;
      }
  }                          

  turnOnPixel(ball->pos.x,ball->pos.y);     // DESPUES MUESTRA A LA PELOTA. NO LLAMA A DISPLAYBALL PORQUE ASI ES MAS EFICIENTE (SOLO PARA EMPEZAR)

  for(int i = 0; i < FIELDSIZE / 2; i++) {  // Y POR ULTIMO PRENDE LOS BLOQUES
    if(blocks[i] == 1) {
        turnOnPixel(2 * i, BLOCKSHEIGHT);
        turnOnPixel(2 * i + 1, BLOCKSHEIGHT);
    }
  }
}

void printCharStartingFromColumn(char c, int column) {      // IMPRIME UN CHAR EN UNA MATRIZ, EMPEZANDO DESDE LA COLUMNA DADA (PARA IMPRIMIR EN LA MATRIZ QUE QUIERA)
    for(int i = column; i < column + 8; i++) {
        m.setColumn(i, font8x8_basic[c][column + 7 - i]);
    }
}