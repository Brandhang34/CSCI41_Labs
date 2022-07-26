// CSCI41Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class DNode
{
public:
    DNode* next;
    DNode* prev;
    int data;
};

class DLL
{
private:
    DNode* front;
public:
    DLL()
    {
        front = NULL;
    }
    void print();
    void insertToFront(int data);
    void insertBeforeTarget(int target, int item);
    void deleteLastNode();
    void deleteFromFront();
    void deleteAllTargetNodes(int target);
};

void DLL::print()
{
    DNode* curr = front;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void DLL::insertToFront(int data)
{
    DNode* node = new DNode;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (front = NULL)
    {
        front = node;
    }
    else
    {
        node->next = front;
        node->prev = node;
        front = node;
    }
}
void DLL::insertBeforeTarget(int target, int data)
{
    DNode* node = front;
    node->data = data;
    node->next = node->prev;
    node->prev = node;

    if (node->prev != NULL)
    {
        node->prev->next = node;
    }

    if (front == node)
    {
        front = node;
    }
}

void DLL::deleteLastNode()
{
    DNode* node = front;
    while (node->next != NULL)
    {
        node = node->next;
    }
    DNode* store_prev = node->prev;
    store_prev->next = NULL;
    delete(node);
}

void DLL::deleteFromFront()
{
    if (front != NULL)
    {
        DNode* node = front;
        front = front->next;
        if (front != NULL)
        {
            front->prev = NULL;
        }
        delete(node);
    }
}

void DLL::deleteAllTargetNodes(int target)
{
    if (front != NULL)
    {
        while (front->data == target)
        {
            deleteFromFront();
        }
        DNode* curr = front;
        while (curr != NULL)
        {
            if (curr->data == target)
            {
                DNode* temp = curr;
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
                curr = curr->next;

                delete(temp);
            }
            else
                curr = curr->next;
        }
    }
}

class CLL
{
private:
    DNode* front;
public:
    CLL()
    {
        front = NULL;
    }
    void print();
    void insertToFront(int data);
    void insertAfterTarget(int target, int item);
    void deleteLastNode();
    void deleteFromFront();
    void deleteAllTargetNodes(int target);
};

void CLL::print()
{
    DNode* curr = front;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void CLL::insertToFront(int data)
{
    DNode* node = new DNode;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    if (front = NULL)
    {
        front = node;
    }
    else
    {
        node->next = front;
        node->prev = node;
        front = node;
    }
}
/*void CLL::insertAfterTarget(int target, int data)
{
    
}
*/
void CLL::deleteLastNode()
{
    DNode* node = front;
    while (node->next != NULL)
    {
        node = node->next;
    }
    DNode* store_prev = node->prev;
    store_prev->next = NULL;
    delete(node);
}

void CLL::deleteFromFront()
{
    if (front != NULL)
    {
        DNode* node = front;
        front = front->next;
        if (front != NULL)
        {
            front->prev = NULL;
        }
        delete(node);
    }
}

void CLL::deleteAllTargetNodes(int target)
{
    if (front != NULL)
    {
        while (front->data == target)
        {
            deleteFromFront();
        }
        DNode* curr = front;
        while (curr != NULL)
        {
            if (curr->data == target)
            {
                DNode* temp = curr;
                curr->prev->next = curr->next;
                if (curr->next != NULL)
                {
                    curr->next->prev = curr->prev;
                }
                curr = curr->next;

                delete(temp);
            }
            else
                curr = curr->next;
        }
    }
}

int main()
{
    DLL list;
    list.insertToFront(20);
    list.insertToFront(26);
    list.insertToFront(25);
    list.insertToFront(12);
    list.insertToFront(30);
    list.insertToFront(27);
    list.insertToFront(27);
    list.insertToFront(26);
    list.insertToFront(9);
    list.insertToFront(27);
    list.insertToFront(20);

    cout << "Initial DLL List : " << endl;
    list.print();

  //  cout << insertBeforeTarget(int target, int item);
    

    cout << "Delete Last node DLL : " << endl;
    list.deleteLastNode();
    list.print();

    cout << "List (After deleting 26) DLL : " << endl;
    list.deleteAllTargetNodes(26);
    list.print();

    cout << "List (After deleting duplicates) DLL : " << endl;

    list.print();

    CLL list2;
    list2.insertToFront(32);
    list2.insertToFront(4);
    list2.insertToFront(23);
    list2.insertToFront(21);
    list2.insertToFront(18);
    list2.insertToFront(9);
    list2.insertToFront(12);
    list2.insertToFront(30);
    list2.insertToFront(38);
    list2.insertToFront(27);
    list2.insertToFront(2);

    cout << "Initial CLL List : " << endl;
    list2.print();

    //cout << insertAfterTarget(int target, int item);


    cout << "Delete Last node CLL : " << endl;
    list2.deleteLastNode();
    list2.print();

    cout << "List (After deleting 12) CLL : " << endl;
    list2.deleteAllTargetNodes(12);
    list2.print();

    cout << "List (After deleting duplicates) CLL : " << endl;

    list2.print();

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
