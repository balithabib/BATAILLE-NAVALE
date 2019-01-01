#include "header.h"

/**
 * \details  Cette fonction permet d'afficher tous le contenu du plateau les deux grilles des deux joueur
 *			 une grille cacher du joueur adversaire et l'autre afficher normale celle du joueur actuelle.
 * \param    joueur* joueur1 : le joueur  adversaire.
 * \param    joueur* joueur2 : le joueur actuelle.
 * \param    int cacher : une variable qui nous dit a ce que en fait un affichage cacher ou pas.
 */
void afficher(joueur* joueur1, joueur* joueur2, int cacher){
	int ligne, colonne, i;
	char* couleur;
    tableBoard(joueur2); // lLa fonction qui affiche des informations sur le resultat du jeu pour chaque joueur 
	couleur("47");couleur(RED);printf("\t\t  Plateau du joueur %s  ",joueur1->nom);couleur(WHITE);
	couleur("47");couleur(RED);printf("\t\t\t\t\t\t\t  Mon Plateau  %s \n",joueur2->nom);couleur(WHITE);
	// Afficher les numeros de colonne pour la grille de l'adversaire  (player 1)
	for(colonne = 1 ; colonne <= TAILLE_PLATEAU ; ++colonne)
		if(colonne < 10)
			printf("  %d ",colonne);
		else
			printf(" %d ",colonne);
	printf("      ");
	// Afficher les numeros de colonne pour la grille de jouer actuelle (player 2)
	for(colonne = 1 ; colonne <= TAILLE_PLATEAU ; ++colonne)
		if(colonne < 10)
			printf("  %d ",colonne);
		else
			printf(" %d ",colonne);
	printf("\n");

	for(ligne = 0 ; ligne < TAILLE_PLATEAU ; ++ligne){
		printf("-");
		for(i = 0 ; i < TAILLE_PLATEAU; i++)	
			printf("----");
		printf("     ");
		printf("-");
		for(i = 0 ; i < TAILLE_PLATEAU; i++)	
			printf("----");
		printf("\n");
        // Afficher la grille de l'adversaire (joueur1) en cachent les bateaux non toucher 
		for(colonne = 0 ; colonne < TAILLE_PLATEAU ; ++colonne)
				if(joueur1->plateau[ligne][colonne] == '#' && cacher == 1)
					printf("|   ");
				else if(joueur1->plateau[ligne][colonne] == 'X'){
					printf("| ");
					couleur = RED;
					compar(ligne, colonne, joueur1, 1, &couleur);
					couleur(couleur);
					printf("%c ",joueur1->plateau[ligne][colonne]);
					couleur(WHITE);
				}else{
					printf("| ");
					couleur(joueur1->color);
					printf("%c ",joueur1->plateau[ligne][colonne]);
					couleur(WHITE);
				}
		
		if(ligne + 1 < 10)
			printf("|  %d  ", ligne + 1);
		else
			printf("|  %d ", ligne + 1);
		// Afficher la grille du joueur acctuelle (joueur2)  
		for(colonne = 0 ; colonne < TAILLE_PLATEAU ; ++colonne)
				if(joueur2->plateau[ligne][colonne] == 'O')
					printf("|   ");
				else if(joueur2->plateau[ligne][colonne] == 'X'){
					couleur = RED;
					compar(ligne, colonne, joueur2, 1, &couleur);
					printf("| ");
					couleur(couleur);
					printf("%c ",joueur2->plateau[ligne][colonne]);
					couleur(WHITE);
				}else{
					couleur = joueur2->color;
					compar(ligne, colonne, joueur2, 0, &couleur);
					printf("| ");
					couleur(couleur);
					printf("%c ",joueur2->plateau[ligne][colonne]);
					couleur(WHITE);
				}
		printf("|\n");
	}
 
    printf("-");
	for(i = 0 ; i < TAILLE_PLATEAU; i++)	
		printf("----");
	printf("     ");
	printf("-");
	for(i = 0 ; i < TAILLE_PLATEAU; i++)	
		printf("----");
	printf("\n");
}

/**     
 * \details  Cette fonction permet d'afficher plusieur message d'indication selon la valeur de "int c".
 * \param	 joueur* player : le joueur.
 * \param    int cacher : une variable qui prend les valeurs 0, 1 , 2 et 3 .  
 */
void print(joueur* player, int c){
	fflush(stdin);
	if(c == 0){
		couleur(RED); printf("%s, appyer sur entreé pour continuer!!\n", player->nom);
		couleur(WHITE);
    	getchar();
	   CLEAR_SCREEN;
	}else if(c == 1){
		couleur("47"); couleur(RED);printf("%s",player->nom);
	    printf(", c'est ton tour de joue:\n---------------------------\n");
	    couleur(WHITE);		
	}else if(c == 2){
		printf("Le joueur ");
		couleur(player->color);printf("%s ",player->nom);
		couleur(WHITE);printf("à Gagner ^-^.\n");		
		printf("La partie est terminer.\nAppyer sur entreé pour revenir au menu principal!!");
    	getchar();
    	CLEAR_SCREEN;
	}else if(c == 3){
		printf("La partie Va Commencer.\nAppyer sur entreé pour continuer!!");
    	getchar();
    	CLEAR_SCREEN;
	}
}

/**    
 * \details  Cette fonction permet d'afficher les resultats de chaque joueur a chaque tour de jeu.   
 * \param    joueur* player : le joueur. 
 */
void tableBoard(joueur* player){
	int i;
	player->nbr_bateau_couler = 0;
	for (i = 0; i < NOMBRE_BATEAU; ++i){
		if(player->bat[i].nbr_case_toucher == player->bat[i].nbr_case_total){
			player->nbr_bateau_couler++;
			player->nbr_bateau_restant = NOMBRE_BATEAU - player->nbr_bateau_couler;
		}
	}
	couleur("45");
	printf("Nombre de bateau restant : %d 	Nombre de bateau couler : %d\n",player->nbr_bateau_restant,player->nbr_bateau_couler);
	printf("Nombre de tire reussi    : %d 	Nombre de tire manquer  : %d\n",player->nbr_tir_reussit,player->nbr_tir_manquer);
	couleur(WHITE);
}

/**
 * \details  Cette fonction permet de récuperer soit la couleur real du bateau c'est choix==0,
 *			 soit une autre  couleur c'est tous le bateau est toucher 
 * \param    int ligne : la ligne d'une case à tester.
 * \param    int colonne: la colonne d'une case à tester.
 * \param    joueur* player : le joueur actuelle.
 * \param    int choix : une variable qui nos sert à faire deux teste différent dans une fonction.
 * \param    char** couleur : une pointeur sur la variable couleur.
 */
void compar(int ligne, int colonne, joueur* player, int choix, char** couleur){
	int test, i;
	for (i = 0; i < NOMBRE_BATEAU; ++i){
		test = ((colonne >= player->bat[i].position_colonne) && (colonne < player->bat[i].position_colonne + player->bat[i].nbr_case_colonne)) 
		        &&((ligne >= player->bat[i].position_ligne) && (ligne < player->bat[i].position_ligne + player->bat[i].nbr_case_ligne));

		if(test && (player->bat[i].nbr_case_total == player->bat[i].nbr_case_toucher) && (choix == 1)){		
			*couleur = "40";
			break;
		}
		if(test && (choix == 0)){
			*couleur = player->bat[i].color;
			break;
		}
	}
}

/**
 * \file          affichage.c
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition de tous les fonction d'affichage
 *
 */