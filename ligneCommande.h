//
// Created by ugogu on 29/10/2026.
//

#ifndef PROJET_ALGO_LIGNECOMMANDE_H
#define PROJET_ALGO_LIGNECOMMANDE_H
include  "client.h"
Commande creerCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit);
Commande modifierCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit, int * nb_ligne_produit, int * nb_client_commande);
Commande supprimerCommande(Commande *commande, LigneCommande *lignecommande, Client *client, Date *date, Adresse *adresse, Produit *produit, int * nb_ligne_produit, int * nb_client_commande);
#endif //PROJET_ALGO_LIGNECOMMANDE_H
