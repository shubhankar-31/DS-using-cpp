#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>
#define space cout<<"\n\n\n";
using namespace std;
class node {

public:
    int data;
    node *left,*right;

    bool isThreaded;


};
node*insert(const int x)
{node* temp= new node;
temp->data=x;
temp->left=temp->right=NULL;
    return temp;
}
void createThreaded(node* root,queue<node*> &q)
{
if(root==NULL)
    return;

     if(root->left)
     createThreaded(root->left,q);

     q.pop();

     if(root->right)
     createThreaded(root->right,q);
     else{
        root->right=q.front();
        root->isThreaded=true;
     }
}
void populateQueue(node* root,queue<node*> &q)
{if(root==NULL)
  return;
  if(root->left)
    populateQueue(root->left,q);
  q.push(root);
  if(root->right)
    populateQueue(root->right,q);
}
void BT_to_threaded(node*  root)
{
    queue<node*> q;

    populateQueue(root,q);

    createThreaded(root,q);
}

node* leftmost(node* root)
{
    while(root!=NULL&&root->left!=NULL)
        root=root->left;

    return root;
}

void inorder(node* root)
{
    node* current=leftmost(root);
    while(current!=NULL)
    {
        cout<<current->data<<" " ;

        if(current->isThreaded)
            current=current->right;
       else
        current=leftmost(current->right);
    }
}
int main()
{
node* root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    root->right->left = insert(6);
    root->right->right = insert(7);

BT_to_threaded(root);
cout<< " inorder traversal is "<<endl;
inorder(root);
return 0;
}
