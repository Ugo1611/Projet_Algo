//
// Created by micae on 29/10/2026.
#ifndef PROJET_ALGO_COMMANDE_H
#define PROJET_ALGO_COMMANDE_H
#include  "types.h"

COMMANDE creerCommande(COMMANDE *commande, LigneCommande *lignecommande, CLIENT *client, DATE *date, ADRESSE *adresse, PRODUIT *produit);
COMMANDE modifierCommande(COMMANDE *commande, LigneCommande *lignecommande, CLIENT *client, DATE *date, ADRESSE *adresse, PRODUIT *produit, int * nb_ligne_produit, int * nb_client_commande);
COMMANDE supprimerCommande(COMMANDE *commande, LigneCommande *lignecommande, CLIENT *client, DATE *date, ADRESSE *adresse, PRODUIT *produit, int * nb_ligne_produit, int * nb_client_commande);
COMMANDE annulerCommande(COMMANDE *commande, CLIENT *client, DATE *date, ADRESSE *adresse, int * nb_ligne_commande);

#endif //PROJET_ALGO_COMMANDE_H
