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

void deleteEvenNumbers(Node **head_ref);
int main()
{

    int arr[] = {5, 6, 18, 9, 2, 7, 8, 3, 1};

    Node *head = NULL;

    for (int numb : arr)
    {
        append(&head, numb);
    }

    printList(&head);

    deleteEvenNumbers(&head);

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

void deleteEvenNumbers(Node **head_ref)
{
    Node *prev = NULL;
    Node *current = *head_ref;

    while (current != NULL)
    {
        if (current->data % 2 == 0)
        {
            if (prev == NULL)
            {
                *head_ref = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            delete current;
            current = prev->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}
