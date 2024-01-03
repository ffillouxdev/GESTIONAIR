#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "vol.h"

void toLowerString(char *str);
int compareStringsIgnoreCase(const char *str1, const char *str2);
void recherche_dest(const char *desti, int taille, Vol *vols);
void recherche_compagnie(const char *comp, int taille, Vol *vols);
void recherche_heurDecol(int decol, int taille, Vol *vols);
void deductionRecherche(int typeDeRec, const char *saisie, Vol *vols, int taille);
void suggestionCorrection(const char *input, const char *suggestion);

#endif // RECHERCHE_H_INCLUDED
