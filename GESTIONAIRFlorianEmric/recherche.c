#include "recherche.h"

void recherche_dest(const char *desti, int taille, Vol *vols) {
    int compt = 0;

    printf("| Ville | Compagnie | Heure | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < taille; i++) {
        if (strstr(vols[i].destination, desti) != NULL) {
            printf("|    %-10s |             %-20s | %-4d | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].destination,
                    vols[i].compagnie,
                    vols[i].heure_decollage,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
    }

    if (compt == 0) {
        deductionRecherche(1, desti, vols, taille);
    }
}

void recherche_compagnie(const char *comp, int taille, Vol *vols) {
    int compt = 0;

    printf("| Compagnie | Ville | Heure | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < taille; i++) {
        if (strstr(vols[i].compagnie, comp) != NULL) {
            printf("|             %-20s |    %-10s | %-4d | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].compagnie,
                    vols[i].destination,
                    vols[i].heure_decollage,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
    }

    if (compt == 0) {
        deductionRecherche(2, comp, vols, taille);
    }
}

void recherche_heurDecol(int decol, int taille, Vol *vols) {
    int compt = 0;

    printf("Voici les vols les plus proches que l'heure saisis \n");
    printf("| Heure | Compagnie | Ville | Numerovol | Comptoir | debutEnr | FinEnr | salle | debutEmb | finEmb | EtatVol |\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < taille; i++) {
        if ((vols[i].heure_decollage >= decol && (vols[i].heure_decollage - decol) <= 150) ||
            (((vols[i].heure_decollage - decol) >= -150) && ((vols[i].heure_decollage - decol) <= 150))) {
            printf("| %-4d |             %-20s |    %-10s | %-2d | %-2d | %-4d | %-4d | %d | %-4d | %-4d | %-17s|\n",
                    vols[i].heure_decollage,
                    vols[i].compagnie,
                    vols[i].destination,
                    vols[i].numeroVol,
                    vols[i].num_Comptoir_Enregistrement,
                    vols[i].heure_debut_Enregistrement,
                    vols[i].heure_fin_Enregistrement,
                    vols[i].salle_embarquement,
                    vols[i].heure_debut_Embarquement,
                    vols[i].heure_fin_Embarquement,
                    vols[i].etat_vol);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
        }
    }

    if (compt == 0) {
        char decolChar[20];
        sprintf(decolChar, "%d", decol);
        deductionRecherche(3, decolChar, vols, taille);
    }
}

void suggestionCorrection(const char *input, const char *suggestion) {
    printf("\nVouliez-vous dire : %s ?\n", suggestion);
}

void toLowerString(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

int compareStringsIgnoreCase(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower((unsigned char)*str1) != tolower((unsigned char)*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }

    // Si l'une des chaînes n'est pas arrivée à sa fin, elles ne sont pas égales
    return (*str1 == '\0' && *str2 == '\0');
}

void deductionRecherche(int typeDeRec, const char *saisie, Vol *vols, int taille) {
    // 1 correspond à la destination, 2 correspond à la compagnie, 3 à l'heure de decollage
    int i = 0, nbHeureSaisie, compteur = 0;

    // Convertir la saisie de l'utilisateur en minuscules
    char saisieMinuscule[50];
    strcpy(saisieMinuscule, saisie);
    toLowerString(saisieMinuscule);

    if (typeDeRec == 1 || typeDeRec == 2) {
        for (i = 0; i < taille; i++) {
            // Convertir la chaîne dans la structure Vol en minuscules
            char destinationMinuscule[50];
            char compagnieMinuscule[50];
            strcpy(destinationMinuscule, vols[i].destination);
            strcpy(compagnieMinuscule, vols[i].compagnie);
            toLowerString(destinationMinuscule);
            toLowerString(compagnieMinuscule);

            const char *deducMot = NULL;
            if (typeDeRec == 1) {
                deducMot = strstr(destinationMinuscule, saisieMinuscule);
            } else if (typeDeRec == 2) {
                deducMot = strstr(compagnieMinuscule, saisieMinuscule);
            }

            if (deducMot != NULL && strstr(deducMot, saisieMinuscule) != NULL) {
                suggestionCorrection(saisie, vols[i].compagnie); // Utiliser le nom de la compagnie
                return;
            }
        }
    } else if (typeDeRec == 3) {
        nbHeureSaisie = atoi(saisie);
        printf("\nL'heure que vous avez saisie ne correspond pas à un vol.\n");
        for (i = 0; i < taille; i++) {
            if (vols[i].heure_decollage == nbHeureSaisie ||
                (vols[i].heure_decollage >= nbHeureSaisie - 5 && vols[i].heure_decollage <= nbHeureSaisie + 5)) {
                printf("Nous avons trouvé celui-ci par contre (dans une plage de 5min avant et après) : \n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("| Heure | Numero Vol | Destination |\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("| %-4d | %-2d | %-20s |\n",
                       vols[i].heure_decollage,
                       vols[i].numeroVol,
                       vols[i].destination
                );
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                compteur++;
            }
        }
        if (compteur == 0)
            printf("Il n'y a pas de vols dans un intervalle de 5 minutes avant et après.\n");
    }
}
