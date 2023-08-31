#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void append(Node **head_ref, int item);
void printList(Node **head_ref);

int main()
{

    Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printList(&head);

    return 0;
}

void append(Node **head_ref, int item)
{
    Node *new_node = new Node();
    new_node->data = item;
    new_node->next = NULL;

    Node *last = new Node();

    last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;

    return;
}

void printList(Node **head_ref)
{
    Node *temp = *head_ref;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
