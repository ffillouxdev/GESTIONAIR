#ifndef PASSAGER_H_INCLUDED
#define PASSAGER_H_INCLUDED

// Definition de la structure passager
struct Passager
{
    char nom[30];
    char prenom[30];
    char date_naiss[10]; // au format jj/mm/aaaa
    int numero_siege;
    double prix_billet; //prise en compte des centimes
};

typedef struct Passager Passager;

#endif // PASSAGER_H_INCLUDED
