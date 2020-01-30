#include "parameterModifier.h"

void modifyPlayerPosition() {       // FUNCION QUE ES LLAMADA AL QUERER MODIFICAR LA POSICION DEL JUGADOR
    Serial.println("Ingrese la nueva ubicacion del jugador CON DOS DIGITOS (de 00 a 14, ej.: si ingresa 00 ocupara las posiciones 0 y 1)");
    Serial.println();

    int newPos = readTwoDigitIntFromSerial();      // TRANSFORMA LOS CHARS EN EL INT QUE ES LA NUEVA POSICION DEL JUGADOR

    if(newPos < 0 || newPos > FIELDSIZE - 2) {          // SE FIJA SI LA POSICION ES VALIDA O NO
        Serial.println("Numero ingresado no valido! No se modificara nada");
        Serial.println();
    } else {
        Serial.print("Moviendo jugador a la posicion ");
        Serial.println(newPos);
        Serial.println();

        playerStartsAt = newPos;        // INDICA QUE EL JUGADOR COMIENZA EN LA NUEVA POSICION

        for(int i = 0; i < FIELDSIZE; i++) {
            player[i] = 0;              // PONE A TODO EL JUGADOR EN 0
            turnOffPixel(i, 0);         // APAGA LOS PIXELES QUE MOSTRABAN AL JUGADOR
        }
        player[newPos] = 1;             // PONE EL JUGADOR EN DONDE CORRESPONDE
        player[newPos + 1] = 1;

        turnOnPixel(newPos, 0);         // Y ENCIENDE LOS PIXELES DE LA NUEVA POSICION DEL JUGADOR
        turnOnPixel(newPos + 1, 0);
    }


}

void modifyBallPosition(int i, ball * ball) {           // MODIFICA LA POSICION DE LA PELOTA. SI RECIBE COMO PRIMER PARAMETRO 2, MODIFICA LA COORDENADA X, SI RECIBE 3, MODIFICA LA COORDENADA Y
    Serial.print("Ingrese la nueva coordenada CON DOS DIGITOS ");
    Serial.print(i == 2 ? "X" : "Y");
    Serial.println(" de la pelota. En X no tiene restricciones, pero en Y no puede ser 0 ni estar por encima de los bloques.");
    Serial.println();

    int newCoord = readTwoDigitIntFromSerial();         // LLAMA A FUNCION AUXILIAR QUE RETORNA LA NUEVA COORDENADA LEIDA DESDE EL PUERTO SERIE

    if(i == 2) {        //  SI QUIERO MODIFICAR EN X, SOLO TENGO LA RESTRICCION DEL TAMAÑO DE LA CANCHA
        if(newCoord < 0 || newCoord > FIELDSIZE - 1) {
            Serial.println("Coordenada X invalida");
            Serial.println();   
            return;
        }
        Serial.print("Cambiando la coordenada X de la pelota a ");
        Serial.println(newCoord);
        Serial.println();  
        turnOffPixel(ball->pos.x, ball->pos.y);     
        ball->pos.x = newCoord;
    }

    if(i == 3) {                // EN Y TENGO MAS RESTRICCIONES
        if(newCoord < 1 || newCoord > BLOCKSHEIGHT - 1) {
            Serial.println("Coordenada Y invalida");
            Serial.println();   
            return;
        }
        Serial.print("Cambiando la coordenada Y de la pelota a ");
        Serial.println(newCoord);
        Serial.println();  
        turnOffPixel(ball->pos.x, ball->pos.y);
        ball->pos.y = newCoord;
    }
    
    turnOnPixel(ball->pos.x, ball->pos.y);          // PRENDO EL PIXEL EN DONDE ESTA LA PELOTA AHORA

} 

void destroyBlock() {           // DESTRUYE UN BLOQUE A ELECCION
    Serial.println("Ingrese el blocke a destruir de 0 a 7");
    Serial.println(); 

    int block = readCharFromSerial() - '0';                 // LEE EL NUMERO DE BLOQUE POR EL PUERTO SERIE, QUE VIENE COMO CHAR Y LO PASA A INT

    if(block < 0 || block > FIELDSIZE / 2 - 1) {            // SE FIJA SI ES CORRECTO Y LO DESTRUYE
        Serial.println("Bloque invalido");
        Serial.println();   
        return;
    } else {
        Serial.print("Destruyendo el bloque numero ");
        Serial.println(block);
        Serial.println();  
        blocks[block] = 0;
        turnOffPixel(block * 2, BLOCKSHEIGHT);      // APAGA LOS PIXELES PARA NO TENER QUE REDIBUJAR TODO
        turnOffPixel(block * 2 + 1, BLOCKSHEIGHT);
        blocksLeft--;
    }
}  

