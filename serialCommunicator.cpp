#include "serialCommunicator.h"

void printEndGame() {           // IMPRIME COSAS AL TERMINAR EL JUEGO
    if(hasToPrint == 0)         // SI YA LO IMPRIMIO RETORNA
        return;
    
    hasToPrint = 0;             // SI NO LO HABIA IMPRESO, CAMBIA ESTE VALOR PARA INDICAR QUE YA LO IMPRIMIO ASI NO LO IMPRIME DEVUELTA

    if(blocksLeft == 0)
        Serial.println("Felicitaciones, ha ganado!");       // SI NO QUEDO NINGUN BLOQUE GANASTE
    else
        Serial.println("Que lastima, la proxima sera!");    // SINO PERDISTE

    unsigned long totalTime = endTime - startTime;

    Serial.print("Usted estuvo jugando ");          // MOSTRAR EL TIEMPO QUE ESTUVO JUGANDO
    Serial.print(totalTime);
    Serial.print(" milisegundos, es decir ");
    Serial.print((double) (totalTime) / 1000);
    Serial.println(" segundos.");

    showTime(totalTime);
}

int readTwoDigitIntFromSerial() {       // LEE POR EL PUERTO SERIE UN ENTERO DE DOS DIGITOS, LO DEVUELVE COMO ENTERO Y VACIA LO QUE SOBRA DEL SERIAL
    while(Serial.available() == 0);     // ESPERO A QUE ESTE EL NUMERO EN EL SERIAL

    char d1 = Serial.read();            // LEO EL PRIMER DIGITO
    char d2 = Serial.read();            // LEO EL SEGUNDO DIGITO

    while(Serial.available() != 0) {    // VACIO EL '\r' Y LO QUE SOBRA, SI INGRESO DE MAS
        Serial.read();
    }

    return (d1 - '0') * 10 + (d2 - '0');      // TRANSFORMA LOS CHARS EN EL INT QUE RETORNA
}

char readCharFromSerial() {             // FUNCION PARA LEER UN CHAR POR EL PUERTO SERIE Y VACIAR EL RESTO. UTIL PARA INGRESAR OPCIONES
    while(Serial.available() == 0);     // ESPERO A QUE SE INGRESE UNA OPCION POR EL PUERTO SERIE

    char c = Serial.read();        // TOMO EL PRIMER CARACTER DE LO INGRESADO POR EL PUERTO SERIE COMO OPCION

    while(Serial.available() != 0)      // ELIMINO EL '\r' QUE SOBRA POR EL PUERTO SERIE Y LOS DEMAS CARACTERES, SI ES QUE INGRESO MAS DE UNO
        Serial.read();

    return c;
}

void shellInteraction() {               // INTERACCION CON LA SHELL DEL YOCTO LINUX
    char buffer[1000];                  // BUFFER PARA LA COMUNICACION CON EL PUERTO SERIE
    char x [] = {"&>/dev/ttyGS0 &"};    // PARA CONCATENAR AL FINAL DE LOS COMANDOS
    int i = 0, j = 0;                   // CONTADORES PARA PODER INTERPRETAR LOS COMANDOS
    
    Serial.println("Usted esta interactuando con la shell de Yocto-Linux. Por favor, ingrese un comando:");
    Serial.println();

    while(Serial.available() == 0 );    // ESPERO A QUE HAYA UN COMANDO POR EL PUERTO SERIE

    while(Serial.available() > 0) {     // UNA VEZ QUE HAY, LO LEO
        buffer[i] = Serial.read();
        i++;
    }
    
    while(x[j] != 0) {                  // LE CONCATENO EL VECTOR X PARA PODER EJECUTAR EL COMANDO
        buffer[i - 1] = x[j];
        i++;
        j++;
    }

    system(buffer);                     // Y LO EJECUTO
}

void interrupt() {                  // SE EJECUTA AL SER INTERRUMPIDO EL JUEGO. MANEJA LAS OPCIONES
    pauseTime = millis();           // GUARDA EL MOMENTO EN EL QUE OCURRIO LA INTERRUPCION PARA PODER DESCONTAR EL TIEMPO QUE TARDA DEL TIEMPO DE JUEGO

    Serial.println("Interrupcion! Opciones:");
    Serial.println("t: ver tiempo jugado hasta ahora");
    Serial.println("s: interactuar con la shell del Yocto-Linux");
    Serial.println("m: modificar parametros del juego");
    Serial.println("Otra opcion: volver al juego");
    Serial.println();

    char option = readCharFromSerial();

    switch(option) {                    // SEGUN LO INGRESADO, EJECUTO LO QUE CORRESPONDE
        case 't': 
            Serial.println("Mostrando tiempo de juego hasta ahora en las matrices");
            Serial.println();
            showTime(pauseTime - startTime);        // DICE QUE MUESTRE EL TIEMPO JUGADO HASTA AHORA
            break;
        case 's': 
            shellInteraction();
            break;
        case 'm':
            modifyParameters();
            break;
        default: 
            break;
    }

    pauseTime = millis() - pauseTime;       // CALCULO EL TIEMPO TOTAL QUE EL JUEGO ESTUVO EN PAUSA, ES DECIR, EL TIEMPO QUE DURO LA INTERRUPCION
    lastTime += pauseTime;                  // SE LO SUMO AL CONTADOR DEL TIEMPO PARA AUMENTAR LA VELOCIDAD PARA QUE HAGA COMO SI NO HUBIERA PASADO TIEMPO
    startTime += pauseTime;                 // IDEM CON EL CONTADOR DE TIEMPO TOTAL
}