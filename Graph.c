#include "Graph.h"
#include "List\list.h"
#include "Stack/stack.h"
// #include "Container



struct vertex
{
    int ID;
    DATA data;
    // Lista que guarda las relaciones del nodo o vertice
    List relations;
};

typedef struct vertex * Vertex;

struct nodeEdge{
    Vertex source;
    Vertex destination;
};

struct graph
{
    size_t bytes;
    int len;
    // Lista que guarda a todos los vertices del grafo
    List vertices;
    // Lista de listas que guardan las relaciones de todos los nodos o vertice
    List relations;
    // Ultimo ID asignado
    int last_id;
    // Stack con los ID eliminados
    Stack recycleID;

};

int idCompare(DATA d1, DATA d2)
{
    Vertex n1=d1, n2=d2;
    if (n1->ID > n2->ID)
    {
        return 1;
    }
    else if (n1->ID < n2->ID)
    {
        return -1;
    }
    else return 0;
}

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

Graph createGraph(size_t bytes)
{
    Graph g1= malloc(sizeof(struct graph));
    if (g1!=NULL)
    {
        g1->bytes=bytes;
        g1->len=0;

        //Lista para guardar todos los vertices
        g1->vertices=listCreate(sizeof(Vertex));
        // Lista para las relaciones de todos los vertices
        g1->relations=listCreate(sizeof(List));
        // Ultimo ID registrado
        g1->last_id=0; 
        // Stack de ID para reutilizar
        g1->recycleID=stackCreate(sizeof(int));
        
        return g1;
    }
    return NULL;
    
}

int sizeGraph(Graph g1){
    if(g1 != NULL)
        return g1 -> len;
    return NULL;
}

bool adjacent(Graph g1, Vertex x, Vertex y)
{
    List relV1= listGet(g1->relations, x->ID);
    short * relation= (short *) listGet(relV1, y->ID);
    if ( *relation == 1)
    {
        return true;
    }
    return false;
}

List neighbors(Graph g1, Vertex x)
{
    
}



