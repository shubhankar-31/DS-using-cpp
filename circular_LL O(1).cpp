#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>


using namespace std;

class node
{ public:
    int data;
    node *next;
};

class circular_ll
{
private:
    node *head,*tail;
      int i = 1;
public:
    circular_ll()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int );
    void add_begin(int );
    void display();
    void search(int );

    //simple return functions
    int get_head()
    {
        return head->data;
    }
    int get_tail()
    {
        return tail->data;
    }
};

void circular_ll::add_node(int n)
    {
        node *temp=new node;

        temp->data = n;


        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp->next=head;
        }
        else
        {
            tail->next = temp;
            temp->next=head;
             tail = temp;

        }
    }

void circular_ll::add_begin(int n)
{
    node *temp=new node;

        temp->data = n;


        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp->next=head;
        }

        else
        {temp->next=head;
        tail->next=temp;
        head=temp;

        }

}
void circular_ll::display()
  {
        node *temp = head;
        if(head==NULL)
        {
            cout<<"List is empty" ;
        }
       else
       {cout<<"Nodes of circular Linked list \n\n";
           do
           {
            cout << temp->data<<"  ";
            temp = temp->next;

           } while (temp != head);
       }
    }

void circular_ll:: search(int key) {
     node *temp = head;


    bool check = 0;

    if(head == NULL) {
        cout<<"List is empty";
        return;
    }
    else {
         do{
            if(temp->data ==  key) {
                check = 1;
                break;
            }
            temp = temp->next;
            i++;
        }while(temp != head);

         if(check)
            cout<<"\nkey is present in the list at the position : "<< i<<endl;
        else
            cout<<"\nkey is not present in the list";
    }
}

int main()
{
circular_ll a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(5);
    a.add_node(4);
    a.add_begin(16);

    a.display();

    cout<<"\n\nhead of the cll is "<<a.get_head()<<endl;
    cout<<"\ntail of the cll is "<<a.get_tail()<<endl;
    a.search(5);


 return 0;

}
