#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("commence\n");
    list * mylist = create_empty_list(3);
    print_all_list(mylist);
    printf("pas de bug ici 0\n");
    mylist = add_val_to_head(mylist,1,1);
    printf("pas de bug ici 1\n");
    mylist = add_val_to_head(mylist,2,2);
    printf("pas de bug ici 2\n");
    mylist = add_val_to_head(mylist,1,3);
    printf("pas de bug ici 3\n");
    mylist = add_val_to_head(mylist,3,4);
    printf("pas de bug ici 5\n");
    mylist = add_val_to_head(mylist, 1, 5);
    printf("pas de bug ici 6\n");
    mylist = add_val_to_head(mylist, 2, 6);
    printf("pas de bug ici 7\n");
    mylist = add_val_to_head(mylist, 1, 7);
    printf("pas de bug ici 8\n");

    printf("finis la\n");

    mylist = add_val_to_head(mylist, 0, 0);

    printf("fini ici\n");

    print_all_list(mylist);
    printf("fini\n");
    return 0;
}