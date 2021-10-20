#include <stdio.h>
#define NBL 6
#define NBC 7


char tab[NBL][NBC];
char token [] = "ox";
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
  printf("\n  1 2 3 4 5 6 7 ");
}

int statusgame(void){
  int count = 0;
  int align = 0;
  printf("\nj'uis dans le status de la game\n");

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
  printf("\nFin d'init\n");
  disp();
  printf("\nFin de disp\n");
  // Boucle du jeu:
  while(statusgame() == 0){
    printf("\nJ'uis rentré dans la boucle\n");
    int colonne, code_retour;
    int i = 7 ;
    do {
      printf("\nOn joue dans quel colonne ?\n");
      code_retour = scanf("%d", &colonne);
    } while (0<code_retour<8);{
        printf("j'uis dans celle là ?");
        while (tab[i][code_retour] != '.'){
          i --;
        }
        printf("Et est-ce que j'en sors ?");
        tab[i][code_retour] = token[joueur];
    }
  }
}