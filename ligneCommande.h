//
// Created by ugogu on 29/10/2026.
//

#ifndef PROJET_ALGO_LIGNECOMMANDE_H
#define PROJET_ALGO_LIGNECOMMANDE_H
include  "client.h"
typedef struct
{
    char refProduit[12];
    char designation[60];
    int quantite;
    float prixUnitaireHT;
    float sousTotalHT;
}lignecommande;
#endif //PROJET_ALGO_LIGNECOMMANDE_H
