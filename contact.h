//
// Created by david on 05/12/2023.
//

#ifndef PROJET_C_CONTACT_H
#define PROJET_C_CONTACT_H

#include "rdv.h"

// Structure représentant un contact avec des rendez-vous
typedef struct contact{
    char* nom_prenom;    // Nom et prénom du contact
    rdv* rdv;            // Rendez-vous du contact
    int nb_lvl;          // Nombre de niveaux pour les liaisons entre contacts
    struct contact **next;  // Pointeurs vers les contacts suivants selon les niveaux
} contact;


contact* create_empty_contact(int level);

#endif //PROJET_C_CONTACT_H
