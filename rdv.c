//
// Created by david on 05/12/2023.
//

#include "rdv.h"
#include "stdlib.h"
#include <stdio.h>
#include "agenda.h"

date *create_empty_date(){
    date* new_date = (date*)malloc(sizeof(date));
    return new_date;
}

heure *create_empty_heure(){
    heure* new_heure = (heure*)malloc(sizeof(heure));
    return new_heure;
}

duree *create_empty_duree(){
    duree* new_duree = (duree*)malloc(sizeof(duree));
    return new_duree;
}

rdv* create_empty_rdv(){
    rdv* new_rdv = (rdv*)malloc(sizeof(rdv));
    new_rdv->date = create_empty_date();
    new_rdv->heure = create_empty_heure();
    new_rdv->duree = create_empty_duree();
    new_rdv->objet = NULL;
    new_rdv->next = NULL;
    return new_rdv;
}


date *create_date(){
    date *new_date = create_empty_date();

    printf("\nEntrez la date (JJ/MM/AAAA) : ");
    //char *date_str = scanString();
    fflush(stdout);
    scanf( "%d/%d/%d", &(new_date->jour), &(new_date->mois), &(new_date->annee));
    fgetc( stdin );

    //free(date_str);

    return new_date;
}

heure *create_heure(){
    heure *new_heure = create_empty_heure();

    printf("\nEntrez l'heure (HH:MM) : ");
    //char *heure_str = scanString();
    fflush(stdout);
    scanf("%d:%d", &(new_heure->h), &(new_heure->min));
    fgetc( stdin );
    //free(heure_str);

    return new_heure;
}

duree *create_duree(){
    duree *new_duree = create_empty_duree();

    printf("\nEntrez la duree (HH:MM) : ");
    //char *duree_str = scanString();
    fflush(stdout);
    scanf("%d:%d", &(new_duree->h), &(new_duree->min));
    fgetc( stdin );
    //free(duree_str);

    return new_duree;
}

rdv *create_rdv(){
    rdv *new_rdv = create_empty_rdv();

    new_rdv->date = create_date();
    new_rdv->heure = create_heure();
    new_rdv->duree = create_duree();

    printf("\nEntrez l'objet du rendez-vous : ");
    fflush(stdout);
    new_rdv->objet = scanString();
    fgetc( stdin );

    return new_rdv;
}

//===================================================================================================================

void print_rdv(rdv* allrdv){
    if(allrdv == NULL){
        printf("\nAucun rendez_vous de prevu");
    }
    else{
        int i = 1;

            do{
                allrdv = allrdv->next;
                printf("\nRendez-vous numero %d", i);
                printf("\nDate : %d/%d/%d", allrdv->date->jour,allrdv->date->mois,allrdv->date->annee);
                printf("\nHeure : %d:%d", allrdv->heure->h,allrdv->heure->min);
                printf("\nDuree : %d:%d", allrdv->duree->h, allrdv->duree->min);
                printf("\nObjet : %s \n", allrdv->objet);
                i++;
            }while(allrdv->next != NULL);
    }
}

rdv *add_rdv_to_head(rdv* allrdv, rdv* newrdv){

    newrdv->next = allrdv->next;
    allrdv->next = newrdv;

    return allrdv;
}

void free_rdv(rdv* my_rdv) {
    // Libère la mémoire du rendez-vous lui-même
    free(my_rdv->date);
    free(my_rdv->heure);
    free(my_rdv->duree);
    free(my_rdv->objet);

    // Libère la mémoire du rendez-vous
    free(my_rdv);
}