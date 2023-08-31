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
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << endl;
        }
    }

    int length()
    {
        return top + 1;
    }
};

int main()
{
    Stack stack1(10);
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);
    stack1.push(60);

    cout << "First stack" << endl;
    stack1.printStack();
    cout << "=====================" << endl;

    Stack stack2(10);

    int firstStackLength = stack1.length();

    for (int i = 0; i < firstStackLength; i++)
    {
        stack2.push(stack1.pop());
    }

    cout << "Second stack" << endl;
    stack2.printStack();
    cout << "=====================" << endl;

    return 0;
}
