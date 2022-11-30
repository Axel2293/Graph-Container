#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Graph grafo=createGraph(sizeof(int) , sizeof(int));
    int n1=10, n2 = 20, n3=30, size = sizeGraph(grafo);
    // Id sera un entero
    int id1=1, id2 = 2, id3 = 3 ,id4=4 ;
    
    // Grafo sin nada
    printf("Size Graph:%d\n",size);

    // Agregar vertice 1
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    // Agregar vertice 1 repetido
    addVertex(grafo,&n2,&id2);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    // Agregar vertice 2
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    
    // Agregar vertice 3
    addVertex(grafo,&n3,&id4);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);

    adjacent(grafo, &id1, &id2);
    
    addEdge(grafo, &id1, &id2, &id3);

    adjacent(grafo, &id1, &id2);
    
    

    return 0;
}