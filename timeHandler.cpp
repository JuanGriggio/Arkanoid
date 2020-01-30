#include "timeHandler.h"

unsigned long getPlayTimeInSeconds() {
  return (pauseTime - startTime) / 1000;
}

void showTime(unsigned long miliseconds) {      // DADO UN TIEMPO EN MILISEGUNDOS, LO MUESTRA EN LAS MATRICES DE LED COMO MINUTOS Y SEGUNDOS
  m.clear();      // LIMPIA LAS MATRICES

  unsigned long seconds = miliseconds / 1000;   // PASA A SEGUNDOS

  int minutes = 0;
 
  while(seconds > 60) {   // CALCULA MINUTOS Y SEGUNDOS CORRECTAMENTE
    seconds -= 60;
    minutes++;
  }

  printCharStartingFromColumn(minutes / 10 + '0', 0);       // MUESTRA EL TIEMPO
  printCharStartingFromColumn(minutes % 10 + '0', 8);
  printCharStartingFromColumn(seconds / 10 + '0', 16);
  printCharStartingFromColumn(seconds % 10 + '0', 24);

  delay(10000);     // ESPERA UN POCO PARA QUE SE PUEDA VER
  m.clear();        // LIMPIA LA MATRIZ
  initialDisplay(&b);   // Y VUELVE A MOSTRAR EL ESTADO DEL JUEGO COMO ESTABA
}
