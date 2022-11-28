
#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node
{
    struct node *left;
    struct node *right;
    DATA data;
};

typedef struct node * Node;

struct set
{
    Node top;
    size_t bytes;
    Function fptr;
    int len;
};

typedef struct set *Set;

// Creates the set container
Set setCreate(Function fptr, size_t bytes)
{
    Set new=malloc(sizeof(struct set));
    if (new!=NULL)
    {
        new->fptr=fptr;
        new->bytes=bytes;
        new->len=0;
        new->top=NULL;
        return new;
    }
    else
    {
        return NULL;
    }
    
}
// Returns the size of the set in int
int setSize(Set s1)
{
    if (s1!=NULL)
    {
        return s1->len;
    }
    else
    {
        return -1;
    }
    
}
// adds an element to the set
bool addSet(Set s1, DATA data)
{
    Node current=s1->top;

    //If set is empty 
    if (s1->top==NULL)
    {
        Node new=malloc(sizeof(struct node));
        new->data=malloc(s1->bytes);
        memcpy(new->data, data, s1->bytes);
        new->left=NULL;
        new->right=NULL;
        s1->top=new;
        s1->len++;
        return true;
    }
    
    Node prior=NULL;
    while (current!=NULL)
    {
        //Compare data to determine where to go(Left of right)
        
            //If data is greater than the one in the current node then 
            //Go right
        if (s1->fptr(data, current->data) == 1)
        {
            prior=current;
            current=current->right;
            if (current==NULL)
            {
                //Register data in the prior node from the right
                Node new=malloc(sizeof(struct node));
                new->data=malloc(s1->bytes);
                memcpy(new->data, data, s1->bytes);
                new->left=NULL;
                new->right=NULL;
                prior->right=new;
                s1->len++;
                return true;
            }
            
        }
            //If data in current is greater than the given data
            //Go left
        else if(s1->fptr(data, current->data) == -1)
        {
            prior=current;
            current=current->left;
            if (current==NULL)
            {
                //Register data in the prior node from the left
                Node new=malloc(sizeof(struct node));
                new->data=malloc(s1->bytes);
                memcpy(new->data, data, s1->bytes);
                new->left=NULL;
                new->right=NULL;
                prior->left=new;
                s1->len++;
                return true;
            }
        }
            //If data are equal
        else
        {
            return false;
        }   
    }
    
}
// Checks if the given element its on the set
bool containSet( Set s1, DATA data)
{
    Node current=s1->top;
    if (current==NULL)
    {
        return false;
    }
    
    while (current!=NULL)
    {
        // If data is equal
        if (s1->fptr(data, current->data)==0)
        {
            return true;
        }
        // If given data is grater than the one in current go right
        else if (s1->fptr(data, current->data)==1)
        {
            current=current->right;
        }
        // If given data is lower than the one in current go left
        else if (s1->fptr(data, current->data)==-1)
        {
            current=current->left;
        }
        
        
    }
    return false;
    
}



bool removeSet( Set s1, DATA data)
{
    // Check first if data is in the set
    if (containSet(s1, data) == false)
    {
        return false;
    }
    
    Node current=s1->top;
    Node prior=NULL;
    while (current!=NULL)
    {
        // Search for the node with the data
        if (s1->fptr(data, current->data)==0)
        {
            // Node doesnt have left or right childs (just Delete)
            if (current->left== NULL && current->right==NULL)
            {
                free(current->data);
                free(current);
                if (prior!=NULL)
                {
                    if (prior->left==current)
                    {
                        prior->left=NULL;
                    }
                    else
                    {
                        prior->right=NULL;
                    }
                    
                }
                // Current is the actual top
                else
                {
                    s1->top=NULL;
                }
                s1->len--;
                return true;
                
            }
            // Node has only one child
                // Child on the left
            else if (current->left!=NULL && current->right==NULL)
            {
                Node swap=current->left;
                if (prior!=NULL)
                {
                    if (prior->left==current)
                    {
                        prior->left=swap;
                    }
                    else
                    {
                        prior->right=swap;
                    }
                }
                // Current is the actual top
                else
                {
                    s1->top=swap;
                }
                free(current->data);
                free(current);
                s1->len--;
                return true;

            }
                // Child on the right 
            else if (current->right!=NULL && current->left==NULL)
            {
                Node swap=current->right;
                if (prior!=NULL)
                {
                    if (prior->left==current)
                    {
                        prior->left=swap;
                    }
                    else
                    {
                        prior->right=swap;
                    }
                    
                }
                // Current is the actual top
                else
                {
                    s1->top=swap;
                }
                free(current->data);
                free(current);
                s1->len--;
                return true;
            }
                // Has two childs
                // Search on the left the greater element
                    // Swap only the data
            else if (current->right!=NULL && current->left!=NULL)
            {
                Node del=current,priororg=prior, greater=NULL, next= NULL;
                // Move left to left root
                current=current->left;
                
                // first left has a higher value on the right
                if (current->right!=NULL)
                {
                    // Move right
                    while (current->right!=NULL)
                    {
                        prior=current;
                        current=current->right;
                    }
                    greater=current;

                    // In case there is a child in the greater element we got on the left
                    if (greater->left != NULL)
                    {
                        prior->right=greater->left;
                    }

                    // Swap data
                    free(del->data);
                    del->data=greater->data;
                    free(greater);
                    s1->len--;
                    return true;
                }
                // Doesnt have any higher values (Make first left the replacement)
                else 
                {
                    // Node to delete is the top
                    if (del == s1->top)
                    {
                        s1->top=current;
                    }
                    current->right=del->right;
                    free(del);
                    free(del->data);
                    s1->len--;
                    return true;
                    
                }
            } 
        }
        // If given data is grater than the one in current go right
        else if (s1->fptr(data, current->data)==1)
        {
            prior=current;
            current=current->right;
        }
        // If given data is lower than the one in current go left
        else if (s1->fptr(data, current->data)==-1)
        {
            prior=current;
            current=current->left;
        }
    }
    return false;
    
    

}

