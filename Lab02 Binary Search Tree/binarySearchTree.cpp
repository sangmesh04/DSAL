/*

A Dictionary stores keywords and its meanings. Provide facility for
1. adding new keywords,
2. deleting keywords,
3. updating values of any entry.
4. Provide facility to display whole data sorted in ascending/ Descending order.
5. Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.

*/

#include"iostream"
#include<string.h>
using namespace std;

struct node{
 char k[20];
 char m[20];
 struct node  *left;
 struct node * right;
};

class dictionary
{
public:
 node *root;
 void create();
 void display(node *, int order);
 void insertNode(node * root,node *temp);
 int searchNode(node *,char []);
 int updateNode(node *,char []);
 node * deleteNode(node *,char []);
 node * leftMost(node *);
};

void dictionary ::create(){
 node *temp;
 int ch;
 do
 {
  temp = new node;
  cout<<"\nKey: ";
  cin>>temp->k;
  cout<<"Mean: ";
  cin>>temp->m;

  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL){
   root = temp;
  }else{
   insertNode(root, temp);
  }
  cout<<"Do you want to add more (1/0): ";
  cin>>ch;
 }
 while(ch == 1);

}

void dictionary::insertNode(node * root,node *temp){
 if(strcmp(temp->k, root->k) < 0 ){
  if(root->left == NULL){
    root->left = temp;
  }
  else{
    insertNode(root->left,temp);
 }
 }
 else if (strcmp(temp->k, root->k) > 0 ){
    if(root->right == NULL){
      root->right = temp;
    }
  else{
   insertNode(root->right,temp);
 }
 }else{
 cout<<"Key must be distinct!"<<endl;
 }
}

void dictionary::display(node * root, int order){
 if( root != NULL && order == 1){
  display(root->left,order);
  cout<<root->k<<" : "<<root->m<<endl;
  display(root->right,order);
 }
 if( root != NULL && order == 2){
  display(root->right,order);
  cout<<root->k<<" : "<<root->m<<endl;
  display(root->left,order);
 }
}

int dictionary::searchNode(node * root,char k[20]){
 int c=0;
 while(root != NULL){
  c++;
  if(strcmp(k,root->k) == 0){
   cout<<"\nNum of Comparisons: "<<c<<endl;
   return 1;
  }
  if(strcmp (k, root->k) < 0){
   root = root->left;
  }
  if(strcmp (k, root->k) > 0){
   root = root->right;
 }
 }
 return -1;
}

int dictionary::updateNode(node * root,char k[20])
{
 while(root != NULL){
  if(strcmp(k,root->k) == 0){
   cout<<"Enter new meaning of key "<<root->k<<" : ";
   cin>>root->m;
   return 1;
  }
  if(strcmp (k, root->k) < 0){
   root = root->left;
  }
  if(strcmp (k, root->k) > 0){
   root = root->right;
 }
 }
 return -1;
}

node* dictionary::deleteNode(node * root,char k[20]){
 node *temp;
 if(root == NULL){
  cout<<"Key is not present in dic!"<<endl;
  return root;
 }

 if (strcmp(k,root->k) < 0){
  root->left = deleteNode(root->left, k);
  return root;
 }
 if (strcmp(k,root->k) > 0){
   root->right = deleteNode(root->right, k);
   return root;
 }

 if (root->right==NULL&&root->left==NULL){
  temp = root;
  delete temp;
  cout<<"Deleted!"<<endl;
  return NULL;
}

  if(root->right==NULL){
  temp = root;
  root = root->left;
  delete temp;
  cout<<"Deleted!"<<endl;
  return root;
  }
  else if(root->left==NULL){
  temp = root;
  root = root->right;
  delete temp;
  cout<<"Deleted!"<<endl;
  return root;
  }
  temp = leftMost(root->right);
  strcpy(root->k,temp->k);
  root->right = deleteNode(root->right, temp->k);
  return root;
}

node * dictionary:: leftMost(node *q){
 while(q->left != NULL){
  q = q->left;
 }
 return q;
}



int main()
{
 int ch = 1,order;
 dictionary d;
 d.root = NULL;

 while(ch>0 && ch<6){
  cout<<"\n<---- Menu ---->"<<endl;
  cout<<"1. Add a key\n2. Display dic\n3. Search a key\n4. Update a key\n5. Delete a key"<<endl;
  cout<<"Enter choice(0 to exit): ";
  cin>>ch;

  switch(ch){
case 1: d.create();
  break;
case 2: if(d.root == NULL){
  cout<<"Dic is empty!"<<endl;
  }
  else{
        cout<<"1. Ascending\n2. Descending"<<endl;
        cout<<"Enter option: ";
        cin>>order;
        cout<<endl;
        if(order==1 || order == 2){
            d.display(d.root,order);
        }else{
            cout<<"Didn't get that..."<<endl;
        }
  }
  break;
case 3: if(d.root == NULL){
  cout<<"Dic is empty!"<<endl;
 }else{
  cout<<"Enter key to be searched: ";
  char k[20];
  cin>>k;
  if( d.searchNode(d.root,k) == 1){
  cout<<"Key is present!"<<endl;
  }
  else{
  cout<<"Key is absent!"<<endl;
  }
 }
  break;
case 4:
  if(d.root == NULL){
  cout<<"Dic is empty!"<<endl;
 }else{
  cout<<"Enter key to be updated: ";
  char k[20];
  cin>>k;
  if(d.updateNode(d.root,k) == 1){
  cout<<"Updated!"<<endl;
  }else{
  cout<<"Key is absent!"<<endl;
  }
 }
  break;
case 5:
  if(d.root == NULL){
  cout<<"Dic is empty!"<<endl;
  }else{
  cout<<"Enter key to be deleted: ";
  char k[20];
  cin>>k;
  if(d.root == NULL){
  cout<<"Key is absent!";
  }
  else{
  d.root = d.deleteNode(d.root,k);
    }
   }
  }
 }
 return 0;
}
