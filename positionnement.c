#include "header.h"

/**   
 * \details  Cette fonction permet de positionner les bateaux.
 * \param    joueur* player : le joueur concerner. 
 * \return   Le joueur. 
 */
joueur* positionementDesBateaux(joueur* player){
	int nbrCase = 2, occuper, choix1, choix2;
	int posc, posl;
	// Les 4 Bateaux sous forme de  ligne
	for(int i = 0; i < 4;i++){
		player->bat[i].nbr_case_colonne = nbrCase++;
		player->bat[i].nbr_case_ligne = 1;
	}
    // Les Couleur donner pour chaque bateaux
	player->bat[0].color = "32";player->bat[1].color = "33";player->bat[2].color = "34";player->bat[3].color = "35";
	player->bat[4].color = "36";player->bat[5].color = "37";player->bat[6].color = "38";player->bat[7].color = "36";
	player->bat[8].color = "32";player->bat[9].color = "33";
	// Les bateaux sous forme de 4x4 et 4x2
	player->bat[4].nbr_case_colonne = player->bat[4].nbr_case_ligne = 2;
	player->bat[5].nbr_case_colonne = 4;player->bat[5].nbr_case_ligne = 2;
	player->bat[6].nbr_case_colonne = player->bat[6].nbr_case_ligne = 4;
	// on fait la déffirence  entre les bateaux normale(bateaux ligne, 4x4 et 4x2) est anormale(bateaux L, H et T)  
	for (int i = 0; i <= 6; ++i){	
		player->bat[i].type = 0;// pour faire la deffirence entre les forme des bateaux
		player->bat[i].normale = 0;
		player->bat[i].nbr_case_total = player->bat[i].nbr_case_ligne * player->bat[i].nbr_case_colonne;// Nombre total de case pour chaque  bateau
	}
	// Les bateau sous forme de L, H et T
	player->bat[7].nbr_case_colonne = player->bat[7].nbr_case_ligne = 4; player->bat[7].normale = 1; player->bat[7].type = 1; player->bat[7].nbr_case_total = 7;
	player->bat[8].nbr_case_colonne = 3; player->bat[8].nbr_case_ligne = 4; player->bat[8].normale = 1; player->bat[8].type = 2; player->bat[8].nbr_case_total = 6;
	player->bat[9].nbr_case_colonne = player->bat[9].nbr_case_ligne = 3; player->bat[9].normale = 1; player->bat[9].type = 3; player->bat[9].nbr_case_total = 7;
	// Placement des Bateaux dans le plateau
	for(int i = 0 ; i < NOMBRE_BATEAU ; i++){
		player->bat[i].nbr_case_toucher = 0;// Au debut aucune case n'est toucher 
		//chercher une bonne position pour chaque bateau
		do{
			occuper = 0;
			posc = rand() % (TAILLE_PLATEAU - player->bat[i].nbr_case_colonne + 1);// Colonne de positionement du bateau
			posl = rand() % (TAILLE_PLATEAU - player->bat[i].nbr_case_ligne + 1); // Ligne de positionement du bateau
			//printf("posl = %d   posc = %d \n",posl,posc);
			// Vérifié si il y n'a pas un autre bateau sur cette position
			for(int j = posl ; j < posl + player->bat[i].nbr_case_ligne ; j++){
				for(int k = posc ; k < posc + player->bat[i].nbr_case_colonne ; ++k){
					if(player->plateau[j][k] == '#'){
						occuper = 1;
						break;
					}
				}	
				if(occuper == 1)break;
			}
			if(player->bat[i].normale){
				for (int j = 0; j < i; ++j){
					if(((posc >= player-> bat[i].position_colonne)
							&& (posc < player-> bat[j].position_colonne + player-> bat[j].nbr_case_colonne)) &&
							((posl >= player-> bat[j].position_ligne)
							&& (posl < player-> bat[j].position_ligne + player-> bat[j].nbr_case_ligne))){
						occuper = 1;
						break;
					}
				}
			}
		} while (occuper == 1);// repeter tanque il y déja un bateau sur cette position 
		//Affecter la bonne position au bateau 
		player->bat[i].position_ligne = posl; 
		player->bat[i].position_colonne = posc;
		// Dessiner le bateau selon sa forme (ligne, 4x4, 4x2, L, H et T ...)
		if(player->bat[i].normale == 0){
			for(int j = posl ; j < posl + player->bat[i].nbr_case_ligne ; j++)
				for(int k = posc ; k < posc + player->bat[i].nbr_case_colonne ; ++k)
					player->plateau[j][k] = '#';
		}else{
			switch (player->bat[i].type){
				case 1 :{// Bateau sous forme de L 4 cas
					choix1 = rand()%3 + 1;
					choix2 = rand()%3 + 1;
					if(choix2 == 2 ) choix2 = posl + player->bat[i].nbr_case_ligne - 1 ;
					else choix2 = posl ;

					if(choix1 == 2 ) choix1 = posc + player->bat[i].nbr_case_colonne - 1 ;
					else choix1 = posc ;
				}
				break;
				case 2 :{// Bateau sous forme de T
					choix1 = posc + player->bat[i].nbr_case_colonne/2;
					choix2 = posl;
				}
				break;
				case 3 :{// Bateau sous forme de H
					choix1 = posc + player->bat[i].nbr_case_colonne - 1;
					choix2 = posl + player->bat[i].nbr_case_ligne / 2;
				}
				break;
			}
			// Placer les bateaux dans le plateau 
			for(int j = posl ; j < posl + player->bat[i].nbr_case_ligne ; j++)
				player->plateau[j][choix1] = '#';

			if(player->bat[i].type == 3){
				for(int j = posl ; j < posl + player->bat[i].nbr_case_ligne ; j++)
				player->plateau[j][posc] = '#';
			}

			for(int k = posc ; k < posc + player->bat[i].nbr_case_colonne ; ++k)	
				player->plateau[choix2][k] = '#';
		}
	}

return player;
}

/**
 * \file         positionnement.c
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition de la fonction positionnement 
 *
 */