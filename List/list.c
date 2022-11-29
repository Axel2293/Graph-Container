#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node
{
    struct node *next;
    struct node *prior;
    DATA data;
};

typedef struct node * Node;

struct list
{
    Node first;
    Node last;
    unsigned int size;
    size_t bytes;
};

List listCreate(size_t bytes)
{
    List new=malloc(sizeof(struct list));
    new->bytes=bytes;
    new->first=NULL;
    new->last=NULL;
    new->size=0;
    return new;
}

unsigned int listSize(List l1)
{
    if (l1 != NULL)
    {
        return l1->size;
    }
    else
    {
        return 0;
    }
    
}

Node nodeCreate(DATA data, size_t bytes)
{
    Node new=malloc(sizeof(struct node));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    new->next=NULL;
    return new;
}

void listAdd(List l1, DATA data)
{
    if (l1 != NULL)
    {
        Node new=nodeCreate(data, l1->bytes);
        if (listSize(l1) == 0)
        {
            l1->first=new;
            l1->last=new;
            l1->size++;
        }
        else
        {
            new->prior=l1->last;
            l1->last->next=new;
            l1->last=new;
            l1->size++;
        }
    }
    else
    {
        printf("Error, list not created");
    }
    
}

DATA listGet(List l1, int indx)
{
    //Validate existance of list and range of given indx
    if (l1 == NULL)
    {
        return NULL;
    }
    else if (indx>= l1->size || indx<0)
    {
        return NULL;
    }

    Node current=l1->first;
    for (size_t i = 0; i < l1->size; i++)
    {
        if (i==indx)
        {
            DATA get=malloc(l1->bytes);
            memcpy(get, current->data, l1->bytes);
            return get;
        }
        else
        {
            current= current->next;
        }
        
    }
    return NULL;
    




    
    
}

void listSet(List l1, int indx, DATA data)
{
    if (l1!=NULL)
    {
        if (l1->size<=indx && indx>=0)
        {
            Node current=l1->first;
            int i=0;
            //Move to desired index
            while (i<indx)
            {
                current=current->next;
                i++;
            }
            //Copy the data on the index
            memcpy(current->data, data, l1->bytes);
            
        }
        else
        {
            printf("Index fuera del rango\n");
        }
        
    }
    else
    {
        printf("List not created\n");
    }
    
}

DATA listRemove(List l1, int indx)
{
    if (l1 != NULL)
    {
        if (indx>=0 && indx<l1->size)
        {
            //One element at the list
            if (l1->size==1)
            {
                DATA temp=l1->first->data;
                free(l1->first);
                l1->first=NULL;
                l1->last=NULL;
                l1->size--;
                return temp;
            }
            //More than one element
            else 
            {
                
                //Remove the first one
                if (indx==0)
                {
                    DATA temp=l1->first->data;
                    Node next=l1->first->next;
                    free(l1->first);
                    l1->first=next;
                    l1->first->prior=NULL;
                    l1->size--;
                    return temp;
                }
                //Remove the last one
                else if (indx == l1->size-1)
                {
                    DATA temp=l1->last->data;
                    Node prior=l1->last->prior;

                    free(l1->last);
                    l1->last=prior;
                    prior->next=NULL;
                    return temp;
                }
                //Between other elements
                else
                {
                    Node current=l1->first;
                    int i=0;

                    while (i<indx)
                    {
                        current=current->next;
                        i++;
                    }
                    DATA temp=current->data;

                    Node next=current->next;
                    Node prior=current->prior;

                    free(current);

                    next->prior=prior;
                    prior->next=next;

                    return temp;
                    
                }
                return NULL;
                
                
            }
            
            
        }
        else
        {
            return NULL;
        }
        
    }
    else
    {
        printf("List not created\n");
        return NULL;
    }
    
}




