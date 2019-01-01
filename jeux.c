#include "header.h"

/**   
 * \details  Cette fonction permet de savoir la fin du jeu en testent l'égaliter entre le nombre
 *           de tir reussit et le nombre de case total pour l'ensemble des  bateaux  
 * \param    joueur* player : le joueur concerner.
 */
int gameOver(joueur* player){
  if(player->nbr_tir_reussit == NOMBRE_CASE_BATEAU){
    print(player, 2);
    return 1;
  }
  else 
    return 0; 
}

/**   
 * \details  Cette fonction permet de jouer à une partie du jeu. 
 * \param    joueur* player1 : le joueur 1.
 * \param    joueur* player2 : le joueur 2.
 */
void jeu(joueur* player1,joueur* player2){
  joueur* joueurActualle;
  int i = 0;
    
  joueurActualle = player1;
  while(!gameOver(joueurActualle)){
  // Le joueur 1 jeu son tour
    joueurActualle = player1;
    print(joueurActualle, 1);
    afficher(player2, player1,1);
    // Le joueur 1 choisit une case du plateau du joueur 2 
    player2 = tour(player1, player2);
    print(joueurActualle, 0);
    //On teste c'est le joueur 1  à gagner
    if(!gameOver(joueurActualle)){
    // Le joueur 2 jeu son tour
      joueurActualle = player2;
      if(player1->ia == player2->ia || joueurActualle->ia == 0){
        print(joueurActualle, 1);  
        afficher(player1, player2,1);
      }
      // Le joueur 2 choisit une case du plateau du joueur 1
      player1 = tour(player2, player1);      
      if(player1->ia == player2->ia || joueurActualle->ia == 0) print(joueurActualle, 0);
    }else{
      break;
    }
    i++;
  }
  printf("Le nombre de tour joue = %d\n",i);
}

/**       
 * \details  Cette fonction permet d'avancer la parti à n coup puis appelle la fonction jeu pour continue l'execution normale du jeu.
 * \param    joueur* player1 : le joueur 1.
 * \param    joueur* player2 : le joueur 2.
 * \param    int n : le nombre de tour que on veut avancé le jeu.
 */
void jeuANCoup(joueur* player1,joueur* player2,int n){
  joueur* joueurActualle = player1;
  int i = 0, ia1 = player1->ia, ia2 = player2->ia;

  print(joueurActualle,3);
  player1->ia = 1;
  player2->ia = 1;
  while(!gameOver(joueurActualle) && (i < n)){
    joueurActualle = player1;
    player2 = tour(player1, player2);
    if(!gameOver(joueurActualle)){
      joueurActualle = player2;
      player1 = tour(player2, player1);
    }
    i++;
  }
  if(gameOver(joueurActualle)) return;
  player1->ia = ia1;
  player2->ia = ia2;

  jeu(player1, player2);

  printf("plus Le nombre de tour joue au début = %d\n",i);
}

/**
 * \file          jeu.c
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition des fonction qui sert a faire marcher le jeu
 *
 */