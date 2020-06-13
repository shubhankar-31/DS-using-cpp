#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>



using namespace std;



class node
{ public:
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int );
    void display();
    void front(int );

};

void linked_list::front(int n)
{
    node *tmp = new node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp;
}
void linked_list::add_node(int n)
    {
        node *tmp=new node;

        tmp->data = n;


        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
             tmp->next = NULL;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }



void linked_list::display()
  {
        node *tmp;
        tmp = head;
        if(head==NULL)
            cout<<"List is Empty";

        else
        {
            while (tmp != NULL)
        {
        cout << tmp->data << endl;
        tmp = tmp->next;
        }

        }
    }



int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);

    a.front(4);
    a.display();


    return 0;
}
