#ifndef ENFANTPRIORITAIRE_H_INCLUDED
#define ENFANTPRIORITAIRE_H_INCLUDED

struct enfant_Prioritaire
{
    int age; // l'enfant a moins de 12 ans
    char nom[30];
    char prenom[30];
    int numero_siege[2];
    double prix_billet[]; //prise en compte des centimes
};

#endif // ENFANTPRIORITAIRE_H_INCLUDED
