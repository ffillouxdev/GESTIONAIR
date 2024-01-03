#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "recherche.h"
#include "vol.h"
#include "passager.h"
#include "retard.h"
#include "flyingplane.h"





int main()
{
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    // Calculez l'heure actuelle en format "minuteminuteheureheure"
    int heureActuelle = 1600;//tm_info->tm_hour * 100 + tm_info->tm_min;
    Vol vols[TAILLE_TAB];
    int taille = 0;

    char filename[50] = "data_vols.csv";
    //printf("Entrez le nom du fichier : ");
    //scanf("%s", &filename);
    lireDonneesCSV(filename, vols, &taille);
    trierTab(vols, taille);
    int quitter = 0;
    printf("\n\nBienvenue a l'aeroport Grenoble Alpes Isere \n\n\n\n");
    while (quitter == 0) {
        int choix = 0;  // Utiliser un entier pour stocker le choix de l'utilisateur
        int choix1 = 0;

        printf("------------ MENU ------------\n\n");
        printf(">>>> 1. Affichage des vols\n");
        printf(">>>> 2. Recherche des vols\n");
        printf(">>>> 3. Afficher liste des passagers\n");
        printf(">>>> 4. Affichage des retards/annulations\n");
        printf(">>>> 5. Quitter\n\n");
        printf("------------ MENU ------------\n\n");
        printf("Veuillez saisir votre choix\n");

        scanf("%d", &choix);

        // Traiter le choix de l'utilisateur avec des instructions if-else if-else
        if (choix == 1) {
                int choix1 = 0;
                printf(">>>> 1. Afficher les vols\n");
                printf(">>>> 2. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf("%d",&choix1);
                if(choix1 == 1){
                    afficherTabVol(vols, taille, heureActuelle);
                }
                else if(choix == 2){
                    quitter = 1;
                }
        }
        else if (choix == 2) {
                printf(" >>>> 1. Rechercher par destination\n");
                printf(" >>>> 2. Rechercher par compagnie\n");
                printf(" >>>> 3. Rechercher par heure de decollage\n");
                printf(" >>>> 4. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf("%d",&choix);
                if(choix == 1){
                    char destination[50];
                    printf("Entrer votre destination : ");
                    scanf("%s", &destination); // Mettre un fgets
                    recherche_dest(destination, taille,vols);
                }
                else if(choix == 2){
                    char compagnie[50];
                    printf("Entrer votre compagnie : ");
                    scanf("%s",&compagnie);

                    recherche_compagnie(compagnie, taille,vols);
                }
                else if(choix == 3){
                    int heurdecoll;
                    printf("Entrer votre heure de decollage : ");
                    scanf("%d",&heurdecoll);
                    recherche_heurDecol(heurdecoll,taille,vols);                }
                else if(choix == 4){
                    quitter = 1;
                }
        }

        else if (choix == 3) {
                printf(" >>>> 1. Affichage via le numero de vols\n");
                printf(" >>>> 2. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf("%d",&choix);
                if(choix == 1){
                }
                else if(choix == 2){
                    quitter = 1;
                }
        }
        else if (choix == 4){
                printf(">>>> 1. Choix d'affichage : retard/annulations :\n");
                printf(">>>> 2. Quitter\n");
                printf("Veuillez saisir votre choix\n");
                scanf("%d",&choix);
                if(choix == 1){
                    printf(" >>>> 1. Afficher la liste des retards actuels\n");
                    printf(" >>>> 2. Reprogrammer les retards\n");
                    printf(" >>>> 3. Optimiser la piste\n");
                    printf(" >>>> 4. Quitter\n");
                    printf("Veuillez saisir votre choix\n");
                    scanf("%d",&choix);
                    if(choix == 1){
                        afficherRetardActuel(vols, taille, heureActuelle);
                    }
                    else if(choix == 2){
                        reprogrammationRetard(vols, taille, heureActuelle);
                        afficherReprogrammation(vols, taille, heureActuelle);
                    }
                    else if(choix == 3){
                        OptimiserPiste(vols,taille);
                        affichagePlane();
                    }
                    else if(choix == 4){
                    quitter = 1;
                    }
                }
                else if(choix == 2){
                    quitter = 1;
                }
        }
         else if (choix == 5) {
            quitter = 1;
        } else {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    }

}
