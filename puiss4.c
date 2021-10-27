#include <stdio.h>
#define NBL 6
#define NBC 7

char tab[NBL][NBC];
char token [] = "ox";
int player = 1;
int count = 0;

void Init(void) {
  for(int l=0; l<NBL; l++) {
    for(int c=0; c<NBC; c++) {
      tab[l][c] = '.';
    }
  }
}

void red(void){
  printf("\033[0;31m");
}

void green(void){
  printf("\033[0;32m");
}

void yellow(void){
  printf("\033[0;33m");

}

void cyan(void){
  printf("\033[0;36m");
}

void white(void){
  printf("\033[0;37m");
}

void Disp(void){

  printf("  _ _ _ _ _ _ _ ");
  for(int l=0; l<NBL; l++) {
    printf(" \n|");
    for(int c=0; c<NBC; c++) {
      if(tab[l][c] == token[0]){
        cyan();
        printf(" %c",tab[l][c]);
      } else if (tab[l][c] == token[1]){
        green();
        printf(" %c",tab[l][c]);
      } else {
        white();
        printf(" %c",tab[l][c]);
      }
    }
    white();
    printf(" |");
  }
  white();
  printf("\n  1 2 3 4 5 6 7 \n");
}


void Empty(void){
  int c = getchar();
  while (c != '\n' && c != EOF){
    c = getchar();
  }
}

int Verif(int range){
  int save;
  int answer;
  for (;;) {
    white();
    save = scanf (" %d", &answer);
    red();

    if (save == EOF) {
      fputs ("You didn't write anything...\n", stderr);
      return 0;
    }

    else if (save == 0) {
      fputs ("Could you choose an intager please ? ...\n", stderr);
      Empty();
    }

    else if (answer < 1 || range < answer) {
      fputs ("This is not a choice...\n", stderr);
      Empty();
    }
    
    else {  
      Empty();
      return answer;
    }
  }
}

int StatusGame(){
  red();
  if (count>6){
    for(int l=0; l<NBL; l++) {
      for(int c=0; c<5; c++) {
        if (tab[l][c] == token[player] && tab[l][c+1] == token[player] && tab[l][c+2] == token[player] && tab[l][c+3] == token[player]){
          printf("\nPlayer %d won !! \n", player+1);
          return 1;
        } 
      }  
    }

    for(int c=0; c<NBC; c++) {
      for(int l=0; l<4; l++) {
        if (tab[l][c] == token[player] && tab[l+1][c] == token[player] && tab[l+2][c] == token[player] && tab[l+3][c] == token[player]){
          printf("\nPlayer %d won !! \n", player+1);
          return 1;
        } 
      }
    }

    for(int c=6; c>2; c--) {
      for(int l=0; l<2; l++) {
        if (tab[l][c] == token[player] && tab[l+1][c-1] == token[player] && tab[l+2][c-2] == token[player] && tab[l+3][c-3] == token[player]){
          printf("\nPlayer %d won !! \n", player+1);
          return 1;
        } 
      }
    }

    for(int c=0; c<3; c++) {
      for(int l=0; l<2; l++) {
        if (tab[l][c] == token[player] && tab[l+1][c+1] == token[player] && tab[l+2][c+2] == token[player] && tab[l+3][c+3] == token[player]){
          printf("\nPlayer %d won !! \n", player+1);
          return 1;
        } 
      }
    }
  }

  if (count >= 42){
    printf("\nThe game is full ! Game Over !\n");
    return 1;
  }
  white();
  return 0;
}

void main(void) {
  int replay = 1;
  while (replay == 1){

    Init();
    Disp();

    while(StatusGame() == 0){

      int column, i=5;
      player = !player;
      red();
      printf("\nPlayer %d is playing ! \nWhich column do you choose ?\n",player+1);
      column = Verif(7);

      while(tab[0][column-1] != '.'){
        printf("\nThis column is full, choose an other one please.\nWhich column do you choose ?\n");
        column = Verif(7);
        }

      while (tab[i][column-1] != '.'){
        i --;
      }

      tab[i][column-1] = token[player];
      white();
      Disp();
      count ++;
      printf("---------------------\n");
    }

    replay = 0;
    yellow();
    printf("\nDo you want to play again ?\n1 for Yes\n2 for No\n");
    red();
    replay = Verif(2);

    while (replay != 1 && replay != 2){
      yellow();
      printf("\nDo you want to play again ?\n1 for Yes\n2 for No\n");
      red();
      replay = Verif(2);
    }
    white();
    if (replay == 1){
      printf("\nAh shit ... here we go again..\n");
    }
    count = 0;
  }
  red();
  printf("\nGame Over ! See You !\n\n");
  white();
}