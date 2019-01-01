#include "header.h"

/**      
 * \details   Cette fonction permet d'afficher le menu principale du jeu.
 */
void menu(){
char* nom1;
char* nom2;
nom1 = malloc(20*sizeof(char));
nom2 = malloc(20*sizeof(char));
srand(time(NULL));
joueur* joueur1;
joueur* joueur2;
int choix,n;
do{
  CLEAR_SCREEN;
  printf("\t\t\033[42mBATAILLE NAVALE\033[0m\n");
  printf("\033[35m----------------------------------------------------------\n");
  printf("\033[35m|\033[33m1-\033[32mPartie :\033[34m Humain vs Humain\033[37m                           \033[35m|\n");
  printf("\033[35m|\033[33m2-\033[32mPartie :\033[34m Ordi vs Ordi\033[37m                         \033[35m|\n");
  printf("\033[35m|\033[33m3-\033[32mPartie :\033[34m Humain vs Ordi\033[37m                         \033[35m|\n");
  printf("\033[35m|\033[33m4-\033[32mPartie :\033[34m Humain vs Humain Partier Avancer de n coupe\033[37m  \033[35m|\n");
  printf("\033[35m|\033[33m5-\033[31mQuitter                                               \033[35m|\n");
  printf("----------------------------------------------------------\n");
  printf("\033[37mChoisir Dans Le Menu :");

  do {
    scanf("%d",&choix);
  }while((choix != 1)&&(choix != 2)&&(choix != 3)&&(choix != 4)&&(choix != 5));
  CLEAR_SCREEN;
  switch (choix) {
    case 1:{
      printf("Donner Le  Nom Du Joueur humain 1:");
      scanf("%s",nom1);
      joueur1 = initialisation(nom1,GREEN,0);

      printf("Donner Le  Nom Du Joueur humain 2:");
      scanf("%s",nom2);
      joueur2 = initialisation(nom2,YELLOW,0);
      
      printf("jnom1= %s   jnom2= %s\n",joueur1->nom,joueur2->nom);
      jeu(joueur1,joueur2);
    }
    break;
    case 2:{
      nom1 = "Ordi 1";
      joueur1 = initialisation(nom1,GREEN,1);
      nom2 = "Ordi 2";
      joueur2 = initialisation(nom2,YELLOW,1);
      jeu(joueur1,joueur2);
    }
    break;
    case 3:{
      printf("Donner Le  Nom Du Joueur humain:");
      scanf("%s",nom1);
      joueur1 = initialisation(nom1,GREEN,0);
      nom2 = "Ordi_Roi";
      joueur2 = initialisation(nom2,YELLOW,1);
      jeu(joueur1,joueur2);
    }
    break;
    case 4:{
      printf("Donner l'etape du jeu souhaité :");
      do {
        scanf("%d",&n);
      }while(n < 0);
      printf("Donner Le  Nom Du Joueur humain 1:");
      scanf("%s",nom1);
      joueur1 = initialisation(nom1,GREEN,0);
      printf("Donner Le  Nom Du Joueur humain 2:");
      scanf("%s",nom2);
      joueur2 = initialisation(nom2,YELLOW,0);
      jeuANCoup(joueur1,joueur2,n);
    }
    break;
    case 5:{
      printf("Au-revoir à La Prochaine fois ^-^  ^-^  ^-^ \n");
      system("exit");
    }
    break;
  }
}while(choix!=5);
}

/**
 * \file          menu.c
 * \author    B.Habib, A.Sofiane, I.Tinhinane, I.Chafia
 * \version   1.0
 * \date       07 Avril 2018
 *
 * \details    définition de a fonction menu
 *
 */