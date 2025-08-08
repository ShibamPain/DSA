// THIS GIVES SEGMENTATION FAULT IN ONLINE COMPILER BUT IN GCC IT WORK PROPERLY 
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data ;
    struct Node *nxt ;
}node;

node *head = NULL;
node *tail = NULL;
int nodecount = 0;

node *makenode(int);
void inrt_at_begin(int);
void inrt_at_last(int);
void inrt_at_anyposition(int,int);
void display();
void deleteLast();


int main()
{
    for(int i=1;i<=10;i++)
        inrt_at_begin(i);
        inrt_at_anyposition(17,3);
    display();
    display();
    return 0;
}

node *makenode(int data)
{
    node *newnode = malloc(sizeof (node));
    if(!newnode)
    {
        printf("memory allocation failed .");
        exit(1);
    }

    newnode->data=data;
    newnode->nxt=NULL;

    return newnode;
}

void inrt_at_begin(int data)
{
    node *newnode = makenode(data);
    nodecount++;

    // NOW I HAVE TO INSERT THIS NODE AT THE BEGGINING

    (*newnode).nxt = head;
    head = newnode;

    if(!tail)
        tail = newnode; //THIS IS WORK WHEN THE LIST IS EMPTY AND I AM CREATE AND LINKED THE 1ST NODE
}

void inrt_at_last(int data)
{
    node *newnode = malloc(sizeof(node));
    if (!newnode){
        printf("failed to allocate memory .");
        exit(1);
    }
    nodecount++;

    newnode->data = data;
    newnode->nxt = NULL;

    // NOW INSERTING AT LAST :)
    if (head == NULL)
    {
        head = newnode;
    }
    else
        tail->nxt = newnode;

    tail = newnode;
    
}

void inrt_at_anyposition(int data,int position)
{
    
    
    if(position <0 || position > nodecount)
        printf("insert node is not possible .");
    else if (position == 0)
    {
        inrt_at_begin(data);
    }
    else if (position == nodecount)
    {
        inrt_at_last(data);
    }
    else
    {
        node *newnode =makenode(data);
        node *temp = head;
        for(int i=0;i<position-1;i++)
            temp =temp->nxt;

        newnode->nxt=temp->nxt;
        temp->nxt = newnode;
        nodecount++;
    }
}

void display()
{
    if (!head)
        printf("the list is empty ..");
    else
    {
        node *temp = head;
        while(temp)
        {
            printf("%d ",temp->data);
            temp = temp->nxt;
            tail = temp->nxt;
        }
    }
}

void deleteLast()
{
    if(head == NULL)
        printf("Not possible to delete..");
    else
    {
        node *temp = head;
        while(temp->nxt->nxt != NULL)
        {
            temp = temp->nxt;
        }
        free(temp->nxt);
        temp->nxt = NULL;
    }

}
