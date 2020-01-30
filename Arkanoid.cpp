#include <MaxMatrix.h>

#include "constants.h"
#include "structs.h"

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

#include "Arkanoid.h"

void changeBallDir(ball * ball, int hor, int vert){     // MODIFICA LA DIRECCION DE LA PELOTA
    ball->dir.vertical = vert;
    ball->dir.horizontal = hor;
} 

void checkBallBump(ball * ball){     // CHEQUEA SI LA PELOTA CHOCA CON ALGO, YA SEA BORDES, BLOQUES O EL JUGADOR

    if(ball->pos.y == FIELDSIZE - 1) {                      // SI LA PELOTA LLEGA HASTA EL BORDE SUPERIOR
        changeBallDir(ball, ball->dir.horizontal, DOWN);    // REBOTA HACIA ABAJO Y MANTIENE DIR. HORIZONTAL

    }
    if(ball->pos.y == 0){                                   // SI LA PELOTA LLEGA HASTA EL BORDE INFERIOR
        gameOver = 1;                                       // PIERDE

    }
    if(ball->pos.x == FIELDSIZE - 1) {                      // SI LA PELOTA LLEGA HASTA EL BORDE DERECHO
        changeBallDir(ball,LEFT,ball->dir.vertical);        // REBOTA HACIA LA IZQUIERDA Y MANTIENE DIR. VERTICAL

    }
    if(ball->pos.x == 0) {                                  // SI LA PELOTA LLEGA HASTA EL BORDE IZQUIERDO
        changeBallDir(ball,RIGHT,ball->dir.vertical);       // REBOTA HACIA LA DERECHA Y MANTIENE DIR. VERTICAL

    }

    // CASOS PARTICULARES

    if(ball->pos.y == BLOCKSHEIGHT + 1 && ball->dir.vertical == DOWN) {
        if(blocks[ball->pos.x / 2] == 1) {
            changeBallDir(ball, ball->dir.horizontal, UP);
            blocks[(int) (ball->pos.x) / 2] = 0;
            brokenBlock = (int) (ball->pos.x) / 2;
            return;
        }
        if(ball->dir.horizontal == LEFT && blocks[ball->pos.x / 2 - 1] == 1 && ball->pos.x % 2 == 0) {
            changeBallDir(ball, RIGHT, UP);
            blocks[ball->pos.x / 2 - 1] = 0;
            brokenBlock = ball->pos.x / 2 - 1;
            return;
        }
        if(ball->dir.horizontal == RIGHT && blocks[ball->pos.x / 2 + 1] == 1 && ball->pos.x % 2 == 1) {
            changeBallDir(ball, LEFT, UP);
            blocks[ball->pos.x / 2 + 1] = 0;
            brokenBlock = ball->pos.x / 2 + 1;
            return;
        }
    }
    if(ball->pos.y == BLOCKSHEIGHT - 1 && ball->dir.vertical == UP) {
        if(blocks[ball->pos.x / 2] == 1) {
            changeBallDir(ball, ball->dir.horizontal, DOWN);
            blocks[(int) (ball->pos.x) / 2] = 0;
            brokenBlock = (int) (ball->pos.x) / 2;
            return;
        }
        if(ball->dir.horizontal == LEFT && blocks[ball->pos.x / 2 - 1] == 1 && ball->pos.x % 2 == 0) {
            changeBallDir(ball, RIGHT, DOWN);
            blocks[ball->pos.x / 2 - 1] = 0;
            brokenBlock = ball->pos.x / 2 - 1;
            return;
        }
        if(ball->dir.horizontal == RIGHT && blocks[ball->pos.x / 2 + 1] == 1 && ball->pos.x % 2 == 1) {
            changeBallDir(ball, LEFT, DOWN);
            blocks[ball->pos.x / 2 + 1] = 0;
            brokenBlock = ball->pos.x / 2 + 1;
            return;
        }
    }
    if(ball->pos.y == BLOCKSHEIGHT && ball->dir.horizontal == LEFT && blocks[ball->pos.x / 2 - 1] == 1 && ball->pos.x % 2 == 0) {
        changeBallDir(ball, RIGHT, ball->dir.vertical);
        blocks[ball->pos.x / 2 - 1] = 0;
        brokenBlock = ball->pos.x / 2 - 1;
        return;
    }
    if(ball->pos.y == BLOCKSHEIGHT && ball->dir.horizontal == RIGHT && blocks[ball->pos.x / 2 + 1] == 1 && ball->pos.x % 2 == 1) {
        changeBallDir(ball, LEFT, ball->dir.vertical);
        blocks[ball->pos.x / 2 + 1] = 0;
        brokenBlock = ball->pos.x / 2 + 1;
        return;
    }

    if(ball->pos.y == 1 && player[ball->pos.x] == 1) {
        changeBallDir(ball, ball->dir.horizontal, UP);
        return;
    }
    if(ball->pos.y == 1 && player[ball->pos.x] == 0 && player[ball->pos.x - 1] == 1 && ball->dir.horizontal == LEFT) {
        changeBallDir(ball, RIGHT, UP);
        return;
    }
    if(ball->pos.y == 1 && player[ball->pos.x] == 0 && player[ball->pos.x + 1] == 1 && ball->dir.horizontal == RIGHT) {
        changeBallDir(ball, LEFT, UP);
        return;
    }
}

