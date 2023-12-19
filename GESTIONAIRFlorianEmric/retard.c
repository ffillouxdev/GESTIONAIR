#include "retard.h"


// Fonction en plus pour afficher les retards en cours avant le tri
void afficherRetardActuel(Vol *vols, int taille, int heureActuelle){
    if ( heureActuelle >= 600 && heureActuelle <=2200 ){
        /* on affiche seulement le numero du vol, l'heure a laquelle il est sencé décollé,
        la compagnie, son etat de vol*/
        printf("\n| Numero de vol | Heure decollage attendue | Compagnie | Etat vol |\n");
        printf("------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < taille ; i++){
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") == 1) { /* strcmp renvoie 0 si les chaines sont identiques, et 1 si elles sont differentes*/
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
        printf("soit il n'y a pas de retards, soit vous n'avez pas respecté l'heure du couvre feu!\n");
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
    //printf("%d %d %d\n", heure_decollage, retard, readapt);
    return readapt;
}


void reprogrammationRetard(Vol *vols, int taille, int heureActuelle){
    for(int i =0; i < taille ; i++){
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

    // for qui permet d'espacer les vols qui n'ont pas 5mins d'intervalle (la piste n'est pas forcement optimisé)
    for(int j = 1; j < taille; j++){
        if((vols[j].heure_decollage - vols[j - 1].heure_decollage) <= 5){
            vols[j].heure_decollage = vols[j - 1].heure_decollage + 5; // rajoute 5min pour avoir un intervalle de 5min entre les vols
            printf("%d\n", vols[j].heure_decollage);
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
        if (vols[i].heure_decollage >= heureActuelle && strcmp(vols[i].etat_vol, "A l'heure") == 1) {
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
        printf("soit il n'y a pas de retards, soit vous n'avez pas respecté l'heure du couvre feu!\n");
    }
}

void generationTabRetard(int *heureActuelle, int taille, Vol *vols){
    afficherRetardActuel(vols, taille, *heureActuelle);

    reprogrammationRetard(vols, taille, *heureActuelle);
    afficherReprogrammation(vols, taille, *heureActuelle);

    trierTab(vols, taille);
}


void OptimiserPiste(Vol *vols, int taille){
    if(vols[0].heure_decollage < 600){
        vols[0].heure_decollage = 600;
    }

    for(int i = 1; i < taille; i++){
        if((vols[i].heure_decollage - vols[i - 1].heure_decollage) > 6){
            vols[i].heure_decollage = vols[i - 1].heure_decollage + 5;
        }
    }

}
//Stabilité d’un algorithme: Un tri est dit “stable lorsqu’il ne change pas l’ordre relatif des quantités égales pour la relation d’ordre c’est à dire que si a et b sont deux éléments égaux et que a précède b dans le tableau initial alors a précède b dans le tableau trié.
