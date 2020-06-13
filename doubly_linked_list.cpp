#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>


using namespace std;

class node
{ public:
    node *prev;
    int data;
    node *next;
};

class doubly_ll
{
public:
    node *head,*tail;
    int i=1;
    doubly_ll()
    { head=NULL;
      tail=NULL;
    }

    void add_node(int );
    void add_begin(int );
    void del_begin();
    void del_end();
    void display_forward();
    void display_reverse();
    void search(int );
     void add_after(node*,int);
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

void doubly_ll:: add_after(node* m,int n)
{
    node* temp= new node;

    temp->data=n;
    temp->prev=m;
    temp->next=m->next;
    m->next=temp;

}

void doubly_ll::add_node(int n)
{
    node*temp=new node;
    temp->data=n;
    if(head==NULL)
    {    temp->prev=NULL;
        temp->next=NULL;
        head=temp;
        tail=temp;

    }
    else
    { tail->next=temp;
      temp->prev=tail;
      temp->next=NULL;

      tail=temp;

    }
}

void doubly_ll::add_begin(int n)
{
    node*temp=new node;
    temp->data=n;
    if(head==NULL)
    {    temp->prev=NULL;
        temp->next=NULL;
        head=temp;
        tail=temp;

    }
    else
    temp->next=head;
    head->prev=temp;
    temp->prev=NULL;
     head=temp;

}

void doubly_ll::del_begin()
{
    node* temp=new node;
    if(head==NULL)
    {
        cout<< "List is empty nothing to delete";
        return;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;

}
void doubly_ll::del_end()
{

    node* temp=new node;
    if(head==NULL)
    {
        cout<< "List is empty nothing to delete";
        return;
    }

    temp=tail;
    tail=tail->prev;
    tail->next=NULL;
        delete temp;
}

void doubly_ll::display_forward()
{
    node* temp= head;
    while(temp!=NULL)
    {

        cout<< temp->data<<"  ";
        temp=temp->next;
    }
cout<<"\n\n";
}

void doubly_ll::display_reverse()
{ node* temp=tail;
   while(temp!=NULL)
   {
       cout<< temp->data<<"  ";
       temp=temp->prev;
   }

cout<<"\n\n";
}

void doubly_ll::search(int key)
{  node* temp=head;
  bool check=false;

        if(head==NULL)
         {  cout<< "List is empty";
             return;
         }
         else
        {do
          {if(temp->data==key)
            {check=true;
              break;
            }
            temp=temp->next;
            i++;
             }while(temp!=NULL);
         }

if(check)
cout<<"Element "<< key <<" is found at position "<< i <<endl;
else
cout<<"\nElement is not present in the list";
}


int main()
{ doubly_ll x;


    x.add_node(1);
    x.add_node(2);
    x.add_node(3);
    x.add_node(4);
    x.add_begin(999);

    x.display_forward();
    x.display_reverse();
    cout<<"\n\n Head of the doubly_ll is "<<x.get_head()<<endl;
    cout<<"\n Tail of the doubly_ll is "<<x.get_tail()<<endl;
    x.search(3);

    x.del_begin();
    x.del_end();
    x.add_after(x.head->next->next,45);
    x.display_forward();

 return 0;

}
