#include "Graph.h"
#include "Set\set.h"
//#include "Container

struct nodeVertex{
    int index; //identificador de tipo int
    //int peso #si lo tuviera
    DATA data;
    //apuntador a la lista * list;
};

typedef struct nodeVertex * nodeV;

struct nodeEdge{
    nodeV source;
    nodeV destination;
};

struct DGraph{
    int size; //numero de nodos
    //int maxSize;
    size_t size_data;
    //matriz bidimencional #si se usa la matriz adyacente
};

nodeV newNode(DATA d, size_t bytes){
    nodeV new = malloc(sizeof(struct nodeVertex));
    //Clonamos el dato
    new -> data = malloc(bytes);
    memcpy(new -> data, d, bytes);
    

    return new;
}

DG createDGraph(size_t bytes){
    DG new = malloc(sizeof(struct DGraph));
    if(new != NULL){
        new -> size = 0;
        new -> size_data = bytes;
        //lista de adyacencia?

        return new;
    }
    else{
        return NULL;
    }
}

int sizeGraph(DG g){
    if(g != NULL)
        return g -> size;
    return NULL;
}