#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;
} node;

node *head = NULL;
node *last = NULL;

void inrt_at_last(int);
void display();
void delete(node*);

int main()
{
    for (int i = 0; i <= 7; i++)
        inrt_at_last(i);

    display();
    delete(head);
    return 0;
}
void inrt_at_last(int data)
{
    node *newnode = malloc(sizeof(node));
    if (!newnode){
        printf("failed to allocate memory .");
        exit(1);

    }
    newnode->data = data;
    newnode->nxt = NULL;

    // NOW INSERTING AT LAST :)
    if (head == NULL)
    {
        head = newnode;
        // last = newnode;
    }
    else
        last->nxt = newnode;

    last = newnode;
    
}

void display()
{
    if (!head)
        printf("the list is empty");
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", (*temp).data);
            temp = temp->nxt;
        }
    }
}
// DELETE FROM LAST

void delete(node *head)
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