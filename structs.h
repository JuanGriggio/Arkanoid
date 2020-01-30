#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef struct{     // POSICION DE LA PELOTA EN EL CAMPO DE JUEGO
    int x,y;
} position;

typedef struct{     // DIRECCION DE LA PELOTA
    int vertical, horizontal;
} direction;

typedef struct {
    position pos;       // POSICION ACTUAL
    position prevPos;   // POSICION ANTERIOR, USADA PARA PODER APAGAR SOLO UN PIXEL Y NO TENER QUE REFRESCAR TODA LA PANTALLA CADA VEZ QUE SE MUEVE LA PELOTA
    direction dir;
    int speed;  
}ball;

#endif