#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    list * mylist = create_empty_list(4);
    mylist = add_val_to_head(mylist,1,1);
    printf("%d\n",mylist->heads[0]->value);
    mylist = add_val_to_head(mylist,1,2);
    printf("%d\n",mylist->heads[0]->value);
    mylist = add_val_to_head(mylist,4,6);
    printf("%d\n",mylist->heads[0]->value);
    mylist = add_val_to_head(mylist,1,5);
    printf("%d\n",mylist->heads[0]->value);
    mylist = add_val_to_head(mylist,3,4);
    printf("%d\n",mylist->heads[0]->value);
    print_lvl_list(mylist,1);
    print_all_list(mylist);
    printf("fini\n");
    return 0;
}
