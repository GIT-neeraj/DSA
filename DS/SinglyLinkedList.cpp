#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printAllOptions()
{
    cout << "Select one option and hit enter:" << endl
         << endl;
    cout << "1. Print the linked list" << endl;
    cout << "2. Insert an element at the start of the list" << endl;
    cout << "3. Insert element at the end of the list" << endl;
    cout << "4. Insert element at the specified position in the linked" << endl;
    cout << "5. Delete the first element of the list" << endl;
    cout << "6. Delete the last element of the list" << endl;
    cout << "7. Delete an element from the specified position" << endl;
    cout << "8. Exit" << endl;
    cout << "______________________________________________________________________" << endl
         << endl;
}

void printTheList(Node *head)
{
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    Node *tempNode = head;
    while (tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

void insertElementAtStart(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    if ((*head) == NULL)
    {
        (*head) = newNode;
        (*head)->next = NULL;
    }
    else
    {
        newNode->next = (*head);
        (*head) = newNode;
    }
}

void insertElementAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if ((*head) == NULL)
    {
        (*head) = newNode;
    }
    else
    {
        Node *tempNode = (*head);
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
}

void insertElementAtPos(Node **head, int pos, int data)
{
    if ((*head) == NULL && pos == 1)
    {
        insertElementAtStart(&(*head), data);
        return;
    }
    if ((*head) == NULL && pos > 1)
    {
        cout << "Position is greater than the lenght of list" << endl;
        return;
    }
    Node *tempNode = (*head);
    int posCount = 1; //we're already at 1st node by being at head.
    while (tempNode != NULL && posCount != pos - 1)
    {
        tempNode = tempNode->next;
        posCount++;
    }
    if (posCount == pos - 1)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
    else
    {
        cout << "Position is greater than the lenght of list" << endl;
    }
}

void deleteElementAtStart(Node **head)
{
    if ((*head) == NULL)
    {
        cout << "List already empty" << endl;
        return;
    }
    Node *temp = (*head);
    (*head) = (*head)->next;
    delete temp;
}

void deleteElementAtEnd(Node **head)
{
    if ((*head) == NULL)
    {
        cout << "List already empty" << endl;
        return;
    }
    Node *tempNode = (*head);
    if (tempNode->next == NULL)
    {
        (*head) = NULL;
        delete tempNode;
        return;
    }
    while (tempNode->next->next != NULL)
    {
        tempNode = tempNode->next;
    }
    delete tempNode->next;
    tempNode->next = NULL;
}

void deleteElementAtPos(Node **head, int pos)
{
    if ((*head) == NULL)
    {
        cout << "List already empty" << endl;
        return;
    }
    if ((*head)->next != NULL && pos == 1)
    {
        deleteElementAtStart(&(*head));
        return;
    }
    Node *tempNode = (*head);
    int posCount = 1; //we're already at 1st node by being at head.
    while (tempNode->next != NULL && posCount != pos - 1)
    {
        tempNode = tempNode->next;
        posCount++;
    }
    if (posCount == pos - 1)
    {
        Node *deleteNode = tempNode->next;
        tempNode->next = tempNode->next->next;
        delete deleteNode;
    }
    else
    {
        cout << "Position is greater than the lenght of list" << endl;
    }
}

int main()
{
    Node *head = NULL;
    char option = '0';
    int data;
    int pos;
    while (option != 8)
    {
        printAllOptions();
        cout << "option: ";
        cin >> option;
        cout << endl;
        switch (option)
        {
        case '1':
            printTheList(head);
            break;

        case '2':
            cout << "Enter the element to insert: ";
            cin >> data;
            insertElementAtStart(&head, data);
            break;

        case '3':
            cout << "Enter the element to insert: ";
            cin >> data;
            insertElementAtEnd(&head, data);
            break;

        case '4':
            cout << "Enter the element to insert: ";
            cin >> data;
            cout << "Enter the position: ";
            cin >> pos;
            if (pos < 1)
            {
                cout << "Invalid position" << endl;
            }
            insertElementAtPos(&head, pos, data);
            break;

        case '5':
            deleteElementAtStart(&head);
            break;

        case '6':
            deleteElementAtEnd(&head);
            break;

        case '7':
            cout << "Enter the position: ";
            cin >> pos;
            if (pos < 1)
            {
                cout << "Invalid position" << endl;
            }
            deleteElementAtPos(&head, pos);
            break;

        default:
            cout << "Wrong input" << endl;
            break;
        }
        cout << endl
             << endl
             << endl;
    }
}