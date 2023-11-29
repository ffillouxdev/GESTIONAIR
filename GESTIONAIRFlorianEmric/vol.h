#ifndef VOL_H_INCLUDED
#define VOL_H_INCLUDED

struct Vol
{
    int numero;
    char compagnie[100];
    char destination[100];
    int numComptoir_Enregistrement; //va de 1 à 10
    int heure_debut_Embarquement[4];
    int heure_fin_Embarquement[4]; // [4] pour le format HHMM
    int heure_decollage[4];
    char etat_vol[20];
    char liste_passagers[200];
};

typedef struct Vol_ Vol;

#endif // VOL_H_INCLUDED
