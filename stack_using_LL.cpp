#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

//Stack using singly LL

using namespace std;

class Node {
    public:
    int data;
    struct Node* link;
};

 Node* top;

void push(int data)
{
     Node* temp = new Node;

    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

bool isEmpty()
{
    return (top==NULL? 0:1);
}

int peek()
{
    if (isEmpty())
        return top->data;
    else
        exit(1);
}

void pop()
{
     Node* temp;

    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else {
        temp = top;
        top = top->link;
        temp->link = NULL;
        delete temp;
    }
}

void display()
{
     Node* temp;

    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else {
        temp = top;
        while (temp != NULL) {
              cout <<  temp->data << endl;
              temp = temp->link;
        }
        cout<<"\n";
    }
}

int main()
{

    push(11);
    push(22);
    push(33);
    push(44);
    push(55);

    display();

    cout << "\n Top element is \n" << peek();
    return 0;


}
