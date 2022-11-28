#ifndef SET_H_
#define SET_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

typedef void * DATA;
typedef struct set *Set;
//Pointers to functions
typedef int (*Function)(DATA, DATA);

Set setCreate(Function, size_t);
int setSize(Set);
bool addSet(Set , DATA );
bool containSet( Set , DATA );
bool removeSet( Set , DATA);



#endif /*SET_H_*/