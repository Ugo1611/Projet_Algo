#ifndef PROJET_ALGO_CLIENT_H
#define PROJET_ALGO_CLIENT_H
#include "types.h"

Client ajouterClient(Client *client, Adresse *adresse);
Client modifierClient(Client *client,Adresse *adresse);
Client afficherClient(Client *client, Adresse *adresse);
Client supprimerClient(Client *client, Adresse *adresse);

#endif //PROJET_ALGO_CLIENT_H
