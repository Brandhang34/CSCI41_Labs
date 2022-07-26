// CSCI41Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

struct Node
{
    int data;
    struct Node* next;
};

#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node* next;
}*start;

class single_llist
{
public:
    node* getNode(int);
    void print();
    int size();
    void insertToFront(int);
    void insertToMiddle(int);
    void deleteATargetNode(int target);
    void deleteAllTargetNodes(int Target);
    single_llist()
    {
        start = NULL;
    }
};

Node* getNode(int data)
{
    // allocating space 
    Node* newNode = (Node*)malloc(sizeof(Node));

    // inserting the required data 
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

int size(Node* head)
{
    int count = 0; 
    Node* current = head; 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insertToFront(struct node** head_ref, int new_info)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->info = new_info;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertToMiddle (Node** head_ref, int x)
{
    if (*head_ref == NULL)
        *head_ref = getNode(x);
    else {
        Node* newNode = getNode(x);

        Node* ptr = *head_ref;
        int len = 0;

        while (ptr != NULL) {
            len++;
            ptr = ptr->next;
        }
        int count = ((len % 2) == 0) ? (len / 2) :
            (len + 1) / 2;
        ptr = *head_ref;

        while (count-- > 1)
            ptr = ptr->next;

        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void deleteATargetNode(struct node* head, struct node* n)
{
    if (head == n)
    {
        if (head->next == NULL)
        {
            printf("There is only one node. The list can't be made empty ");
            return;
        }
        head->info = head->next->info;
        n = head->next;
        head->next = head->next->next;
        free(n);
        return;
    }
}

void deleteAllTargetNodes(node* head)
{
    node* n, * store;
    n = head;
    while (n != NULL)
    {
        store = n->next;
        free(n);
        n = store;
    }
}

int main()

{

    struct node* head = NULL;

    /* Create following linked list

      12->15->10->11->5->6->2->3 */

    insertToFront(&head, 3);

    insertToFront(&head, 2);

    insertToFront(&head, 6);

    insertToFront(&head, 5);

    insertToFront(&head, 11);

    insertToFront(&head, 10);

    insertToFront(&head, 15);

    insertToFront(&head, 12);

    printf("Given Linked List: ");

    print(head);

    cout << size(head);


   

    printf("\nDeleting node %d: ", head->next->next->info);

    deleteATargetNode(head, head->next->next);

    printf("\nModified Linked List: ");

    print(head);

 

    printf("\nDeleting all Targeted nodes ");

    deleteAllTargetNodes(head);

    printf("\nModified Linked List: ");

    print(head);

    getchar();

    return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
