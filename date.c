#include <stdio.h>
#include <stdlib.h>
#include "date.h"


int jour(DATE x){
    if (x.mois == 2) {
        if (x.annee % 4 == 0) {
            if (x.jour >= 1 && x.jour <= 29) {
                return x.jour;
            }
            else {
                printf("Ce jour n'existe pas");
                exit(0);
            }
        }
        else {
            if (x.jour >= 1 && x.jour <= 28) {
                return x.jour;
            }
            else {
                printf("Ce jour n'existe pas");
                exit(0);
            }
        }
    }
    else {
        if (x.jour >= 1 && x.jour <= 31) {
            return x.jour;
        }
        else {
            printf("Ce jour n'existe pas");
            exit(0);

        }
    }
    return 0;
}

int mois(DATE x) {
    if (x.mois >= 1 && x.mois <= 12) {
        if (x.mois == 2) {
            if (x.annee % 4 == 0) {
                if (x.jour > 29) {
                    printf("Ce jour n'existe pas");
                    exit(0);
                }
                else {
                    return x.mois;
                }
            }
        }
        else {
            return x.mois;
        }
    }
    else {
        printf("Ce mois n'existe pas");
        exit(0);
    }
    return 0;
}

int annee(DATE x) {
    if (x.annee >= 2000 && x.annee <= 2100) {
        if (x.annee % 4 == 0) {
            jour(x);
        }
        else {
            return x.annee;
        }
    }
    else {
        printf("Cette année n'existe pas");
        exit(0);
    }
    return 0;
}
