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

    node(int x)
    {    data=x;
        left=NULL;
        right=NULL;
    }
};
node*insert(node* root ,const int x)
{//by using this function I'm no longer bound to adding
    //the element in the tree by using normal -> arrow
    //O(log n)....also I'm following the property of BST
    if(root==NULL)
        return new node(x);

    if(x< root->data)
        root->left=insert(root->left,x);

    if(x> root->data)
        root->right=insert(root->right,x);

    return root;
    }
void inorder(node* root, vector<int> &arr);
void BST_minheap(node* root,vector<int> &arr, int *i);

void convert_minheap(node*root)
{
vector<int> arr;
  int i = -1;
inorder(root,arr);
BST_minheap(root,arr,&i);
}
 void preorder(node* root)
 {
       if(root==NULL)
        return ;

       cout<<root->data<<" ";
       preorder(root->left);
       preorder(root->right);
}
void inorder(node* root, vector<int> &arr)
   {    if(root==NULL)
        return;

       inorder(root->left,arr);
       arr.push_back(root->data);
       inorder(root->right,arr);
   }

 void BST_minheap(node* root,vector<int> &arr, int *i)
 {
     if(root==NULL)
        return;

     root->data=arr[++*i];
     BST_minheap(root->left,arr,i);
     BST_minheap(root->right,arr,i);

 }




int main()
{
node *root=NULL;
root=insert(root,4);
root=insert(root,2);
root=insert(root,6);
root=insert(root,1);
root=insert(root,3);
root=insert(root,5);
root=insert(root,7);
convert_minheap(root);
cout<<" Preorder traversal "<<endl;
preorder(root);
space;

return 0;
}
