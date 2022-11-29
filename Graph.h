
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdbool.h>

typedef struct DGraph * DG;


DG createDGraph(size_t); //#Crea una nueva instancia de un contenedor DGraph. 

int sizeGraph(DG); //#Retorna el número de vértices que existen en el grafo. 

//bool adjacent(DG, x, y) #Retornar true si en el contendor DG, existe una arista entre los vértices:  'x' y 'y'. 

/*DATA neighbors(DG, x) #Retorna los datos que se encuentran en los vértices y que son vecinos del vértice x. 
                        Un vértice y es vecino de x, si existe una arista de x a y.*/

//void addVertex(DG, x) #Agrega un nuevo vértice x, si no existe en el grafo DG. 

//void removeVertex(DG, x) #Remueve el vértice x, si existe en el grafo DG.

//void addEdge(DG, x, y, z) #Agrega al grafo DG una arista z del vértice x al vértice y, si  no existe. 

//void removeEdge(DG, x, y) #Remueve del grafo DG la arista del vértice x al vértice y, si existe. 


#endif /* _GRAPH_H_ */