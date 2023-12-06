//
// Created by david on 05/12/2023.
//

#ifndef PROJET_C_CONTACT_H
#define PROJET_C_CONTACT_H

#include "rdv.h"

typedef struct contact{
    char* nom_prenom;
    rdv* rdv;
    int nb_lvl;
    struct contact **next;
}contact;


contact* create_empty_contact(int level);

#endif //PROJET_C_CONTACT_H
