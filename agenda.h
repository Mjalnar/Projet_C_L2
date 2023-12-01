//
// Created by david on 30/11/2023.
//

#ifndef PROJET_C_AGENDA_H
#define PROJET_C_AGENDA_H
typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct heure{
    int h;
    int min;
}heure;

typedef struct duree{
    int h;
    int min;
}duree;

typedef struct rdv{
    date date;
    heure heure;
    duree duree;
    char* objet;
    struct rdv *next;
}rdv;

typedef struct contact{
    char* nom_prenom;
    rdv* rdv;
    int nb_lvl;
    struct contact **next;
}cell;

typedef struct agenda{
    int max_lvl;
    struct contact** heads;
}agenda;



char *scanString(void);


#endif //PROJET_C_AGENDA_H
