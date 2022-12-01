
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdbool.h>
#include <stddef.h>
#include "List/list.h"

typedef struct nodeEdge * Edge;
typedef struct graph * Graph;

//  #Crea una nueva instancia de un contenedor DGraph.
Graph createGraph(size_t, size_t);
//  #Retorna el número de vértices que existen en el grafo.
int sizeGraph(Graph);
// Retornar true si en el contendor DG, existe una arista entre los vértices:  'x' y 'y'.
bool adjacent(Graph, DATA, DATA);
// #Retorna los datos que se encuentran en los vértices y que son vecinos del vértice x. 
                                // Un vértice y es vecino de x, si existe una arista de x a y
List neighbors(Graph, DATA);
//  #Agrega un nuevo vértice x, si no existe en el grafo DG. 
void addVertex(Graph, DATA, DATA);
//  #Remueve el vértice x, si existe en el grafo DG.
void removeVertex(Graph, DATA);
//  #Agrega al grafo DG una arista z del vértice x al vértice y, si  no existe. 
void addEdge(Graph, DATA, DATA, DATA); 
//  #Regresa los datos guardados en el vertice
DATA getVertexData(Graph, DATA);
//  #Sobreescribe los datos existentes en el vertice
void setVertexData(Graph g1, DATA x, DATA dt);
//  #Remueve del grafo DG la arista del vértice x al vértice y, si existe.
void removeEdge(Graph, DATA, DATA);
//  #Regresa los datos en la arista de x a y
DATA getEdgeLabel(Graph, DATA, DATA);
//  #Sobreescribe los datos en la arista z  de x a y
void setEdgeLabel(Graph, DATA, DATA, DATA); 
    
#endif /* _GRAPH_H_ */