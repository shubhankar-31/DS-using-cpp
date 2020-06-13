#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>


using namespace std;
class node {

public:
    int data;
    node *left,*right;

    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
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
bool node_exist(node* root ,int x)
{//this function will do a level order traversal to find the node O(n)
    if(root==NULL)
        return false;

    queue<node*> q;
    q.push(root);

    node*temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==x)
            return true;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return false;
}
void del_deepest( node* root,node* d_node)
{//this function will delete the deepest node
    queue< node*> q;
    q.push(root);

    // Do level order traversal until last node but
    //right to left
     node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }

//traversing from right side since we have to find
//the rightmost deepest node in the tree
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);


        }
    }
}

node* deletion( node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data== key)
            return NULL;
        else
            return root;
    }

    queue< node*> q;
    q.push(root);

     node* temp;
     node* key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data== key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL) {
        int x = temp->data;
        del_deepest(root, temp);
        key_node->data= x;
    }
    return root;
}
void level_traversal(node* root)
{// this function will do level order traversal and print the data
    if(root==NULL)
        return ;

    queue<node*> q;
    q.push(root);

    node* temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
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

void  nth_inorder(node*leaf ,int n)
{
    static int count=0;
    if(leaf==NULL)
        return;


if(count <=n)
    {
        nth_inorder(leaf->left,n);
        count++;

       if(count == n)
        cout<<leaf->data;

        nth_inorder(leaf->right,n);

    }
}
void  nth_preorder(node*leaf ,int n)
{
    static int count=0;
    if(leaf==NULL)
        return;


if(count <=n)
    {count++;
         if(count == n)
        cout<<leaf->data;

        nth_preorder(leaf->left,n);



        nth_preorder(leaf->right,n);

    }
}
void  nth_postorder(node*leaf ,int n)
{
    static int count=0;
    if(leaf==NULL)
        return;


if(count <=n)
    {


        nth_postorder(leaf->left,n);


        nth_postorder(leaf->right,n);
 count++;
         if(count == n)
        cout<<leaf->data;
    }
}

int main()
{

node *root=new node(1);

root->left=new node(2);

root->right=new node(3);

root->left->left=new node(5);

root->left->right=new node(7);

root->right->left=new node(9);
cout<<"Preorder traversal "<<endl;
preorder(root);
cout<<"\n\n";
cout<<"Inorder traversal "<<endl;
inorder(root);
cout<<"\n\n";
cout<<"Postorder traversal "<<endl;
postorder(root);
cout<<endl<<endl<<endl;
int x=554;
if(node_exist(root,x))
    cout<<"element "<<x <<" found";
else
    cout<<"element "<<x <<" not found";
cout<<endl<<endl;
    cout<<endl<<endl;
    int y= max_height(root);
    cout<<"Height of the binary tree is : " <<y;
    cout<<endl<<endl;
    cout<<endl<<endl;
inorder(root);
 cout<<endl<<endl;
    cout<<endl<<endl;

nth_inorder(root,4);
cout<<endl;
nth_preorder(root,3);
cout<<endl;
nth_postorder(root,3);
 return 0;

}
