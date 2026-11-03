#ifndef PROJET_ALGO_ADRESSE_H
#define PROJET_ALGO_ADRESSE_H
#include "types.h"

typedef struct
{
    char rue[80];
    char ville[50];
    char codePostal[8];
    char pays[50];
} ADRESSE;

int CP_Valide(char *tab);
int A_Valide(ADRESSE *tab);
void afficher(ADRESSE *tab);

#endif //PROJET_ALGO_ADRESSE_H
