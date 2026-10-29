//
// Created by micae on 29/10/2026.
#ifndef PROJET_ALGO_COMMANDE_H
#define PROJET_ALGO_COMMANDE_H
//include  "client.h"
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
    char statut[20];
    int nbLignes;
    int capaciteLignes;
}commande;

#endif //PROJET_ALGO_COMMANDE_H
