#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    list* mylist = creer_liste_pour_n(3);
    printf("\n");
    print_all_list(mylist);

    /* int choix;
     while (choix !=0) {
         printf("Choisissez une option :\n");
         printf("\n1. Creer une liste\n");
         printf("2. Quiter\n");

         scanf(" %d", &choix);
         int n, val;
         if (choix == 1) {
             printf("\nChoisissez un nombre de niveau : ");
             scanf(" %d", &n);
             list *mylist = create_empty_list(n);
             while (choix != 0) {
                 printf("\n1. Ajouter une cellule\n");
                 printf("2. Afficher liste\n");
                 scanf(" %d", &choix);
                 if (choix == 1) {
                     printf("\nChoisisez un nombre de niveau : ");
                     scanf(" %d", &n);
                     printf("\nChoisissez une valeur : ");
                     scanf(" %d", &val);
                     mylist = add_val_to_head(mylist, n, val);
                 }
                 if (choix == 2) {
                     print_all_list(mylist);
                 }
                 if (choix == 3) {
                     return 0;
                 }
             }
         }
         if (choix == 2) {
             return 0;
         }*/




    /*
    printf("commence\n");
    list * mylist = create_empty_list(8);
    mylist = add_val_to_head(mylist, 8, 6);

    printf("pas de bug ici 0\n");
    mylist = add_val_to_head(mylist,3,1);
    printf("pas de bug ici 1\n");
    mylist = add_val_to_head(mylist,2,2);
    printf("pas de bug ici 2\n");
    mylist = add_val_to_head(mylist,3,3);
    printf("pas de bug ici 3\n");
    mylist = add_val_to_head(mylist,4,4);
    printf("pas de bug ici 4\n");
    mylist = add_val_to_head(mylist, 5, 5);



    printf("finis la\n");

    mylist = add_val_to_head(mylist, 0, 0);

    printf("fini ici\n");

    print_all_list(mylist);
    printf("fini\n");
    return 0;*/

}