void moveBall(ball * ball){         // SE EJECUTA CONSTANTEMENTE. MUEVE LA PELOTA ACORDE A SU VELOCIDAD Y SE FIJA SI TIENE QUE MODIFICAR SU DIRECCION
    delay(ball->speed);
    checkBallBump(ball);                // SE FIJA SI LA PELOTA REBOTA CON ALGO

    ball->prevPos.x = ball->pos.x;      //GUARDA LA POSICION ANTERIOR PARA PODER APAGAR LOS PIXELES RAPIDAMENTE CON LAS MATRICES
    ball->prevPos.y = ball->pos.y;

    ball->pos.x += ball->dir.horizontal;    // ACTUALIZA LA POSICION CON LA DIRECCION A LA QUE ESTA YENDO 
    ball->pos.y += ball->dir.vertical;
}

void movePlayerRight(){         // MUEVE EL JUGADOR A LA DERECHA
    int i;
    for(i = 0; i < FIELDSIZE; i++) {
        if (player[i] == 1 && i < FIELDSIZE - 2) {
            player[i] = 0;
            player[i + 2] = 1;
            playerStartsAt++;       // SU POSICION EMPIEZA UNA POSICION MAS A LA DERECHA
            playerMoved = 1;        // INDICA QUE HUBO UN MOVIMIENTO HACIA LA DERECHA
            Serial.println("MOVIO DERECHA");
            return;
        }
    }

}

void movePlayerLeft(){          // MUEVE EL JUGADOR A LA IZQUIERDA
  int i;
    for(i = 0; i < FIELDSIZE; i++){
        if(player[i+1] == 1 && player[i] == 0){
            player[i] = 1;
            player[i+2] = 0;
            playerStartsAt--;       // SU POSICION EMPIEZA UNA POSICION MAS A LA IZQUIERDA
            playerMoved = -1;       // INDICA QUE HUBO UN MOVIMIENTO HACIA LA IZQUIERDA
            Serial.println("MOVIO IZQUIERDA");
            return;
        }
    }

    
}

void increaseBallSpeed(ball * ball){        // AUMENTA LA VELOCIDAD DE LA PELOTA
    (ball->speed) -= 50;
}

void initializeGame(ball * ball) {      // INICIALIZA EL JUEGO ARKANOID
    int i = random(0, FIELDSIZE - 2);       // NUMERO AL AZAR PARA INICIALIZAR AL JUGADOR EN ALGUNA POSICION ALEATORIA. VA DE 0 HASTA FIELDSIZE - 2 PORQUE TIENE QUE DEJAR 1 PIXEL LIBRE PORQUE EL JUGADOR OCUPA 2 PIXELES
    player[i] = 1;
    player[i + 1] = 1;
    playerStartsAt = i;

    ball->prevPos.x = i;        // INICIALIZA LA PELOTA ARRIBA DEL JUGADOR
    ball->prevPos.y = 1;
    ball->pos.x = i;
    ball->pos.y = 1;

    ball->dir.vertical = UP;    // INICIALIZA LA DIRECCION VERTICAL HACIA ARRIBA
    i = random(0, 1);           // NUMERO ALEATORIO PARA INICIALIZAR LA DIRECCION HORIZONTAL
    if(i == 1)
        ball->dir.horizontal = RIGHT;
    else
        ball->dir.horizontal = LEFT;

    for(i = 0; i < FIELDSIZE/2; i++) {
        blocks[i] = 1;
    }

    ball->speed = 300;      // VELOCIDAD INICIAL
}
