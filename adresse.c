#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "adresse.h"

int CP_Valide(char *tab) {
    if (tab == NULL || strlen(tab) != 5) {
        return 0;
    }
    for (int i = 0; i < 5; i++) {
        if (tab[i] < '0' || tab[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int A_Valide(ADRESSE *tab) {
    if (tab == NULL) {
        return 0;
    }
    if (strlen(tab -> rue) == 0 || strlen(tab -> ville) == 0 || strlen(tab -> pays) == 0) {
        return 0;
    }
    return CP_Valide(tab -> codePostal);
}

void afficher(ADRESSE *tab) {
    if (tab != NULL) {
        printf("%s, %s, %s, %s", tab -> rue, tab -> codePostal, tab -> ville, tab -> pays);
    }
}
