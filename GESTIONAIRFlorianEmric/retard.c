#include "retard.h"


// Fonction en plus pour afficher les retards en cours avant le tri
void afficherRetardActuel(Vol *vols, int taille, int heureActuelle){
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        /* on affiche seulement le numero du vol, l'heure a laquelle il est sencé décollé,
        la compagnie, son etat de vol*/
        printf("\n| Numero de vol | Heure decollage attendue | Compagnie | Etat vol |\n");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < taille ; i++){
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") != 0) {
                printf("| %d | %d | %s | %s |\n",
                       vols[i].numeroVol,
                       vols[i].heure_decollage,
                       vols[i].etat_vol,
                       vols[i].compagnie
                );
                printf("------------------------------------------------------------------------------------------\n");
            }
        }
    }else {
        printf("Il n'y a pas de retards, c'est du jamais vu!");
    }
}

// Fonction qui recupere toutes les données de l'état de vol de chaque vol (structure Vol)
int recupDonneesRetard(const char *etat_vol){
    // convertisseur des min de retards dans le bon format 60min appliqué a l'heure de décollage
    int minRetard;
    sscanf(etat_vol, "Retarde (%d min)", &minRetard);
    return minRetard;
}

// Fonction qui convertit la somme du retard et de l'heure de décollage en heures
int readapteHeures(int heure_decollage, int retard) {
    // Permet de readapter la somme décimale en heure au format HHMM
    int h = heure_decollage / 100;
    int mm = heure_decollage % 100;

    // Ajout du retard aux minutes
    int mm2 = mm + retard;

    // Ajustement des heures si les minutes dépassent 60
    if (mm2 >= 60) {
        h = h + 1;
        mm2 = mm2 - 60;
    }

    int readapt = (h * 100) + mm2;
//    printf("%d %d %d\n", heure_decollage, retard, readapt);
    return readapt;
}

void reprogrammationRetard(Vol *vols, int taille, int heureActuelle){
    for(int i = 0; i < taille ; i++){
        // On regarde si le vol n'a pas etait déjà reprogrammer
        if (strstr(vols[i].etat_vol, "Retarde") && !strstr(vols[i].etat_vol, "Reprogramme")) {
            int minRetard = recupDonneesRetard(vols[i].etat_vol); // on recupere les min du %s et on le met en %d
            if(vols[i].heure_decollage <= 2159){
                vols[i].heure_decollage = readapteHeures(vols[i].heure_decollage, minRetard); // on ajoute son retard à son heure de décollage
                strcpy(vols[i].etat_vol, "Reprogramme"); // on met son etat de vol a reprogramme
            } else {
                // conditions qui annule les vols si ils sont au dessus de 2200 (qu'est ce qu'on fait de ces vols?)
                strcpy(vols[i].etat_vol, "Annule");
            }
        }
    }
}

//Fonction qui remet 5min a tout le monde si des vols n'ont pas un intervalle correct

void afficherReprogrammation(Vol *vols, int taille, int heureActuelle){
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        /* on affiche seulement le numero du vol, l'heure a laquelle il est sencé décollé,
        la compagnie, son etat de vol*/
        printf("\n| Numero de vol | Heure decollage reprogramme | Compagnie | Etat vol |\n");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < taille ; i++){
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") != 0) {
                printf("| %d | %d | %s | %s |\n",
                       vols[i].numeroVol,
                       vols[i].heure_decollage,
                       vols[i].compagnie,
                       vols[i].etat_vol
                );
                printf("------------------------------------------------------------------------------------------\n");
            }
        }
    }else {
        printf("Il n'y a pas de retards, c'est du jamais vu!");
    }
}


/*Vol *vols, int taille, int indiceTab,int heureActuelle*/