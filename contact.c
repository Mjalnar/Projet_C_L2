//
// Created by david on 05/12/2023.
//

#include "contact.h"
#include <stdlib.h>
#include "stdio.h"
#include "agenda.h"

// Crée un contact vide avec un nombre spécifié de niveaux
contact* create_empty_contact(int level){
    contact* new_contact = (contact*)malloc(sizeof(contact));

    if (new_contact == NULL) {
        printf("Allocation de mémoire pour le contact a échoué.\n");
        return NULL;
    }

    new_contact->next = (contact**)malloc(sizeof(contact*) * level);

    if (new_contact->next == NULL) {
        printf("Allocation de mémoire pour les niveaux du contact a échoué.\n");
        free(new_contact); // Libère la mémoire si l'allocation échoue
        return NULL;
    }

    // Crée un rendez-vous vide pour le contact
    new_contact->rdv = create_empty_rdv();

    new_contact->nb_lvl = level;
    new_contact->nom_prenom = NULL;
    for(int i = 0; i < level; i++){
        new_contact->next[i] = NULL;
    }

    return new_contact;
}

// Crée un contact avec des données renseignées par l'utilisateur
contact* create_contact(){
    int ans;
    // Crée un contact vide avec 4 niveaux par défaut
    fflush(stdout);
    contact* new_contact = create_empty_contact(4);
    fgetc( stdin );

    // Demande et enregistre le nom et prénom du contact
    printf("\nNom Prenom : ");
    fflush(stdout);
    new_contact->nom_prenom = scanString();
    fgetc( stdin );

    // Demande à l'utilisateur s'il souhaite ajouter un rendez-vous au contact
    printf("Voulez-vous ajouter un nouveau rendez-vous ?\n1. Oui\n2. Non\n");
    fflush(stdout);
    scanf(" %d", &ans);
    fgetc( stdin );

    // Si l'utilisateur choisit "oui", crée un rendez-vous et l'ajoute au contact
    if(ans == 1)
        new_contact->rdv = add_rdv_to_head(new_contact->rdv, create_rdv());

    return new_contact;
}

void free_contact(contact* my_contact) {
    // Libère la mémoire du nom/prénom du contact
    if (my_contact->nom_prenom != NULL) {
        free(my_contact->nom_prenom);
        my_contact->nom_prenom = NULL;
    }

    // Libère la mémoire des niveaux de contacts s'ils ont été alloués dynamiquement
    if (my_contact->next != NULL) {
        free(my_contact->next);
        my_contact->next = NULL;
    }

    // Libère la mémoire du rendez-vous associé au contact
    if (my_contact->rdv != NULL) {
        free_rdv(my_contact->rdv);
        my_contact->rdv = NULL;
    }

    // Libère la mémoire du contact lui-même
    free(my_contact);
}


