#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*modules*/
#include "vol.h"


// Fonction pour lire les donn�es du fichier CSV et remplir le tableau de struct
void lireDonneesCSV(const char *nomFichier, Vol *vols, int *taille) {
    FILE *fichier = fopen(nomFichier, "r+");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
   }else{

    // on recupere ligne par ligne les infos du CSV
    char ligne[1100];
    fgets(ligne, sizeof(ligne), fichier);
    char *passager;

    //Pour extraire ensuite les infos grace � un sscanf
    *taille = 0;
    while(fgets(ligne, sizeof(ligne), fichier)){
        sscanf(ligne, "%d,%99[^,],%99[^,],%d,%d,%d,%d,%d,%d,%d,%19[^,],%*[^\n]",
        &vols[*taille].numeroVol,
        vols[*taille].compagnie, // unique
        vols[*taille].destination, // unique
        &vols[*taille].num_Comptoir_Enregistrement,
        &vols[*taille].heure_debut_Enregistrement,
        &vols[*taille].heure_fin_Enregistrement,
        &vols[*taille].salle_embarquement,
        &vols[*taille].heure_debut_Embarquement,
        &vols[*taille].heure_fin_Embarquement,
        &vols[*taille].heure_decollage,
        vols[*taille].etat_vol);

        // on va faire pareil pour les passagers sert a recuperer les infos entre la 1ere occu " et la 1ere occu " dans chaque ligne (ce qui correspond aux passagers)
        char *passagersStart = strchr(ligne, '\"');
        char *passagersEnd = strchr(passagersStart + 1, '\"');
        *passagersEnd = '\0'; // Pour remplacer le guillement fermant par le caractere nul
        char *passager = strtok(passagersStart + 1, "\";"); // strtok permet d'extraire des chaines de caract�res

        int i = 0;
        while (passager != NULL) {
            //printf("OK3 - Passager: %s\n", passager);

            // Assurez-vous que vous avez suffisamment d'espace pour les passagers
            if (i < MAX_PASSAGERS) {
                // Pour extraire les champs des passagers et les mettre
                int passagerResultats = sscanf(passager, "%99[^,],%99[^,],%9[^,],%d,%lf",
                    vols[*taille].passager[i].nom,
                    vols[*taille].passager[i].prenom,
                    vols[*taille].passager[i].date_naiss,
                    &vols[*taille].passager[i].numero_siege,
                    &vols[*taille].passager[i].prix_billet);
            }
            passager = strtok(NULL, "\";");
            i++;
        }
        (*taille)++;
    }
    fclose(fichier);
   }
}

void trierTab3heure(Vol *vols, int taille, int heureActuelle){
    // on va trier les vols qui sont dans les 3 heures qui suivent l'heure actuelle
    // on triera les vols par ordre croissant en premier

}


void afficherTabVol(Vol *vols, int taille){
    // on va afficher les vols qui sont dans les 3 heures qui suivent l'heure actuelle
    printf("| Heure decollage | Numero de vol | Compagnie | Destination | Numero comptoir d'enregistrement | Heure debut enregistrement | Heure fin enregistrement| Salle d'embarquement |Heure debut embarquement| Heure fin embarquement | Etat vol |\n");
    for(int i = 0; i < taille; i++){
        printf("| %d | %d | %s | %s | %d | %d | %d | %d | %d | %d | %s |\n",
            vols[i].heure_decollage,
            vols[i].numeroVol,
            vols[i].compagnie,
            vols[i].destination,
            vols[i].num_Comptoir_Enregistrement,
            vols[i].heure_debut_Enregistrement,
            vols[i].heure_fin_Enregistrement,
            vols[i].salle_embarquement,
            vols[i].heure_debut_Embarquement,
            vols[i].heure_fin_Embarquement,
            vols[i].etat_vol);
            printf("------------------------------------------------------------------------------------------\n");

    }
}

// tableau qui va prendre toutes les structures charg�
void generation_tab(int* heureActuelle, const char *fichierCSV ){
    Vol vols[TAILLE_TAB];
    int taille = 0;
    lireDonneesCSV(fichierCSV, vols, &taille);
    trierTab3heure(vols, taille, *heureActuelle);
    afficherTabVol(vols, taille);
}
