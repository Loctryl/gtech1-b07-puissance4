#include <stdio.h>

void init(void) {
  int NBL, NBC;
  char tab[NBL][NBC];
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[l][c] = '.';
    }
  }
}

void main(void) {
  // Init du jeu:
  init();
  // Boucle du jeu:
}