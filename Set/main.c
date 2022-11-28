#include "set.h"
#include <stdio.h>
#include <stdlib.h>

int intcmp(DATA num1, DATA num2)
{
    int *n1=num1, *n2=num2;
    if (*n1 > *n2)
    {
        return 1;
    }
    else if (*n1< *n2)
    {
        return -1;
    }
    else return 0;
    
    
}


int main()
{
    int *ptr=malloc(sizeof(int));
    *ptr=22;
    Set s1 = setCreate(intcmp, sizeof(int));
    printf("Dir set: %p\n", s1);

    addSet(s1, ptr);

    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    *ptr=15;
    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    *ptr=16;
    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    *ptr=666;
    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    *ptr=777;
    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    // Repeated number
    *ptr=22;
    addSet(s1, ptr);
    printf("Add %d\n",*ptr );
    printf("Size: %d\n",setSize(s1));

    *ptr=666;
    removeSet(s1, ptr);
    // Check if 22 is in the set after delete
    *ptr=22;
    if (containSet(s1, ptr) == true)
    {
        printf("Si esta %d\n", *ptr);
    }
    else{
        printf("No esta %d\n", *ptr);
    }
    










    return 0;
}