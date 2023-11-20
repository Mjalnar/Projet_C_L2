#include "cell.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    list * mylist = create_empty_list(4);
    mylist = add_val_to_head(mylist,3,1);

    mylist = add_val_to_head(mylist,2,2);

    mylist = add_val_to_head(mylist,3,3);

    mylist = add_val_to_head(mylist,4,4);

    print_all_list(mylist);
    printf("fini\n");
    return 0;
}
