#include <stdio.h>

char init(void) {
  int NBL, NBC;
  char tab[NBL][NBC];
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[l][c] = '.';
    }
  }
  return tab[NBL][NBC];
}

int main(void) {
  // Init du jeu:
  char tab;
  tab = init();
  // Boucle du jeu:
  return 0;
}