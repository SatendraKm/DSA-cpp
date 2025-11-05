#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack(/* args */);
    ~Stack();
    void push(int x);
    int pop();
    void Display();
};

Stack::Stack(/* args */)
{
    top = NULL;
}

Stack::~Stack()
{
}
void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "stack is full" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}
void Stack::Display()
{
    Node *p = top;
    cout << "Stack: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout << stk.pop() << " pop from the stack" << endl;
    stk.Display();

    return 0;
}