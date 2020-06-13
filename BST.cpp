#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;

class node {

public:
    int data;
    node *left,*right;

    node(int x)
    {    data=x;
        left=NULL;
        right=NULL;
    }
};
node*insert(node* root ,const int x)
{//by using this function I'm no longer bound to adding
    //the element in the tree by using normal -> arrow
    //O(log n)
    if(root==NULL)
        return new node(x);

    if(x< root->data)
        root->left=insert(root->left,x);

    if(x> root->data)
        root->right=insert(root->right,x);

    return root;
    }
void inorder(node* root)
{
    if(root== NULL)
        return;

        inorder(root->left);
        cout<<root->data<<" <- ";
        inorder(root->right);
}
void preorder(node* root)
{
    if(root== NULL)
        return;

        cout<<root->data<<" <- ";
        preorder(root->left);
        preorder(root->right);
}
void postorder(node* root)
{
    if(root== NULL)
        return;

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" <- ";
}

void search(node* root,const int n)
{//O(log n)
    if(root==NULL)
    {cout<< n<<" is not present in the BST";
        return;
    }

    if(root->data==n)
        { cout<<n<<" is present in the BST";
           return;
        }

          if(n < root->data)
            search(root->left,n);
          else
            search(root->right,n);
}
int max_height(node* root)
{

   if(root==NULL)
    return 0 ;

    queue<node*> q;
    q.push(root);
   static int height =0;
    node* temp;
int node_count;
    while(1)
    { node_count=q.size();

        if(node_count==0)
            return height;
        else
        height++;

        while(node_count>0)
        {
            temp=q.front();
            q.pop();

               if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);

                node_count--;
        }
   }

}
node*minValue(node* root)
{
    node* current=root;
    while(current&&current->right!=NULL)
        current=current->left;

    return current;
}

node* deletion(node* root,const int key)
{
    if(root==NULL)
        return NULL;
    else if(key<root->data)
         root->left=deletion(root->left,key);
    else if(key>root->data)
         root->right=deletion(root->right,key);
     else
     {//case 1 when a node has no children
         if(root->left==NULL&&root->right==NULL)
         {
             delete root;
             root=NULL;
             return root;
         }//case 2 when either left or right child is null
         else if(root->left==NULL)
         {
             node*temp=root;
             root=root->right;
             delete temp;
             return root;
         }
         else if(root->right==NULL)
         {
             node*temp=root;
             root=root->left;
             delete temp;
             return root;
         }
         else{
          node*temp=minValue(root->right);
         root->data=temp->data;
         root->right=deletion(root->right,temp->data);
         }
     }
     return root;

}

int min_Value(node* root)
{
    node*temp=root;
    while(temp!=NULL&&temp->left)
        temp=temp->left;

    return temp->data;
}

int max_Value(node* root)
{
    node*temp=root;
    while(temp!=NULL&&temp->right)
        temp=temp->right;

    return temp->data;
}
int main()
{

node*root=NULL;
root=insert(root,8);
root=insert(root,3);
root=insert(root,1);
root=insert(root,6);
root=insert(root,4);
root=insert(root,7);
root=insert(root,10);
root=insert(root,14);
root=insert(root,13);

inorder(root);
space;
search(root,7);
space;

int y= max_height(root);
cout<< y;
space;
preorder(root);
space;
root=deletion(root,1);
space;
inorder(root);
space;
int e=min_Value(root);
cout<<"Minimum value is "<<e;
space;
int f=max_Value(root);
cout<<"Maximum value is "<<f;
 return 0;

}
