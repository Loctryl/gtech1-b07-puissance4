#include <stdio.h>
#define NBL 6
#define NBC 7

char** tab[NBL][NBC];
int joueur;

void init(void) {
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[l][c] = '.';
    }
  }
}

void disp(void){
  printf("  _ _ _ _ _ _ _ ");
  for(int l=0; l<NBL; l++) {
    printf(" \n|");
    for(int c=0; c<NBC; c++) {
      printf(" %c",tab[l][c]);
    }
    printf(" |");
  }
  printf("\n  - - - - - - - ");
}

int statusgame(void){
  int count = 0;
  int align = 0;

  //game won

  if (align == 4){
    return 2 ; 
  }

  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      if (tab[l][c] != '.'){
        count ++;
      }
    }
  }
  if (count == 42){
    return 1;
  }
  return 0;
}

void main(void) {
  // Init du jeu:
  init();
  disp();
  // Boucle du jeu:
  while(statusgame() == 0){
    int colonne, code_retour;
    do {
      code_retour = scanf("%d", &colonne);
    } while (0<code_retour<8);{
        return 0;
    }
  }
}