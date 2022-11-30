#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Graph grafo=createGraph(sizeof(int) , sizeof(char));
    int n1=10, n2 = 20, n3=30, size = sizeGraph(grafo);
    // Id sera un entero
    char id1='A', id2 = 'B', id3 = 'C' ,id4= 'D', id5='E';
    
    // Grafo sin nada
    printf("Size Graph:%d\n",size);

    // Agregar vertice 1
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);

    // Agregar vertice 2
    addVertex(grafo,&n2,&id2);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    
    // Agregar vertice 3
    addVertex(grafo,&n3,&id4);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);

    adjacent(grafo, &id1, &id2);

    addEdge(grafo, &id1, &id2, &id3);

    adjacent(grafo, &id1, &id2);

    addEdge(grafo, &id1, &id4, &id5);

    adjacent(grafo, &id1, &id4);
    
    List VC1=neighbors(grafo, &id1);

    for (size_t i = 0; i < listSize(VC1); i++)
    {
        printf("VC1 dt: %d\n", *(int *)listGet(VC1, i));
    }
    List VC2=neighbors(grafo, &id2);

    DATA d1=getVertexData(grafo, &id1);
    printf("DATA 1: %d\n", *(int *) d1);

    int temp=100;
    setVertexData(grafo, &id1, &temp);

    d1=getVertexData(grafo, &id1);
    printf("DATA 1: %d\n", *(int *) d1);

    DATA label=getEdgeLabel(grafo, &id1, &id2);
    printf("Lablel: %c\n", *(char *) label);

    //CombrobaciÃ³n getEdgeLabel y setEdgeLabel
    label=getEdgeLabel(grafo, &id1, &id2);
    printf("Lablel: %c\n", *(char *) label);

    char tempEdge='F';
    setEdgeLabel(grafo, &id1, &id2, &tempEdge);

    label=getEdgeLabel(grafo, &id1, &id2);
    printf("Lablel: %c\n", *(char *) label);
    
    return 0;
}