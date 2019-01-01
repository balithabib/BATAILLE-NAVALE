#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h> 

/// Des macros qui nous permet d'afficher un texte en couleur passer en paramétre.
#define couleur(param) printf("\033[%sm",param)
#define RED "31"
#define GREEN "32"
#define BLUE "34"
#define YELLOW "33"
#define WHITE "0"
/// Des macros our supprimer l'écrans 
#ifdef __unix__
    #define CLEAR_SCREEN system("clear")
#elif defined _WIN32
    #define CLEAR_SCREEN system("cls")
#endif

#define TAILLE_PLATEAU  15 // TAILLE DU PLATEAU
#define NOMBRE_CASE_BATEAU 62 // NOMBRE DE CASE TOTAL POUR TOUS LES BATEAUX
#define NOMBRE_BATEAU 10 // NOMBRE TOTAL DE BATEAUX
/**
 * \brief     Structure qui représente un bateau
 */
struct bateau{
	char nbr_case_ligne;   /*!< Variable indiquant le nomre de cases par ligne */
	char nbr_case_colonne; /*!< Variable indiquant le nombre de cases par colonne */
	char position_ligne;   /*!< Variable indiquant la ligne exacte du bateau */
	char position_colonne; /*!< Variable indiquant la colonne exacte du bateau */
	char nbr_case_toucher; /*!< Variable indiquant le nombre de case toucher */
	char nbr_case_total;   /*!< Variable indiquant le nombre de case total */
	int normale;   /*!< Variable indiquant le nature du bateau */
	int type;      /*!< Variable indiquant le type du bateau */
	char* color;   /*!< Variable indiquant la couleur du bateau */
};
typedef struct bateau bateau;

/// Structure qui représente un joueur
struct joueur {
  char plateau[TAILLE_PLATEAU][TAILLE_PLATEAU]; // Tableau qui représent le plateau de chaque joueur
  char* nom;      /*!< Variable indiquant le nom du joueur */
  char* color;    /*!< Variable indiquant la color du joueur */
  int ia;         /*!< Variable indiquant la nature de joueur IA ou humain */
  bateau bat[10]; /*!< Tableau de bateau */
  //char tab_vie[NOMBRE_BATEAU]; /*!< Tableau comportant les points de vies restants des bateaux */
  char nbr_bateau_couler;  /*!< Variable indiquant le nombre bateau couler */
  char nbr_bateau_restant; /*!< Variable indiquant le nombre bateau restant */
  char nbr_tir_reussit;	   /*!< Variable indiquant le nombre de tirs réussis */
  int nbr_tir_manquer;	   /*!< Variable indiquant le nombre de tirs manqués */
};
typedef struct joueur joueur;

/// Une fonction qui affiche le menu du jeu
void menu(); 

/// Une fonction qui affiche le plateau de jeu 
void afficher(joueur*, joueur*, int);

/// Une fonction qui affiche différent messager de mise en forme dasn le jeu a l'aide d'un int donner comme argument  
void print(joueur*, int); 

/// Une fonction qui déroule le jeu
void jeu(joueur*, joueur*); 

 /// une fonction qui déroule jeu avancer de N coupe simuler
void jeuANCoup(joueur*, joueur*, int);

/// Une fonction qui affiche le resultat du joueur actuelle à chaque tour 
void tableBoard(joueur*); 

/// Une fonction qui fait l'initialisation de chaque joueur au début du jeu
joueur* initialisation(char*, char*, int);

/// Une fonction qui posision les bateau de la bonne façon à chaque debut de jeu apres l'initialisation 
joueur* positionementDesBateaux(joueur*);

/// Une fonction qui déroule le tour d'un jour 
joueur* tour(joueur*, joueur*); 

/// Une fonction qui vérifier la fin du jeu 
int gameOver(joueur*);

/// Une fonction qui récupere une couleur selon des conditions
void compar(int ligne, int colonne, joueur* player, int choix, char** couleur);