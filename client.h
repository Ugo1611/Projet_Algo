//
// Created by kanek on 28/10/2026.
//

#ifndef PROJET_ALGO_CLIENT_H
#define PROJET_ALGO_CLIENT_H
struct client
{
    int client;
    char nom[50];
    char prenom[50];
    char email[80];
    char telephone[15];
};

int pointsFidelite;
int nbCommandes;
int capaciteCommandes;
Commande* commande = NULL
int actif;

#endif //PROJET_ALGO_CLIENT_H
