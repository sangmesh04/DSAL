/*
Beginning with an empty binary tree, Construct binary tree by inserting
the values in the order given. After constructing a binary tree -
i. Insert new node,
ii. Find number of nodes in longest path from root,
iii. Minimum data value found in the tree,
iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
v. Search a value
*/

#include<iostream>
using namespace std;

struct node{
int data;
struct node* left;
struct node* right;
};

class BinaryTree{
int x,n;

public:
    node *root;
    BinaryTree(){
        root = NULL;
    }

    node *createNewNode(int Idata){
        node *pointer = new node;
        pointer->data = Idata;
        pointer->left = NULL;
        pointer->right = NULL;
        return pointer;
    }

    node *insertnode(node *temp,int Idata,int posi){
    if(temp== NULL){
        temp = createNewNode(Idata);
    }
    else if(posi==1){
        temp->left = insertnode(temp->left, Idata, posi);
    }else{
    temp->right = insertnode(temp->right, Idata, posi);
    }
    return temp;
    }

     node *input(){
         node *last;
         int xl,xr,posi;
      cout<<"Enter number of elements in binary search tree: ";
      cin>>n;
      for(int i = 0 ; i < n ; i++)
      {
       cout<<"Enter number "<<i+1<<"/"<<n<<": ";
       cin>>x;
       cout<<"Enter value for left of "<<x<<": ";
       cin>>xl;
       if(xl != -1){
       root = insertnode(root , x, 1);
       }
       cout<<"Enter value for right of "<<x<<": ";
       cin>>xr;
       if(xr != -1){
       root = insertnode(root , x, 0);
       }
      }
      last = root;
      cout<<"root value: "<<root->data<<endl;
      return last;
     }

     void display(node *temp){
        if(temp != NULL){
             display(temp->left);
             cout<<temp->data<<"  ";
             display(temp->right);
        }
     }

};

int main(){
    BinarySearchTree obj;
    obj.input();
    obj.display(obj.root);
    /*int option;
    while(option>0 && option<6){
        cout<"<---- Menu ---->"<<endl;
        cout<<"1. Insert new node \n2. Find number of nodes in longest path from root \n3. Minimum data value found in the tree \n4. Change a tree so that the roles of the left and right pointers are swapped at every node \n5. Search a value"<<endl;
        cout<<"Enter option: ";
        cin>>option;
        switch
    }*/
return 0;
}
