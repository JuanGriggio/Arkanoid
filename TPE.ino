
#include <MaxMatrix.h>
#include "structs.h"

MaxMatrix m(DATA, LOAD, CLOCK, NUM_OF_MATRIX);      // PARA CONTROLAR LAS MATRICES

char font8x8_basic[129][8] = {
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0000 (nul)
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0001
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0002
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0003
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0004
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0005
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0006
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0007
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0008
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0009
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000A
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000B
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000C
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000D
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000E
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+000F
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0010
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0011
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0012
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0013
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0014
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0015
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0016
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0017
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0018
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0019
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001A
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001B
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001C
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001D
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001E
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+001F
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0020 (space)
 { 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00}, // U+0021 (!)
 { 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0022 (")
 { 0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00}, // U+0023 (#)
 { 0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00}, // U+0024 ($)
 { 0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00}, // U+0025 (%)
 { 0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00}, // U+0026 (&)
 { 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0027 (')
 { 0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00}, // U+0028 (()
 { 0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00}, // U+0029 ())
 { 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00}, // U+002A (*)
 { 0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00}, // U+002B (+)
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06}, // U+002C (,)
 { 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00}, // U+002D (-)
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00}, // U+002E (.)
 { 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00}, // U+002F (/)
 { 0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00}, // U+0030 (0)
 { 0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00}, // U+0031 (1)
 { 0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00}, // U+0032 (2)
 { 0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00}, // U+0033 (3)
 { 0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00}, // U+0034 (4)
 { 0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00}, // U+0035 (5)
 { 0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00}, // U+0036 (6)
 { 0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00}, // U+0037 (7)
 { 0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00}, // U+0038 (8)
 { 0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00}, // U+0039 (9)
 { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00}, // U+003A (:)
 { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06}, // U+003B (//)
 { 0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00}, // U+003C (<)
 { 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00}, // U+003D (=)
 { 0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00}, // U+003E (>)
 { 0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00}, // U+003F (?)
 { 0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00}, // U+0040 (@)
 { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00}, // U+0041 (A)
 { 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00}, // U+0042 (B)
 { 0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00}, // U+0043 (C)
 { 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00}, // U+0044 (D)
 { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00}, // U+0045 (E)
 { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00}, // U+0046 (F)
 { 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00}, // U+0047 (G)
 { 0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00}, // U+0048 (H)
 { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0049 (I)
 { 0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00}, // U+004A (J)
 { 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00}, // U+004B (K)
 { 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00}, // U+004C (L)
 { 0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00}, // U+004D (M)
 { 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00}, // U+004E (N)
 { 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00}, // U+004F (O)
 { 0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00}, // U+0050 (P)
 { 0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00}, // U+0051 (Q)
 { 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00}, // U+0052 (R)
 { 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00}, // U+0053 (S)
 { 0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0054 (T)
 { 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00}, // U+0055 (U)
 { 0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00}, // U+0056 (V)
 { 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00}, // U+0057 (W)
 { 0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00}, // U+0058 (X)
 { 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00}, // U+0059 (Y)
 { 0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00}, // U+005A (Z)
 { 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00}, // U+005B ([)
 { 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00}, // U+005C (\)
 { 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00}, // U+005D (])
 { 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00}, // U+005E (^)
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF}, // U+005F (_)
 { 0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+0060 (`)
 { 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00}, // U+0061 (a)
 { 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00}, // U+0062 (b)
 { 0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00}, // U+0063 (c)
 { 0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00}, // U+0064 (d)
 { 0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00}, // U+0065 (e)
 { 0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00}, // U+0066 (f)
 { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F}, // U+0067 (g)
 { 0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00}, // U+0068 (h)
 { 0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+0069 (i)
 { 0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E}, // U+006A (j)
 { 0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00}, // U+006B (k)
 { 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00}, // U+006C (l)
 { 0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00}, // U+006D (m)
 { 0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00}, // U+006E (n)
 { 0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00}, // U+006F (o)
 { 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F}, // U+0070 (p)
 { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78}, // U+0071 (q)
 { 0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00}, // U+0072 (r)
 { 0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00}, // U+0073 (s)
 { 0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00}, // U+0074 (t)
 { 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00}, // U+0075 (u)
 { 0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00}, // U+0076 (v)
 { 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00}, // U+0077 (w)
 { 0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00}, // U+0078 (x)
 { 0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F}, // U+0079 (y)
 { 0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00}, // U+007A (z)
 { 0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00}, // U+007B ({)
 { 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00}, // U+007C (|)
 { 0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00}, // U+007D (})
 { 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+007E (~)
 { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // U+007F
 { 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00} // U+0080
};

char blocks[FIELDSIZE/2];           // LOS BLOQUES A ROMPER. ES FIELDSIZE / 2 PORQUE CADA BLOQUE OCUPA 2 PIXELES
char player[FIELDSIZE] = {0};       // EL JUGADOR, VECTOR DE FIELDSIZE POSICIONES QUE COMIENZA EN 0 PORQUE DESPUES SE INICIALIZA AL AZAR
int playerStartsAt;                 // INDICA RAPIDAMENTE DONDE ESTA EL JUGADOR PARA PODER MOSTRARLO RAPIDAMENTE POR LAS MATRICES
int gameOver = 0;                   // INDICA SI SE SIGUE JUGANDO O SE PERDIO
int brokenBlock = -1;               // -1 SI NO SE ROMPIO NINGUN BLOQUE, SINO INDICA EL BLOQUE QUE SE ROMPIO, ES PARA MOSTRAR MAS RAPIDO POR LAS MATRICES
int playerMoved = 0;                // 0 SI NO SE MOVIO, -1 SI SE MOVIO A LA IZQ, 1 SI SE MOVIO A LA DER, ES PARA MOSTRAR MAS RAPIDO POR LAS MATRICES
ball b;                             // LA PELOTA DEL JUEGO 
unsigned long startTime, endTime;   // PARA MEDIR EL TIEMPO DE JUEGO
unsigned long currentTime, lastTime;    // PARA MEDIR EL INTERVALO DE 15 SEGUNDOS POR EL CUAL SE INCREMENTA LA VELOCIDAD DE LA PELOTA
int hasToPrint = 1;                 // PARA VER SI HAY QUE IMPRIMIR LA INFO AL TERMINAR EL JUEGO
int blocksLeft = FIELDSIZE / 2;     // CANTIDAD DE BLOQUES QUE QUEDAN
unsigned long pauseTime;            // PARA DESCONTAR EL TIEMPO AL INTERACTUAR CON LA TERMINAL / VIENDO LA HORA / ETC

#include "constants.h"
#include "Arkanoid.h"
#include "globalVariables.h"
#include "matrixHandler.h"
#include "serialCommunicator.h"

#include "Arduino.h"





void checkInput() {         // CHEQUEO LA ENTRADA
    if(digitalRead(MOVE_LEFT_PIN) == HIGH) {
        movePlayerLeft();
    } else if(digitalRead(MOVE_RIGHT_PIN) == HIGH) {
        movePlayerRight();
    } else if(digitalRead(INTERRUPT_PIN) == HIGH) {
        interrupt();
    }
}


void setup() {
  Serial.begin(115200); // INICIALIZO PUERTO SERIE PARA LA COMUNICACION

  m.init();             // INICIALIZO LA MATRIZ
  m.setIntensity(OFF_INTENSITY);

  pinMode(MOVE_LEFT_PIN, INPUT);     // CONFIGURO PINES QUE VOY A USAR COMO ENTRADA
  pinMode(MOVE_RIGHT_PIN, INPUT);
  pinMode(INTERRUPT_PIN, INPUT);

  initializeGame(&b);       // INICIALIZA EL JUEGO ARKANOID
  initialDisplay(&b);       // MUESTRA TODO POR LAS PANTALLAS POR PRIMERA VEZ. ESTO SE HACE PARA QUE DESPUES SOLO SE TENGA QUE MOSTRAR
                            // LO QUE CAMBIA Y NO ACTUALIZAR TODA LA PANTALLA
  
  Serial.println("BIENVENIDO!");
  Serial.println("Instrucciones: El juego comienza automaticamente. Si genera una interrupcion a traves del pin de interrupciones, las opciones son las siguientes:");
  Serial.println("t: ver tiempo jugado hasta ahora");
  Serial.println("s: interactuar con la shell del Yocto-Linux");
  Serial.println("m: modificar parametros del juego");
  Serial.println("Otra opcion: volver al juego");
  Serial.println();

  startTime = millis();     // PARA CONTAR CUANTO TIEMPO ESTUVO JUGANDO
  lastTime = millis();      // PARA CONTAR LOS 15 SEGUNDOS
}

void loop() {
    while(gameOver == 0 && blocksLeft != 0) {           // MIENTRAS QUE NO HAYA PERDIDO O NO HAYA GANADO
        currentTime = millis();
        if(currentTime - lastTime > 15000) {            // SE FIJA SI PASARON 15 SEGUNDOS DESDE LA ULTIMA VEZ QUE SE AUMENTO LA VELOCIDAD
            increaseBallSpeed(&b);                      // SI ES ASI, SE AUMENTA LA VELOCIDAD Y SE ACTUALIZA EL TIEMPO EN EL QUE ESTO PASO PARA PODER SEGUIR HACIENDO LA CUENTA
            lastTime = currentTime;
            Serial.println("Aumento de velocidad!");
            Serial.println();
        }
            

        checkInput();           // CHEQUEO SI HAY ALGUNA ENTRADA
        moveBall(&b);           // SIEMPRE MUEVO LA PELOTA
        displayPlayer();        // MUESTRO AL JUGADOR, SI ES QUE SE MOVIO
        displayBall(&b);        // MUESTRO LA PELOTA
        displayBrokenBlock();   // MUESTRO AL BLOQUE QUE SE ROMPIO, SI ES QUE HUBO UNO
    }
    endTime = millis();         // CUANTO TIEMPO ESTUVO JUGANDO
    printEndGame();             // MUESTRA TEXTO AL TERMINAR EL JUEGO, YA SEA SI GANO O PERDIO
   
    
}
