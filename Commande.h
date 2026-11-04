//
// Created by micae on 29/10/2026.
#ifndef PROJET_ALGO_COMMANDE_H
#define PROJET_ALGO_COMMANDE_H
#include  "types.h"

COMMANDE creerCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit);
COMMANDE modifierCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit, int * nb_ligne_produit, int * nb_client_commande);
COMMANDE supprimerCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit, int * nb_ligne_produit, int * nb_client_commande);
COMMANDE annulerCommande(Commande *commande, Client *client, Date *date, Adresse *adresse, int * nb_ligne_commande);

#endif //PROJET_ALGO_COMMANDE_H
