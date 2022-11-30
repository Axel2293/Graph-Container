
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdbool.h>
#include <stddef.h>
#include "List/list.h"

typedef struct nodeEdge * Edge;
typedef struct graph * Graph;
typedef struct vertex * Vertex;

// Crea una nueva instancia de un contenedor DGraph.
Graph createGraph(size_t, size_t);

Vertex createVertex(DATA, size_t, DATA, size_t);
// Retorna el número de vértices que existen en el grafo.
int sizeGraph(Graph);
// Retornar true si en el contendor DG, existe una arista entre los vértices:  'x' y 'y'.
bool adjacent(Graph, DATA, DATA);

// #Retorna los datos que se encuentran en los vértices y que son vecinos del vértice x. 
                                // Un vértice y es vecino de x, si existe una arista de x a y./
List neighbors(Graph, DATA);
//  #Agrega un nuevo vértice x, si no existe en el grafo DG. 
void addVertex(Graph, DATA, DATA);
//  #Remueve el vértice x, si existe en el grafo DG.
void removeVertex(Graph, DATA);
//  #Agrega al grafo DG una arista z del vértice x al vértice y, si  no existe. 
bool addEdge(Graph, DATA, DATA, DATA); 

//void removeEdge(DG, x, y) #Remueve del grafo DG la arista del vértice x al vértice y, si existe.

DATA getEdgeLabel(Graph, DATA, DATA);


#endif /* _GRAPH_H_ */