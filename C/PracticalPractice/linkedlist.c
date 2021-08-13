#include <stdio.h>
#include <stdlib.h>

/*Things to implement:
    - Insert into function
    - Reverse function
    - Print the linked list
    https://www.youtube.com/watch?v=VOpjAHCee7c
*/ 


struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node node_t;


void printLinkedList(node_t* head)
{
    while(head->next != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("%d -> NULL", head->data);
}

int main()
{

    node_t n1, n2, n3;
    n1.data = 1, n2.data = 2, n3.data = 3;
    //We need a pointer, pointing to the node which is the head of our linked list.
    node_t* head;

    //Let us create a list:
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    //We now have a linked list: head -> 1 -> 2 -> 3 -> NULL

    printLinkedList(head);

    return 0;
}