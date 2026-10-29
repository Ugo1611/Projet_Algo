//
// Created by ugogu on 29/10/2026.
//

#ifndef PROJET_ALGO_PRODUIT_H
#define PROJET_ALGO_PRODUIT_H
typedef struct  {
    char reference[12];
    char designation[60];
    char categorie[30];
    float prixUnitaireHT;
    int quantiteStock;
    int seuilAlerte;
    int actif;
}produit;

#endif //PROJET_ALGO_PRODUIT_H
