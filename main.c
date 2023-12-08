/*
==============================================================================
Nom du projet         : Projet_C_L2
Auteurs               : WATINE DAVID, BOUAOU Sohaïb, BAURY Lucas
Date de création      : 21/10/2023
Dernière modification : 08/12/2023
Description           : Projet de deuxième année en école d'ingénieur,
                        qui consiste à creer un agenda de contact et de
                        rendez-vous à partir de liste à niveaux.
==============================================================================
*/


#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"
#include "menu.h"
#include "agenda.h"

int main() {

    //rdv * myrdv = create_rdv();
    //print_rdv(myrdv);
/*
    agenda* myagenda = create_empty_agenda(4);
    myagenda = tri_new_contact(myagenda);
    printf("quelle contact cherchez-vous");
    fflush(stdout);
    char *nom = scanString();
    fgetc( stdin );
    contact* mycontact = search_contact(*myagenda, nom);
    print_rdv(mycontact->rdv);
    //myagenda = tri_new_contact(myagenda);
    //myagenda = tri_new_contact(myagenda);

    print_all_agenda(myagenda);
    free_agenda(myagenda);
*/





    int choix;
    printf("Choisisez votre partie : ");
    scanf(" %d", &choix);

    if (choix == 1){
        menu_partie_1();
    }
    if (choix == 2){
        menu_partie_2();
    }
    if (choix == 3){
        menu_partie_3();
    }

}