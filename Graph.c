#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "Container

struct vertex
{
    DATA ID;
    DATA data;
    // Lista que guarda las relaciones del nodo o vertice
    List relations;
    int lenr;
};

typedef struct vertex * Vertex;

struct nodeEdge{
    DATA ID;
    Vertex source;
    Vertex destination;
};

typedef struct nodeEdge * Edge;

struct graph
{
    DATA ID;
    size_t bytesDT;
    size_t bytesID;
    int len;
    // Lista que guarda a todos los vertices del grafo
    List vertices;
    // Lista de listas que guardan las relaciones de todos los nodos o vertice
    List relations;
    // Ultimo ID asignado
    //int *last_id;
    // Stack con los ID eliminados
    //Stack recycleID;

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

Graph createGraph(size_t bytesDT, size_t bytesID)
{
    Graph g1= malloc(sizeof(struct graph));
    if (g1!=NULL)
    {
        g1->bytesDT=bytesDT;
        g1->bytesID = bytesID;
        //g1->ID=ID;
        g1->len=0;

        //Lista para guardar todos los vertices
        g1->vertices=listCreate(sizeof(Vertex));
        // Lista para las relaciones de todos los vertices
        //g1->allrelations=listCreate(sizeof(List));
        // Ultimo ID registrado
        //g1->last_id=malloc(sizeof(int));
        //*g1->last_id=-1; 
        // Stack de ID para reutilizar
        //g1->recycleID=stackCreate(sizeof(int));
        
        return g1;
    }
    return NULL;
    
}

int sizeGraph(Graph g1){
    if(g1 != NULL)
        return g1 -> len;
    return 0;
}

Vertex findVRTX(Graph g1, DATA ID)
{
    //Encontrar el Vertice con el ID
    for (size_t i = 0; i < listSize(g1->vertices); i++)
    {
        Vertex temp=listGet(g1->vertices, i);
        //  Comparar la memoria para determinar si los ID son iguales
        if (memcmp(ID, temp->ID, g1->bytesID) == 0)
        {
            return temp;
        }
        
    }
    return NULL;
}

bool adjacent(Graph g1, DATA x, DATA y)
{
    //Encontrar el Vertice x Y y
    Vertex xVRTX=findVRTX(g1, x);
    Vertex yVRTX=findVRTX(g1, y);

    if (xVRTX !=NULL && yVRTX!=NULL)
    {
        for (size_t i = 0; i < listSize(xVRTX->relations); i++)
        {
            //  Obtener las aristas y comparar los destinos
            Edge cmpr= listGet(xVRTX->relations, i);
            if (cmpr->destination == y)
            {
                printf("X tiene una relación con Y\n" );
                return true;
            }   
        }
        printf("No se encontró una realcion de X a Y\n");
        return false;
    }
    printf("No se encontro uno de los vertices dados\n");
    return false;
    

}

Vertex createVertex(DATA d, size_t bytesDT, DATA ID, size_t bytesID){
    Vertex new = malloc(sizeof(struct vertex));
    new->data=malloc(bytesDT);
    memcpy(new->data, d, bytesDT);

    // Aplicar logica de stack para el remove de vertices
    new->ID=malloc(bytesID);
    new->ID=memcpy(new->ID, ID, bytesID);
    
    new -> relations = listCreate(sizeof(Edge));
    new->lenr=0;
    return new;
}

bool addVertex(Graph g1, DATA data, DATA ID){
    
    if(g1 != NULL){
        Vertex new=createVertex(data, g1->bytesDT, ID, g1->bytesID);
        //Grafo vacio
        if(g1 -> len == 0){
            
            // Añadir el vertice a la lista de vertices del grafo
            listAdd(g1 -> vertices, new);
            g1 -> len += 1; //Aumentar el tamaño del grafo
        }
        //Grafo No vacio
        else{
            for (int i = 0; i < g1 -> len; i++){

                Vertex current = listGet(g1 -> vertices, i);
                if (memcmp(new->ID, current->ID, g1->bytesID) == 0){
                    printf("El vertice ya existe en el grafo\n");
                    return false;
                }
                listAdd(g1->vertices, new);
                g1->len+=1;
                printf("Vertice agregado al grafo\n");
                return true; 
            }
        }
    }
    return false;
    //Combrobar si existe el graph
    //Cuando se cree el vertice se debe crear su lista
    //Asignarle un ID
}

bool addEdge(Graph g1, DATA x, DATA y, DATA z){
    //Comprobar que graph existe
    //comprobar con funcion adjacent que NO existe una arista
        /*Si no existe enlazar el source con el primer vertice
          Enlazar el destination con el segundo vertice 
          Agregar el ID del segundo vertice en la lista de relaciones del primer vertice
        */
    //Cuando agregemos la arista almacenaremos el ID del vertice destination en la lista de relaciones del source
    Vertex xVRTX= findVRTX(g1, x);
    Vertex yVRTX= findVRTX(g1, y);

    if (g1!=NULL)
    {
        //Verificar que esa relación no exista de x a y
        if (adjacent(g1, x,y) == false)
        {
            //  Reservar memoria
            Edge newEDG= malloc(sizeof(struct nodeEdge));
            //  Registrar los vertices en la arista
            newEDG->source=xVRTX;
            newEDG->destination=yVRTX;
            //  Copy la data para la arista z
            memcpy(newEDG->ID, z, g1->bytesID);
            //  Registrar la arista en las relaciones de el vertice x
            xVRTX->lenr+=1;
            listAdd(xVRTX->relations, newEDG);
            //listAdd(g1->allrelations, newEDG);

            printf("Arista de x a y creada con exito\n");
            return true;
        }
        printf("La relación de x a y ya existe\n");
        return false;
        
    }
    printf("Error: Grafo no creado\n");
    return false;
    
}


/*List neighbors(Graph g1, DATA x)
{
    Vertex xVRTX = findVRTX(g1, x);
    if(g1!=NULL){
        for (int i = 0; i < xVRTX->lenr; i++)
        {
            Edge current = listGet(xVRTX->relations, i);
            return current->destination;
        }
    }
}

DATA getEdgeLabel(Graph g1, Vertex x, Vertex y){
    if (g1 != NULL)
    {
        Vertex xVRTX = findVRTX(g1, x);
        if (g1 != NULL)
        {
            Edge xEDG = listGet(xVRTX->relations, x->lenr);
            for (int i = 0; i < xVRTX->lenr; i++)
            {
                Edge current = listGet(xVRTX->relations, i);
                if (memcmp(current->source, xEDG->source, g1->bytesID) == 0 && memcmp(current->destination, xEDG->destination, g1->bytesID) == 0)
                {
                    return current->ID;
                }
            }
        }
    }
    return NULL;
}
*/