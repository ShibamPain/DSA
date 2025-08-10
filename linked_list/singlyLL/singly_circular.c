#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nxt;

} node;

node *head = NULL, *tail = NULL;
void inrt_at_begin(int);
node *makenode(int);
void display();
void delete(node *);

int main()
{
    for (int i = 1; i <= 10; i++)
        inrt_at_begin(i);

    display();
    delete(head);
    display();

    return 0;
}

void inrt_at_begin(int data)
{
    node *newnode = makenode(data);

    // NOW I HAVE TO INSERT THIS NODE AT THE BEGGINING BUT THIS IS CIRCULAR
    if (!head)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->nxt = head;
        head = newnode;
    }
    tail->nxt = newnode;
}

void display()
{
    if (head == NULL)
        printf("empty list");
    else
    {
        node *temp = head;
        while (temp->nxt != head)
        {
            printf("%d ", (*temp).data);
            temp = temp->nxt;
        }
        printf("%d", temp->data);
    }
}
void delete(node *curr) // delete(head)
{
    if (curr == NULL) // BASE CONDITION..:)
        return;
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    while (head != tail)
    {
        node *current = curr; // current = head = address od 1st node

        node *address_of_next_node = (*current).nxt; // address_of_next_node = address of 2nd node

        free(current); // free the 1st node
        head = address_of_next_node;
        tail->nxt = address_of_next_node;
        delete(address_of_next_node);
    }
}
// MAKING NEW NODE

node *makenode(int data)
{
    node *newnode = malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    newnode->data = data;
    newnode->nxt = NULL;
    return newnode;
}