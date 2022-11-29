#include "Graph.h"
#include "Set/set.h""
// #include "Container



struct node
{
    int ID;
    DATA data;
    Set relations;
};

typedef struct node * Node;

struct graph
{
    size_t bytes;
    int len;
    Set nodes;
    int last_id;
};

int idCompare(DATA d1, DATA d2)
{
    Node n1=d1, n2=d2;
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
    g1->bytes=bytes;
    g1->len=0;

    //Create the set to store the nodes
    g1->nodes=setCreate(idCompare, bytes);
    g1->last_id=0;    
    return g1;
}







