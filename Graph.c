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

};

Graph createGraph(size_t bytesDT, size_t bytesID)
{
    Graph g1= malloc(sizeof(struct graph));
    if (g1!=NULL)
    {
        g1->bytesDT=bytesDT;
        g1->bytesID = bytesID;
        g1->len=0;
        //Lista para guardar todos los vertices
        g1->vertices=listCreate(sizeof(Vertex));

        
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
    //Comprobar si existe el graph
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

void deleteEdges(Vertex x)
{
    if (x!=NULL)
    {
        for (size_t i = 0; i < listSize(x->relations); i++)
        {
            Edge current=listGet(x->relations, i);
            free(current->ID);
            free(current);
            listRemove(x->relations, i);
            x->lenr--;
        }
        listDestroy(x->relations);
        
        return;
        
    }
    
}

void removeVertex(Graph g1, DATA x)
{
    if (g1!=NULL)
    {
        Vertex xVRTX= findVRTX(g1, x);
        if (xVRTX !=NULL)
        {
            // Buscar los vertices que tienen relacion de y a x
            for (size_t i = 0; i < listSize(g1->vertices); i++)
            {
                Vertex current = listGet(g1->vertices, i);
                if (current != xVRTX)
                {
                    // Buscar si existe una arista de y a x
                    if (adjacent(g1, current->ID, xVRTX->ID) == true)
                    {
                        // Eliminar
                        removeEdge(g1, current->ID, xVRTX->ID);
                    }
                    
                }
                
            }
            
            free(xVRTX->data);
            free(xVRTX->ID);
            g1->len--;
            printf("Vertice eliminado correctamente\n");
            return;
            
        }
        return;

        
    }
    return;
    
}

void removeEdge(Graph g1, DATA x, DATA y)
{
    Vertex xVRTX=findVRTX(g1, x);
    Vertex yVRTX=findVRTX(g1, y);
    if (xVRTX !=NULL && yVRTX!=NULL)
    {
        if (listSize(xVRTX->relations) >0 )
        {
            for (size_t i = 0; i < listSize(xVRTX->relations); i++)
            {
                //  Obtener las aristas y comparar los destinos
                Edge cmpr= listGet(xVRTX->relations, i);
                if (cmpr->destination == yVRTX)
                {   
                    free(cmpr->ID);
                    free(cmpr);
                    listRemove(xVRTX->relations, i);
                    xVRTX->lenr--;
                    printf("Relacion eliminada correctamente\n" );
                    return;
                }   
            }
            printf("No se encontró una realcion de X a Y\n");
            return;
        }
        else
        {
            printf("No existen relaciones en X\n");
            return;
        }
    }
    printf("No se encontro uno de los vertices dados\n");
    return;
}

DATA getEdgeLabel(Graph g1, DATA x, DATA y){
    if (g1 != NULL)
    {
        Vertex xVRTX = findVRTX(g1, x);
        Vertex yVRTX = findVRTX(g1, y);
        for (int i = 0; i < xVRTX->lenr; i++)
        {
            Edge current = listGet(xVRTX->relations, i);
            if (memcmp(current->destination->ID, yVRTX->ID, g1->bytesID) == 0)
            {
                return current->ID;
            }
        }
    }
    return NULL;
}

void setEdgeLabel(Graph g1, DATA x, DATA y, DATA l){
    if (g1 != NULL)
    {
        // Buscar los 
        Vertex xVRTX = findVRTX(g1, x);
        Vertex yVRTX = findVRTX(g1, y);
        for (int i = 0; i < xVRTX->lenr; i++)
        {
            // Buscar la arista
            Edge current = listGet(xVRTX->relations, i);
            if (memcmp(current->destination->ID, yVRTX->ID, g1->bytesID) == 0)
            {
                // Copy de los nuevos datos a la arista
                memcpy(current->ID, l, g1->bytesID);
                return;
            }
            printf("No existe la arista\n");
        }
    }
}

