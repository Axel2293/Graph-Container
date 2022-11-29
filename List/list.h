#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef void * DATA;

typedef struct list * List;

//Creates the list and initialices all the values in 0 or NULL
List listCreate(size_t);
unsigned int listSize(List);
void listAdd(List, DATA);
DATA listGet(List, int);
void listSet(List, int, DATA);
DATA listRemove(List, int);




#endif /*_LIST_H_*/