void createBlock() {            // CREA UN BLOQUE A ELECCION
    Serial.print("Ingrese el blocke a crear de 0 a 7");

    int block = readCharFromSerial() - '0';     // LEE EL NUMERO DE BLOQUE POR EL PUERTO SERIE, QUE VIENE COMO CHAR Y LO PASA A INT

    if(block < 0 || block > FIELDSIZE / 2 - 1) {        // SE FIJA SI ES CORRECTO Y LO CREA
        Serial.println("Bloque invalido");
        Serial.println();   
        return;
    } else {
        Serial.print("Creando el bloque numero ");
        Serial.println(block);
        Serial.println();  
        blocks[block] = 1;
        turnOnPixel(block * 2, BLOCKSHEIGHT);
        turnOnPixel(block * 2 + 1, BLOCKSHEIGHT);
        blocksLeft++;
    }
} 

void destroyAllBlocks() {           // DESTRUYE TODOS LOS BLOQUES
    Serial.println("Destruyendo todos los bloques");
    Serial.println();  
    for(int i = 0; i < FIELDSIZE; i++) {
        turnOffPixel(i, BLOCKSHEIGHT);              // APAGA LOS PIXELES
        blocks[i / 2] = 0;                          // PONE EN 0 EL VECTOR DE BLOQUES EN TODAS LAS POSICIONES
    }
    blocksLeft = 0;         // E INDICA QUE NO QUEDAN BLOQUES
}

void createAllBlocks() {           // CREA TODOS LOS BLOQUES
    Serial.println("Creando todos los bloques");
    Serial.println();  
    for(int i = 0; i < FIELDSIZE; i++) {
        turnOnPixel(i, BLOCKSHEIGHT);              // ENCIENDE LOS PIXELES
        blocks[i / 2] = 1;                          // PONE EN 1 EL VECTOR DE BLOQUES EN TODAS LAS POSICIONES
    }
    blocksLeft = FIELDSIZE / 2;         // E INDICA QUE QUEDAN TODOS LOS BLOQUES
}

void modifyTime() {             // MODIFICA EL CONTADOR TIEMPO JUGADO HASTA EL MOMENTO
    Serial.println("Ingrese cuanto tiempo ha estado jugando hasta ahora en segundos (00 - 99) CON DOS DIGITOS");
    Serial.println();  

    int newTime = readTwoDigitIntFromSerial();      // OBTIENE EL INT DE LOS SEGUNDOS QUE ESTUVO JUGANDO

    if(newTime < 0) {                               // SE FIJA SI ES INVALIDO
        Serial.println("Numero invalido!");
        Serial.println(); 
        return;
    }

    startTime = pauseTime - newTime * 1000;         // SI ES VALIDO, INDICA QUE EMPEZO EL JUEGO HACE X SEGUNDOS DESDE QUE COMENZO LA INTERRUPCION
}

void modifyParameters() {       // FUNCION LLAMADA CUANDO EN LA INTERRUPCION SE ELIGE LA OPCION DE MODIFICAR PARAMETROS DEL JUEGO
    Serial.println("Usted esta por modificar los parametros del juego. Opciones:");
    Serial.println("1: modificar ubicacion del jugador");
    Serial.println("2: modificar coordenada x de la pelota");
    Serial.println("3: modificar coordenada y de la pelota");
    Serial.println("4: hacer desaparecer un bloque");
    Serial.println("5: hacer aparecer un bloque");
    Serial.println("6: hacer desaparecer todos los bloques");
    Serial.println("7: hacer desaparecer todos los bloques");
    Serial.println("8: modificar el tiempo de juego transcurrido");
    Serial.println("Otra opcion: volver al juego");
    Serial.println();

    char option = readCharFromSerial();     // OBTIENE EL CHAR POR EL SERIAL

    switch(option) {            // Y EJECUTA LO CORRESPONDIENTE
        case '1': 
            modifyPlayerPosition();
            break;
        case '2': 
            modifyBallPosition(2, &b);      // 2 SIGNIFICA X  
            break;
        case '3':
            modifyBallPosition(3, &b);      // 3 SIGNIFICA Y  
            break;
        case '4': 
            destroyBlock();
            break;
        case '5': 
            createBlock();
            break;
        case '6':
            destroyAllBlocks();
            break;
        case '7': 
            createAllBlocks();
            break;
        case '8': 
            modifyTime();
            break;
        default: 
            break;
    }
} 