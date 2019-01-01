#include "header.h"


int main (void) {
  for(int i = 1; i< 100;i++){
  printf ("Debut des tests\n");
  
  joueur* player1 = NULL;
  player1 = initialisation(player1,GREEN,1);
  assert (player1 != NULL);

  joueur* player2 = NULL;
  player2 = initialisation(player2,YELLOW,1);
  assert (player2 != NULL);
  
  joueur* joueurActualle = player1;
  while(!gameOver(joueurActualle)){

    joueurActualle = player1;
    player2 = tour(player1, player2);

    if(!gameOver(joueurActualle)){

      joueurActualle = player2;
      player1 = tour(player2, player1);      
    }else{
      break;
    }
  }
  printf("\n-------------------------------\n");
  }
  printf ("Tout est OK\n");

  return (EXIT_SUCCESS);
}