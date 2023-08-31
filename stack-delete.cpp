#include <iostream>

using namespace std;

struct Stack
{
    int MAX_SIZE;
    int top;
    int *stack;

    Stack(int size)
    {
        MAX_SIZE = size;
        top = -1;
        stack = new int[MAX_SIZE];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        top++;
        stack[top] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1;
        }
        int elementToBePoped = stack[top];

        top--;

        return elementToBePoped;
    }

    int peak()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return stack[top];
    }

    void printStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{

    int a[10] = {2, 4, 7, 23, 6, 3, 7, 24, 8, 22};
    Stack stack(10);

    int targetIndex = 5;

    for (int i = 0; i < targetIndex; i++)
    {
        stack.push(a[i]);
    }

    for (int i = targetIndex + 1; i < 10; i++)
    {
        stack.push(a[i]);
    }

    cout << "Array after removing 5th indexed element:" << endl;
    stack.printStack();
    cout << "=====================" << endl;

    return 0;
}
