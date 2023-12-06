//
// Created by david on 05/12/2023.
//

#include "contact.h"
#include "stdlib.h"

contact* create_empty_contact(int level){

    contact* new_contact = (contact*)malloc(sizeof(contact));
    new_contact->next = (contact**)malloc(sizeof(contact *) * level);                                              //création du pointeur "new_cell" de type cell
    new_contact->rdv = create_empty_rdv();
    new_contact->nb_lvl = level;                                                                           //attribution d'une valeur level// allocation mémoire
    new_contact->nom_prenom = NULL;
    for(int i=0; i<level; i++){                                                                          //boucle pour initialiser les tetes
        new_contact->next[i] = NULL;                                                                      //à null.
    }
    
    return new_contact;
}
