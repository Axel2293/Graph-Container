#include "list.h"
#include <stdio.h>

int main(void)
{
    List l1=listCreate(sizeof(int));
    int num=10;
    listAdd(l1, &num);

    num=20;
    listAdd(l1, &num);

    num=30;
    listAdd(l1, &num);

    num=40;
    listAdd(l1, &num);

    int *n=listGet(l1, 3);
    printf("Num in indx[3]: %d\n", *n);

    n=listRemove(l1, 2);
    printf("Removed [2]: %d\n", *n);

    return 0;
}