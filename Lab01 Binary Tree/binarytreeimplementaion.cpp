/*

Beginning with an empty binary tree, construct binary tree by inserting the values in the order given.
After constructing a binary tree perform following operations on it-
•Perform in-order, pre-order and post order traversal(Implement both recursive and non-recursive methods)
•Change a tree so that the roles of the left and right pointers are swapped at every node
•Find the height of tree
•Copy this tree to another [operator=]
•Count number of leaves, number of internal nodes.
•Erase all nodes in a binary tree.

*/



#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;



struct node{

int data;
struct node * left;
struct node * right;
};

class BinaryTree{


public:
    node * root;
    int lfcount=0,incount=0;
    BinaryTree();
    node * create();
    void inorder(node * temp);
    void preorder(node * temp);
    void postorder(node * temp);

    void allLeafNode(node *temp);
    void internalNodes(node *temp);

    void nonrecPreorder(node *temp);
    void nonrecInorder(node *temp);
    void nonrecPostorder(node *temp);

    node * mirror(node *temp);

    node * copyTree(node *temp);

    void operator = (BinaryTree &);

    void deleteTree(node *temp);

    int heightTree(node *temp);
};

BinaryTree::BinaryTree(){

    root=NULL;
}


int BinaryTree::heightTree(node *temp){
    int leftHeight, rightHeight;
    if(temp == NULL){
        return 0;
    }else{
        leftHeight = heightTree(temp->left);
        rightHeight = heightTree(temp->right);
        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }else{
        return rightHeight + 1;
        }
    }
}


void BinaryTree::deleteTree(node *temp){

    if(temp != NULL){
        deleteTree(temp->left);
        deleteTree(temp->right);
        cout<<temp->data<<"  ";
        delete temp;
    }
}

void BinaryTree::operator = (BinaryTree &t){

    root = copyTree(t.root);
    cout<<"Address of initial tree root: "<<t.root<<endl;
    cout<<"Address of copied tree root: "<<root<<endl;
}

node * BinaryTree::copyTree(node *temp){

    node *t = NULL;
    if(temp != NULL){
        t = new node;
        t->data = temp->data;
        t->left = copyTree(temp->left);
        t->right = copyTree(temp->right);
    }
    return t;
}

node * BinaryTree::mirror(node *temp){

    node *t = NULL;
    if(temp != NULL){
        t = new node;
        t->data = temp->data;
        t->left = mirror(temp->right);
        t->right = mirror(temp->left);
    }
    return t;
}

void BinaryTree::nonrecPostorder(node *temp){

    stack<node *> s1, s2;
    s1.push(temp);
    vector<int> a;
    while(!s1.empty()){
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL){
            s1.push(temp->left);
        }
        if(temp->right != NULL){
            s1.push(temp->right);
        }
        while(!s2.empty()){
            node *t = s2.top();
            s2.pop();
            a.push_back(t->data);
            //cout<<t->data<<"  ";
        }
        //cout<<endl;
    }
    for(int i=a.size()-1;i>=0;i--){
        cout<<a[i]<<"  ";
    }
}

void BinaryTree::nonrecInorder(node *temp){

    stack<node *> s;
    while(temp != NULL){
        s.push(temp);
        temp = temp->left;
    }
    while(!s.empty()){
        temp=s.top();
        s.pop();
        cout<<temp->data<<"  ";
        temp=temp->right;
        while(temp!=NULL){
            s.push(temp);
            temp=temp->left;
            }
        }
        cout<<endl;
}

void BinaryTree::nonrecPreorder(node *temp){

    stack<node *> s;
    s.push(temp);
    while(!s.empty()){
        temp = s.top();
        s.pop();
        cout<<temp->data<<"  ";
        if(temp->right!=NULL){
            s.push(temp->right);
        }
        if(temp->left!=NULL){
            s.push(temp->left);
        }
    }
    cout<<endl;
}

void BinaryTree::inorder(node *temp){

        if(temp != NULL){
             inorder(temp->left);
             cout<<temp->data<<"  ";
             inorder(temp->right);
        }
}

void BinaryTree::preorder(node *temp){
        if(temp != NULL){
            cout<<temp->data<<"  ";
            preorder(temp->left);
            preorder(temp->right);
        }
}


void BinaryTree::postorder(node *temp){
        if(temp != NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data<<"  ";
        }
}


void BinaryTree::allLeafNode(node *temp){

        if(temp == NULL){
            return;
        }
        if(temp->left==NULL && temp->right==NULL){
            cout<<temp->data<<"  ";
            lfcount += 1;
            return;
        }
        if(temp->left != NULL){
            allLeafNode(temp->left);
        }
        if(temp->right != NULL){
            allLeafNode(temp->right);
        }
}

void BinaryTree::internalNodes(node *temp){

        if(temp==NULL){
            return;
        }
        if(temp->left != NULL || temp->right != NULL){
            cout<<temp->data<<"  ";
            incount += 1;
        }
        if(temp->left != NULL){
            internalNodes(temp->left);
        }
        if(temp->right != NULL){
            internalNodes(temp->right);
        }
}

node * BinaryTree::create(){

        int x;
        cout<<"#---(-1 to stop): "; //node data
        cin>>x;
        if(x== -1){
                return NULL;
        }
        else{
                node *p=new node;
                p->data=x;
                cout<<"<--- "<<x<<endl; //left child
                p->left=create();
                cout<<"---> "<<x<<endl; //right child
                p->right=create();
                return p;
        }
}

int main(){
BinaryTree obj, cobj;
node * t;
int h;
t = obj.create();
obj.root = t;
cout<<"\n\nThe inorder tree is: "<<endl;
obj.inorder(t);
cout<<"\n\nThe inorder non-recursive way: "<<endl;
obj.nonrecInorder(t);

cout<<"\n\nThe inorder of copy of tree: "<<endl;
cobj = obj;
obj.inorder(cobj.root);

cout<<"\n\nThe inorder of mirror of tree: "<<endl;
obj.inorder(obj.mirror(t));



cout<<"\n\nThe preorder tree is: "<<endl;
obj.preorder(t);
cout<<"\n\nThe preorder non-recursive way: "<<endl;
obj.nonrecPreorder(t);

cout<<"\n\nThe post order tree is: "<<endl;
obj.postorder(t);
cout<<"\n\nThe post order non-recursive way: "<<endl;
obj.nonrecPostorder(t);

cout<<"\n\nAll leaf nodes are: "<<endl;
obj.allLeafNode(t);
cout<<"\nLeaf count is: "<<obj.lfcount<<endl;

cout<<"\n\nAll internal nodes are: "<<endl;
obj.internalNodes(t);
cout<<"\nInternal node count is: "<<obj.incount<<endl;

h = obj.heightTree(t);
cout<<"\n\nThe height of tree is: "<<h<<endl;

cout<<"\n\nThe order of deleting the nodes of tree is: "<<endl;
obj.deleteTree(t);
t = NULL;
h = obj.heightTree(t);
cout<<"\n\nThe height of tree after deleting tree is: "<<h<<endl;
return 0;
}
