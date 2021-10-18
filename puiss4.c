#include <stdio.h>

void init(void) {
  int NBL, NBC;
  char tab[NBL][NBC];
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[l][c] = '.';
    }
  }
  return tab;
}

char aff(tab){
  int NBL, NBC;
  int game = tab;
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
        printf("%c", game[l][c]);
    }
  }
}

int main(void) {
  // Init du jeu:
  init();
  char token[] = "xo";
  // Boucle du jeu:
}