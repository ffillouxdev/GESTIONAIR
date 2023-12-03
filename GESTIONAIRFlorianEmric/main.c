#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*modules*/
#include "vol.h"
#include "passager.h"
#include "retard.h"
#include "critere_recherches.h"


int main()
{
    printf("Entrez le nom du fichier : ");
    char filename[50], *a;
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n");

    printf("Entrez l'heure : ");
    int hour;
    scanf("%d", &hour);
    getchar();

    generation_tab(&hour, filename);

    return 0;
}
 /* exemple d'element struct Passager
    Passager p1 = {"Filloux", "Florian", "07/02/2004", 1, 503.65};
    //printf("%s | %s | %s | %d | %.2lf", p1.nom, p1.prenom, p1.date_naiss, p1.numero_siege, p1.prix_billet);*/
