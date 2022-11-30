#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Graph grafo=createGraph(sizeof(int) , sizeof(int));
    int n1=10, n2 = 20, size = sizeGraph(grafo);
    int id1=1, id2 = 2, id3 = 3 ;
    
    printf("Size Graph:%d\n",size);
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    addVertex(grafo,&n2,&id2);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);


    addEdge(grafo, &id1, &id2, &id3);

    return 0;
}