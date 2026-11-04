#ifndef PROJET_ALGO_CLIENT_H
#define PROJET_ALGO_CLIENT_H
#include "types.h"

void ajouterClient(BOUTIQUE *boutique);
void modifierClient(BOUTIQUE *boutique);
void afficherClient(BOUTIQUE boutique);
void supprimerClient(BOUTIQUE *boutique);
void rechercherClient(BOUTIQUE boutique);
void modifierAdresseClient(BOUTIQUE *boutique);
void afficherPointsFidelite(BOUTIQUE boutique);
void ajouterPointFidelite(BOUTIQUE *boutique);

#endif //PROJET_ALGO_CLIENT_H
