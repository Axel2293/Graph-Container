#include "Graph.h"
#include "List\list.h"
#include "Stack/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
// #include "Container

int testID = 1;



struct vertex
{
    int ID;
    DATA data;
    // Lista que guarda las relaciones del nodo o vertice
    List relations;
};

struct edge
{
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
    List allRelations; //¿Es necesario?
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
        g1->allRelations=listCreate(sizeof(List));
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
    //revisar esta parte
    if(g1 != NULL){
        List relV1 = listGet(x->relations, x->ID); //Obtener la lista de realciones de x
        List relV2 = listGet(g1 -> allRelations, y -> ID);   //Obtener la lista de relaciones de y
        short * relation= (short *) listGet(relV1, y->ID);
        if ( *relation == 1)
        {
        return true;
        }
        return false;
    }
    else{
        return NULL;
    }
    //Comprobar que graph existe
        //Si existe obtener la lista de relaciones del vertice x y del vertice y
        //Si en cualquiera de las dos listas se encuentra el ID del otro vertice
            //Retornar true
        //Sino retornar false




}

List neighbors(Graph g1, Vertex x)
{
    //Revisar la lista de relaciones del vertice x
    //Crear una nueva lista llamda info o algo asi xd
    //Almacenar la información de cada uno de sus vecinos en una lista
    //retonar la lista
}

Vertex createVertex(DATA d, size_t bytes){
        Vertex new = malloc(sizeof(struct vertex));
        new->data=malloc(bytes);
        memcpy(new->data, d, bytes);
        new-> ID = 0;
        new -> relations = NULL;
        return new;
}

void addVertex(Graph g1, Vertex x){
    if(g1 != NULL){

        //Grafo vacio
        if(g1 -> len == 0){
            //ID como los vamos a asignar?
            x -> ID = testID;
            //Crear lista
            x -> relations = listCreate(sizeof(List));
            // Añadir el vertice a la lista de vertices del grafo
            listAdd(g1 -> vertices, x);
            g1 -> len += 1; //Aumentar el tamaño del grafo
            testID += 1;
        }
        //Grafo No vacio
        for (int i = 0; i < g1 -> len; i++){

            Vertex current = listGet(g1 -> vertices, i);
            /*if (memcmp()){
                
            }*/
            
            /* code */
        }
        

    }
    return NULL;
    //Combrobar si existe el graph
    //Cuando se cree el vertice se debe crear su lista
    //Asignarle un ID
}

void addEdge(Graph g1, Vertex x, Vertex y, DATA d){
    //Comprobar que graph existe
    //comprobar con funcion adjacent que NO existe una arista
        /*Si no existe enlazar el source con el primer vertice
          Enlazar el destination con el segundo vertice 
          Agregar el ID del segundo vertice en la lista de relaciones del primer vertice
        */
    //Cuando agregemos la arista almacenaremos el ID del vertice destination en la lista de relaciones del source


}
