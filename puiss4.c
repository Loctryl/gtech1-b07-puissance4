#include <stdio.h>
#define NBL 6
#define NBC 7


char tab[NBL][NBC];
char token [] = "ox";
int joueur = 0;
int count = 0;

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
  printf("\n  1 2 3 4 5 6 7 \n");
}

int statusgame(){
  printf("Je rentre dans la status de la game\n");
  int align = 0;
  if (count>6){
    for(int l=0; l<NBL; l++) {
      for(int c=0; c<5; c++) {
        if (tab[l][c] == token[joueur] && tab[l][c+1] == token[joueur] && tab[l][c+2] == token[joueur] && tab[l][c+3] == token[joueur]){
          printf("Je suis 1");
          return 1;
        } 
      }  
    }
    for(int c=0; c<NBC; c++) {
      for(int l=0; l<4; l++) {
        if (tab[l][c] == token[joueur] && tab[l+1][c] == token[joueur] && tab[l+2][c] == token[joueur] && tab[l+3][c] == token[joueur]){
          printf("Je suis 2");
          return 1;
        } 
      }
    }
    for(int c=6; c>2; c--) {
      for(int l=0; l<2; l++) {
        if (tab[l][c] == token[joueur] && tab[l+1][c-1] == token[joueur] && tab[l+2][c-2] == token[joueur] && tab[l+3][c-3] == token[joueur]){
          printf("Je suis 3");
          return 1;
        } 
      }
    }
    for(int c=0; c<3; c++) {
      for(int l=0; l<2; l++) {
        if (tab[l][c] == token[joueur] && tab[l+1][c+1] == token[joueur] && tab[l+2][c+2] == token[joueur] && tab[l+3][c+3] == token[joueur]){
          printf("Je suis 4");
          return 1;
        } 
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
      int colonne;
      int i = 5 ;
      printf("\nOn joue dans quel colonne ?\n");
      scanf("%d", &colonne);
      if (colonne<=7 && tab[6][colonne] != '.'){
        while (tab[i][colonne-1] != '.'){
          i --;
        }
        tab[i][colonne-1] = token[joueur];
        disp();
        printf("Changement de joueur ! ");
        joueur = !joueur;
        count ++;
        printf("%d \n", count);
      } else {
        printf("\nVous ne pouvez pas jouer dans cette colonne ! \n");
        disp();
        }
    }
}