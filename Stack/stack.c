#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// ========================== STACK
    //NODE OF STACK
struct nodeSTK
{
    DATA data;
    struct nodeSTK *prior;

};
    //POinter to node of stack
typedef struct nodeSTK * NodePS;

    //Container stack
struct stack
{
    NodePS top;
    int size;
    size_t bytes;
};

Stack stackCreate(size_t bytes)
{
    //Memory for all the elements in the struct stack
    Stack stk= malloc(sizeof(struct stack));

    if (stk!=NULL)
    {
        //Initialize in 0 and give size of data to get stored
        stk->bytes=bytes;
        stk->size=0;
        stk->top=NULL;
        return stk;
    }
    else
    {
        return NULL;
    }
    

}

int stackSize(Stack stk)
{
    if (stk!=NULL)
    {
        return stk->size;
    }
    else
    {
        return -1;
    }
    
}

bool stackisEmpty(Stack stk)
{
    if (stk != NULL)
    {
        if(stk->top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
    
}

DATA stackTop(Stack stk)
{
    if (stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            DATA ret=malloc(stk->bytes);
            memcpy(ret, stk->top->data, stk->bytes);
            return ret;
        }
        else 
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

NodePS newNode(DATA data, size_t bytes)
{
    NodePS new= malloc(sizeof(struct nodeSTK));
    new->data=malloc(bytes);
    memcpy(new->data, data, bytes);
    new->prior=NULL;
    return new;
}

void push(Stack stk, DATA data)
{
    if(stk!=NULL)
    {
        NodePS nd=newNode(data, stk->bytes);
        stk->size++;
        nd->prior=stk->top;
        stk->top=nd;
    }
    else
    {
        printf("Error: Stack is null");
    }
}

DATA pop(Stack stk)
{
    if(stk!=NULL)
    {
        if(stk->top!=NULL)
        {
            void *dataTemp=stk->top->data;

            NodePS new_top=stk->top->prior;
            free(stk->top);
            stk->top=new_top;
            stk->size--;
            return dataTemp;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void stackDestroy(Stack stk)
{

    // Destroy nodes
    if (stk!=NULL)
    {
        if(stk->top!=NULL && stk->size!=0)
        {
            for(int i=0; i<stk->size; i++)
            {
                // Save next node to destroy
                if(stk->top!=NULL)
                {
                    NodePS next_node=stk->top->prior;
                    //Destroy one at the top
                    free(stk->top->data);
                    free(stk->top);

                    //Make new top
                    stk->top=next_node;
                }
            }
        }
        //Delete stack
        free(stk);
    }
}