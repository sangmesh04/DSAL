#include<iostream>
using namespace std;

struct node
{
    char c;
    int flag;
    struct node *next;
};

class GeneralizedLinkedList
{
public:
    node *header, *footer;
    GeneralizedLinkedList()
    {
        header = NULL;
        footer = NULL;
    }

    node * add()
    {
        int n;
        header = NULL;
        node *x, *y;
        int f;
        cout<<"\nEnter total numbers to be added: ";
        cin>>n;
        char var;
        for(int i=0; i<n; i++)
        {
            x = new node;
            cout<<"Enter number to add: ";
            cin>>var;
            cout<<"Do you want next or down(enter 1 for down): ";
            cin>>f;
            x->next = NULL;
            x->flag = f;
            x->c = var;
            if(header==NULL)
            {
                header=x;
                footer=x;
            }
            else
            {
                y=header;
                while(y->next!=NULL)
                {
                    y=y->next;
                }
                y->next=x;
                //x->prev=y;
                footer=x;
            }
        }
        return header;
    }

    void display(node *d)
    {
        cout<<"\nEntered data is: "<<endl;
        node *y;
        y = d;
        cout<<"[ ";
        while(y!=NULL)
        {
            if(y->flag==1)
            {
                cout<<" ["<<y->c<<"] ";
            }
            else
            {
                cout<<y->c<<" ";
            }
            y=y->next;
        }
        cout<<" ]";
    }

};

int main()
{
    int option = 1;
    char ans;
    struct node *z;
    GeneralizedLinkedList obj;

    do
    {
        cout<<"<-- Menu -->"<<endl;
        cout<<"1. Add\n2. Display"<<endl;
        cout<<"Enter option: ";
        cin>>option;
        switch(option)
        {
        case 1:
            obj.add();
            z = obj.header;
            break;
        case 2:
            obj.display(z);
            break;
        default:
            cout<<"Wrong option entered!"<<endl;
        }
        cout<<"\n\nDo you want to continue? (y/n) : ";
        cin>>ans;
    }
    while(ans == 'y');
    return 0;
}
