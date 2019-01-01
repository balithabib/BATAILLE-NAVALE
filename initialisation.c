#include "header.h"

/**  
 * \details  Cette fonction permet d'intialiser les champ du joueur passer en argument. 
 * \param    char* nom : le nom du joueur.
 * \param    char* color : la couleur par défaut du joueur.
 * \param	 int ia : une valeur qui indique la nature du joueur humaine ou ia. 
 * \return   le joueur.
 */
joueur* initialisation(char* nom, char* color, int ia){
	int ligne, colonne;
	joueur* player;
	player = malloc(sizeof (*player));
	player->nom = nom;
	
	for(ligne = 0 ; ligne < TAILLE_PLATEAU ; ++ligne)
		for(colonne = 0 ; colonne < TAILLE_PLATEAU ; ++colonne)
			player->plateau[ligne][colonne] = ' ';

	player->ia = ia;
	player->nbr_bateau_couler = 0;
	player->nbr_bateau_restant = NOMBRE_BATEAU;
	player->nbr_tir_reussit = 0;
	player->nbr_tir_manquer = 0;
	player->color = color;
	
	player = positionementDesBateaux(player);
	return player;
}

/**
 * \file          initialisation.c
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition de la fonction initialisation
 *
 */