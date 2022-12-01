#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    Graph grafo=createGraph(sizeof(int) , sizeof(char));
    int n1=10, n2 = 20, n3=30, size = sizeGraph(grafo);
    // Id sera un entero
    char id1='A', id2 = 'B', id3 = 'C' ,id4= 'D', id5='E';
    
    printf("\n==========AGREGAR VERTICES=========\n");
    // Grafo sin nada
    printf("Size Graph:%d\n",size);

    // Agregar vertice 1
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);

    printf("Agregando repetido\n");
    addVertex(grafo,&n1,&id1);
    size=sizeGraph(grafo);
    

    // Agregar vertice 2
    addVertex(grafo,&n2,&id2);
    size=sizeGraph(grafo);
    printf("Size Graph:%d\n",size);
    
    // Agregar vertice 3
    addVertex(grafo,&n3,&id4);
    size=sizeGraph(grafo);
    printf("Size TOTAl: %d\n",size);

    printf("\n=========AGREGAR REALACIONES============\n");

    // Todavia no hay relaciones
    printf("Verificando relacion V1 a V2 (NO HAY)\n");
    adjacent(grafo, &id1, &id2);
    // Agregar arista de V1 a V2
    printf("Creando relacion V1 a V2\n");
    addEdge(grafo, &id1, &id2, &id3);
    // Verificar si la arista existe
    printf("Verificando relacion V1 a V2 (Ya existe)\n");
    adjacent(grafo, &id1, &id2);
    // Arista de V1 a V3
    printf("Creando relacion V1 a V3\n");
    addEdge(grafo, &id1, &id4, &id5);
    // Verificar la arista de V1 a V3
    printf("Verificando relacion V1 a V3 (Ya existe)\n");
    adjacent(grafo, &id1, &id4);
    
    printf("\n==========VECINOS V1 y V2===========\n");

    // Vecinos de V1
    printf("Vecinos V1 (Tiene 2)\n");
    List VC1=neighbors(grafo, &id1);
    for (size_t i = 0; i < listSize(VC1); i++)
    {
        printf("VC1 dt: %d\n", *(int *)listGet(VC1, i));
    }
    // Vecinos de V2 (No tiene)
    printf("Vecinos de V2 (no tiene)\n");
    List VC2=neighbors(grafo, &id2);

    printf("\n==========SOBRESCRIBIR DATOS V1==============\n");
    // Datos de V1
    DATA d1=getVertexData(grafo, &id1);
    printf("OLD DATA V1: %d\n", *(int *) d1);

    int temp=100;
    setVertexData(grafo, &id1, &temp);

    d1=getVertexData(grafo, &id1);
    printf("NEW DATA V1: %d\n", *(int *) d1);

    printf("\n========SOBRESCRIBIR LABEL ARISTA============\n");
    DATA label=getEdgeLabel(grafo, &id1, &id2);
    printf("OLD Label V1-V2: %c\n", *(char *) label);

    char tempEdge='F';
    setEdgeLabel(grafo, &id1, &id2, &tempEdge);

    label=getEdgeLabel(grafo, &id1, &id2);
    printf("NEW Label V1-V2: %c\n", *(char *) label);
    
    printf("\n==========ELIMINAR ARISTA==============\n");

    printf("Arista existe de V1 a V2\n");
    adjacent(grafo, &id1, &id2);
    printf("Eliminando arista de V1 a V2\n");
    removeEdge(grafo, &id1, &id2);
    printf("Verificando la arista eliminada V1 a V2\n");
    adjacent(grafo, &id1, &id2);

    printf("\n==========ELIMINAR VERTICE==============\n");

    printf("DATA of V3: %p\n", getVertexData(grafo, &id4));

    removeVertex(grafo, &id4);

    printf("NEW len: %d\n", sizeGraph(grafo));

    printf("DATA of V3: %p\n", getVertexData(grafo, &id4));
    return 0;
}