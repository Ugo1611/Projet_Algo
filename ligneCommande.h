//
// Created by ugogu on 29/10/2026.
//

#ifndef PROJET_ALGO_LIGNECOMMANDE_H
#define PROJET_ALGO_LIGNECOMMANDE_H
include  "client.h"
typedef struct
{
    int numero;
    int idClient;
    float montantBrutHT;
    float tauxRemise;
    float montantRemise;
    float montantHT;
    float montantTVA;
    float montantTTC;
    float fraisPort;
}commande;
typedef struct {
    int jour;
    int mois;
    int annee;
}date;
char statut[20];
int nbLignes;
int capaciteLignes;
struct Lignecommande
{
    char refProduit[12];
    char designation[60];
    int quantite;
    float prixUnitaireHT;
    float sousTotalHT;
};
#endif //PROJET_ALGO_LIGNECOMMANDE_H
