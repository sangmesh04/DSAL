/*

A Dictionary stores keywords and its meanings. Provide facility for
1. adding new keywords,
2. deleting keywords,
3. updating values of any entry.
4. Provide facility to display whole data sorted in ascending/ Descending order.
5. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.

*/
#include<iostream>
#include<string>
using namespace std;

struct node{
int key;
int mean;
struct node * right;
struct node * left;
};

class BinarySearchTree{
public:
    node *root;
    BinarySearchTree();
    node * createBSTree(node *);
    node * CreateNode();
    void inorder(node *);
};

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

node * BinarySearchTree::CreateNode(){
    node *p = new node;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node * BinarySearchTree::createBSTree(node *p){
    int k,m;
    cout<<p<<endl;
    cout<<"#Key -->(x to stop): ";
    cin>>k;
    if(k==0){
        return NULL;
    }else{
         cout<<"@Meaning --> ";
         cin>>m;
         node *q = CreateNode();
         q->key = k;
         q->mean = m;
         if(p == NULL){
            node *q = CreateNode();
            createBSTree(q);
        }else if(p->key > k){
                p->left = createBSTree(p->left);
        }else{
                p->right = createBSTree(p->right);
            }
        return q;
    }
}

void BinarySearchTree::inorder(node *temp){
        if(temp != NULL){
             inorder(temp->left);
             cout<<temp->key<<" : "<<temp->mean<<", ";
             inorder(temp->right);
        }
}

int main(){
    BinarySearchTree obj;

    obj.createBSTree(NULL);
    node *p = obj.CreateNode();
    obj.inorder(p);
    //cout<<"\n"<<p;
}
