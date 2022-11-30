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
        Vertex temp=malloc(sizeof(Vertex)); 
        temp=listGet(g1->vertices, i);
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
        //printf("REL1: %d\n", xVRTX->lenr);
        //printf("REL2: %d\n", yVRTX->lenr);
        if (xVRTX->lenr >0  || yVRTX->lenr>0)
        {
            for (size_t i = 0; i < listSize(xVRTX->relations); i++)
            {
                //printf("RELATIONS %d\n", listSize(xVRTX->relations));
                //  Obtener las aristas y comparar los destinos
                Edge cmpr= listGet(xVRTX->relations, i);
                if (cmpr->destination == yVRTX)
                {
                    printf("X tiene una relación con Y\n" );
                    return true;
                }   
            }
            printf("No se encontró una realcion de X a Y\n");
            return false;
        }
        else
        {
            printf("No existen relaciones\n");
            return false;
        }
    }
    printf("No se encontro uno de los vertices dados\n");
    return false;
    

}

Vertex createVertex(DATA d, size_t bytesDT, DATA ID, size_t bytesID){
    Vertex new = malloc(sizeof(struct vertex));
    new->data=malloc(bytesDT);
    memcpy(new->data, d, bytesDT);

    new->ID=malloc(bytesID);
    new->ID=memcpy(new->ID, ID, bytesID);
    
    new -> relations = listCreate(sizeof(Edge));
    //printf("\t List %p\n", new);
    new->lenr=0;
    return new;
}

void addVertex(Graph g1, DATA data, DATA ID){
    
    if(g1 != NULL){
        //Grafo vacio
        if(g1 -> len == 0){
            Vertex new=createVertex(data, g1->bytesDT, ID, g1->bytesID);
            // Añadir el vertice a la lista de vertices del grafo
            listAdd(g1 -> vertices, new);
            g1 -> len += 1; //Aumentar el tamaño del grafo
            printf("Vertice agregado al grafo \n");
            return;
        }
        //Grafo No vacio
        else{
            for (int i = 0; i < g1 -> len; i++){

                Vertex current = listGet(g1 -> vertices, i);
                if (memcmp(ID, current->ID, g1->bytesID) == 0){
                    printf("El vertice ya existe en el grafo\n");
                    return;
                }else
                {
                    Vertex new=createVertex(data, g1->bytesDT, ID, g1->bytesID);
                    listAdd(g1->vertices, new);
                    g1->len+=1;
                    printf("Vertice agregado al grafo \n");
                    return;
                }
                
            }
        }
    }
    return;
    //Combrobar si existe el graph
    //Cuando se cree el vertice se debe crear su lista
    //Asignarle un ID
}

void addEdge(Graph g1, DATA x, DATA y, DATA z){
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
            newEDG->ID=malloc(sizeof(g1->bytesID));
            //  Copy la data para la arista z
            memcpy(newEDG->ID, z, g1->bytesID);
            //  Registrar la arista en las relaciones de el vertice x
            xVRTX->lenr+=1;
            listAdd(xVRTX->relations, newEDG);
            //listAdd(g1->allrelations, newEDG);

            printf("Arista de x a y creada con exito\n");
            return;
        }
        printf("La relación de x a y ya existe\n");
        return;
        
    }
    printf("Error: Grafo no creado\n");
    return;
    
}


List neighbors(Graph g1, DATA x)
{
    Vertex xVRTX = findVRTX(g1, x);

    if(g1!=NULL)
    {
        if (listSize(xVRTX->relations)!=0)
        {
            List VC=listCreate(sizeof(DATA));
            for (int i = 0; i < xVRTX->lenr; i++)
            {
                Edge current = listGet(xVRTX->relations, i);
                listAdd(VC, current->destination->data);

            }
            printf("Hay relaciones\n");
            return VC;
        }
        printf("X no tiene vecinos\n");
        return NULL;
    }
    return NULL;
}

DATA getVertexData(Graph g1, DATA x)
{

    if (g1!=NULL)
    {
        Vertex xVRTX = findVRTX(g1, x);
        if (xVRTX !=NULL)
        {
            return xVRTX->data;
        }
        printf("No existe el vertice\n");
        return NULL;
        
    }
    return NULL;
    
}

void setVertexData(Graph g1, DATA x, DATA dt)
{
    if (g1!=NULL)
    {
        Vertex xVRTX = findVRTX(g1, x);
        if (xVRTX !=NULL)
        {
            memcpy(xVRTX->data, dt, g1->bytesDT);
            return;
        }
        printf("No existe el vertice\n");
    }

}


DATA getEdgeLabel(Graph g1, DATA x, DATA y){
    if (g1 != NULL)
    {
        Vertex xVRTX = findVRTX(g1, x);
        Vertex yVRTX = findVRTX(g1, y);
        for (int i = 0; i < xVRTX->lenr; i++)
        {
            Edge current = listGet(xVRTX->relations, i);
            if (memcmp(current->destination, yVRTX, g1->bytesID) == 0)
            {
                return current->ID;
            }
        }
    }
    return NULL;
}
