#include <stdio.h>
#include <stdlib.h>
#include "date.h"


int jour(DATE x){
    int d_jour = 31;
    if (x.mois == 2) {
        d_jour = 29;
    }
    if (x.jour >= 1 && x.jour <= d_jour) {
        return x.jour;
    }
    else {
        printf("Ce jour n'existe pas");
        exit(0);
    }
    return 0;
}

int mois(DATE x) {
    if (x.mois >= 1 && x.mois <= 12) {
        jour(x);
        return x.mois;
    }
    else {
        printf("Ce mois n'existe pas");
        exit(0);
    }
    return 0;
}

int annee(DATE x) {
    if (x.annee >= 2000 && x.annee <= 2100) {
        mois(x);
        if (x.mois == 2 && x.jour == 29) {
            if ((x.annee % 4 != 0 && x.annee % 100 != 0)) {
                printf("Ce jour n'existe pas");
                exit(0);
            }
        }
        return x.annee;
    }
    else {
        printf("Cette année n'existe pas");
        exit(0);
    }
    return 0;
}
