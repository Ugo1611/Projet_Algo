#ifndef PROJET_ALGO_DATE_H
#define PROJET_ALGO_DATE_H
#include "types.h"

typedef struct{
    int jour;
    int mois;
    int annee;
}DATE;

int jour(DATE x);
int mois(DATE x);
int annee(DATE x);

#endif //PROJET_ALGO_DATE_H
