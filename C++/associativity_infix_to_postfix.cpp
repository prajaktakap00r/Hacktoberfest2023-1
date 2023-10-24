#include <iostream>
using namespace std;

class stack_structure
{
public:
    int size;
    int top;
    char *s;
};

class stack
{
public:
    stack_structure *st = new stack_structure;

    void create();
    void display();
    void push(char x);
    char pop();
    int peek(int pos);
    int isFull();
    int isEmpty();
    int stackTop();
    int isBalanced(char *exp);
};

void stack ::create()
{
    cout << "enter size of stack: ";
    cin >> st->size;
    st->top = -1;
    st->s = new char[st->size];
}

void stack ::display()
{
    for (int i = st->top; i >= 0; i--)
    {
        cout << st->s[i] << endl;
    }
}

void stack ::push(char x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

char stack ::pop()
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int stack ::peek(int pos)
{
    int x = -1;
    if (st->top - pos + 1 < 0)
    {
        cout << "invalid position" << endl;
    }
    else
    {
        x = st->s[st->top - pos + 1];
    }
    return x;
}

int stack ::isFull()
{
    return st->top == st->size - 1;
}

int stack ::isEmpty()
{
    return st->top == -1;
}

int stack ::stackTop()
{
    if (!isEmpty())
    {
        return st->top;
    }
    else
    {
        return -1;
    }
}

int stack ::isBalanced(char *exp)
{
    int i = 0;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty)
            {
                return false;
            }
            else
            {
                pop();
            }
        }
    }
    return isEmpty() ? true : false;
}

int main()
{
    char *exp = "((a+b)*(c+d))";
    stack s1;
    cout<<s1.isBalanced(exp);
}
