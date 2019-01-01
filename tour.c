#include "header.h"

/**
 * \brief       
 * \details  Cette fonction permet de jouer un tour. 
 * \param    joueur* player1 : le joueur qui joue  
 * \param    joueur* player2 : le joueur l'adversaire.   
 * \return   Le joueur.
 */
joueur* tour(joueur* player1, joueur* player2){
  int ligne,colonne,occuper,i,b = 0;

  do{
    occuper = 0;
    // Obtenir le choix du joueur1 pour attaque une case  
    if(!player1->ia){
      // Si le joueur1 est un humaine
      do{
          if(b) printf("valeur incorrect,\n");
          printf("(ligne,colonne) :");
          scanf("%d %d",&ligne,&colonne);
          b = 1;
      }while((ligne > TAILLE_PLATEAU || ligne < 0) || (colonne > TAILLE_PLATEAU || colonne < 0));
    }else{
      // Si le joueur1 est une IA
      ligne = rand()%TAILLE_PLATEAU + 1;
      colonne = rand()%TAILLE_PLATEAU + 1;
    }
    // Savoir quelle case est touché celle d'un bateau ou une case vide ou une deja joue précdament 
    if(player2->plateau[ligne - 1][colonne - 1] == '#'){
      //bateau toucher incrémentation du nombre de tire réussi
      player2->plateau[ligne - 1][colonne - 1] = 'X';
      player1->nbr_tir_reussit++;
      // Savoir quelle bateau est toucher est incrémenter le nombre de case toucher pour ce bateau 
      for (i = 0; i < NOMBRE_BATEAU; ++i){
        if(((colonne - 1 >= player2-> bat[i].position_colonne)
            && (colonne - 1 < player2-> bat[i].position_colonne + player2-> bat[i].nbr_case_colonne)) &&
            ((ligne - 1 >= player2-> bat[i].position_ligne)
            && (ligne  - 1< player2-> bat[i].position_ligne + player2->bat[i].nbr_case_ligne))){
          player2->bat[i].nbr_case_toucher++;
          break;
        }
      }
    }
    else{
      if (player2->plateau[ligne - 1][colonne - 1] == 'X' || player2->plateau[ligne - 1][colonne - 1] == 'O' )
        occuper = 1;// Case précédament toucher 
      else{
        // case vide toucher incréménter le nombre de tir manger
        player2->plateau[ligne - 1][colonne - 1] = 'O';
        player1->nbr_tir_manquer++;
      }
    }
  }while(occuper == 1);

  return player2;
}

/**
 * \file          header.h
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition de la fonction tour  
 *
 */