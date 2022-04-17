//============================================================================
// Name        : dsal03.cpp
// Author      : sangmeshwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


/*

 Create an inordered threaded binary tree and perform
 inorder and preorder traversals.
 Analyse time and space complexity of the algorithm.

 */


#include <iostream>
using namespace std;

class Node
{
    private:
        Node *left, *right;
        int data;
        int rbit, lbit;

public:
    Node()
    {
    	data=0;
        left = NULL;
        right = NULL;
        rbit = lbit = 0;
    }
    Node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
        rbit = lbit = 0;
    }
    friend class TBT;
};

class TBT
{
private:
    Node *root, *header;
public:
    TBT()
    {
        root = NULL;
        header = new Node(21324);
        header->right = header->left = header;
    }
    void insert(int d);
    void inorder();
    void preorder();
    void deleteNode(int);
    Node *inSucc(Node *);
    Node *inPred(Node *);
};

void TBT::insert(int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        root->left = root->right = header;
        root->lbit = root->rbit = 1;
        header->left = root;
        header->lbit = 1;
        cout << "\nData Inserted successfully!" << endl;
    }
    else
    {
        Node *curr = root;
        while (curr != NULL)
        {

            if (curr->data > d)
            {
                Node *p = new Node(d);
                if (curr->lbit == 1)
                {
                    p->left = curr->left;
                    curr->left = p;
                    p->lbit = 1;
                    curr->lbit = 0;
                    p->right = curr;
                    p->rbit = 1;
                    cout << "\nData Inserted successfully!" << endl;
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }

            if (curr->data < d)
            {
                Node *p = new Node(d);
                if (curr->rbit == 1)
                {
                    p->right = curr->right;
                    curr->right = p;
                    p->rbit = 1;
                    curr->rbit = 0;
                    p->left = curr;
                    p->lbit = 1;
                    cout << "\nData Inserted successfully!" << endl;
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
    }
}

void TBT::inorder()
{
    Node *c = root;
    while (c->lbit == 0)
        c = c->left;
    while (c != header)
    {
        cout << c->data << " ";
        if (c->rbit == 0)
        {
            c = c->right;
            while (c->lbit == 0)
                c = c->left;
        }
        else
            c = c->right;
    }
}
void TBT::preorder()
{
    Node *temp = root;
    while (temp != header)
    {
        while (temp->lbit == 0)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << temp->data << " ";
        while (temp->rbit == 1)
        {
            temp = temp->right;
            if (temp == header)
                return;
        }
        temp = temp->right;
    }
}

Node *TBT::inSucc(Node *ptr)
{
    if (ptr->rbit == 1)
        return ptr->right;
    ptr = ptr->right;
    while (ptr->lbit == 0)
        ptr = ptr->left;
    return ptr;
}

Node *TBT::inPred(Node *ptr)
{
    if (ptr->lbit == 1)
        return ptr->left;
    ptr = ptr->left;
    while (ptr->rbit == 0)
        ptr = ptr->right;
    return ptr;
}

void TBT::deleteNode(int x)
{
    if (header->left == NULL)
    {
        cout << "Tree is Empty!" << endl;
        return;
    }
    Node *temp = header->left;
    Node *parent = header;
    bool found = false;
    while (temp != header)
    {
        if (temp->data == x)
        {
            found = true;
            break;
        }
        else if (temp->data > x)
        {
            if (temp->lbit == 1)
            {
                cout << "Element not found!" << endl;
                return;
            }
            parent = temp;
            temp = temp->left;
        }
        else if (temp->data < x)
        {
            if (temp->rbit == 1)
            {
                cout << "Element not found!" << endl;
                return;
            }
            parent = temp;
            temp = temp->right;
        }
    }

    if (temp->lbit == 0 && temp->rbit == 0)
    {

        Node *successor = temp->right;
        Node *p_successor = temp;
        Node *child = NULL;

        while (successor->lbit != 1)
        {
            p_successor = successor;
            successor = successor->left;
        }

        temp->data = successor->data;
        if (successor->lbit == 1 && successor->rbit == 1)
        {
            if (p_successor == temp)
            {
                p_successor->right = successor->right;
                p_successor->rbit = 1;
                delete successor;
                cout << "Node deleted!" << endl;
                return;
            }

            p_successor->left = successor->left;
            p_successor->lbit = 1;
        }
        else
        {
            p_successor->left = successor->right;
            child = successor->right;
            child->left = successor->left;
        }
        delete successor;
        cout << "Node deleted!" << endl;
        return;
    }

    else if ((temp->lbit == 0  && temp->rbit==1) || (temp->rbit == 0 && temp->lbit==1))
    {
        Node *child = NULL;

        if (temp->lbit == 0)
        {
            child = temp->left;
        }
        else
        {
            child = temp->right;
        }


        if (temp == root)
        {
            header->left = child;
            root = child;
        }

        else if (parent->left == temp)
        {
            parent->left = child;
        }

        else
        {
            parent->right = child;
        }

        Node *s = inSucc(temp);
        Node *p = inPred(temp);


        if (temp->lbit == 0)
        {
            p->right = s;
        }

        else
        {
            s->left = p;
        }

        delete temp;
        cout << "Node deleted!" << endl;
        return;
    }

    else
    {

        if (temp == root)
        {
            header->left = NULL;
            root = NULL;
        }

        else if (parent->left == temp)
        {
            parent->lbit = 1;
            parent->left = temp->left;
        }

        else
        {
            parent->rbit = 1;
            parent->right = temp->right;
        }
        delete temp;
        cout << "Node deleted!" << endl;
        return;
    }
}

int main()
{
    TBT t1;
    int ch;
    while (true)
    {
        cout << "\n<-----MENU----->" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Inorder Traversal " << endl;
        cout << "3. Preorder Traversal" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "\nEnter number of Nodes:";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int data;
                cout << "\nEnter data: ";
                cin >> data;
                t1.insert(data);
            }
            break;
        }
        case 2:
        {
            cout << "Inorder Traversal : " << endl;
            t1.inorder();
            break;
        }
        case 3:
        {
            cout << "Preorder Traversal: " << endl;
            t1.preorder();
            break;
        }
        case 4:
        {
            int key;
            cout << "\nEnter value to be delete: " << endl;
            cin >> key;
            t1.deleteNode(key);
            cout << "Data deleted successfully!" << endl;
            break;
        }
        case 5:
        	cout<<"\nProgram ended successfully!"<<endl;
            break;
            return 0;
        default:
            cout << "Please ,enter valid choice!" << endl;
        }
    }
    return 0;
}


