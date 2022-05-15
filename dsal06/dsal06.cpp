/*
Represent a given graph using adjacency list to perform DFS and BFS.
Use the map of  the  area  around  the college  as  the  graph.
Identify  the  prominent  landmarks  as nodes and perform DFS and BFS on that.
*/


#include <iostream>
using namespace std;
#define MAX 20

struct queue
{
    int data[MAX];
    int front,rear;
};

class Queue
{
    struct queue q;
public:
    Queue()
    {
        q.front=q.rear=-1;
    }
    int isempty();
    int isfull();
    void enqueue(int);
    int delqueue();
};
int Queue::isempty()
{
    return(q.front==q.rear);
}
int Queue::isfull()
{
    return(q.rear==MAX-1);
}
void Queue::enqueue(int x)
{
    q.data[++q.rear]=x;
}
int Queue::delqueue()
{
    return q.data[++q.front];
}


class Stack
{
public:
    int top;
    int stack[MAX];
    Stack()
    {
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    int tp();
};
int Stack :: tp()
{
    return(stack[top]);
}
bool Stack :: isEmpty()
{
    return(top == -1);
}
bool Stack :: isFull()
{
    return(top == 19);
}
void Stack :: push(int x )
{
    int a;
    a = isFull();
    if(a==1)
    {
        cout<<"Stack_overflow"<<endl;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
int Stack :: pop()
{
    int a;
    int item = -1;
    a = isEmpty();
    if(a==1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        item = stack[top];
        top--;
        return item;
    }
    return item;
}


class Node
{
    int data;
    Node *link;
public:
    Node()
    {
        data = -1;
        link = NULL;
    }
    Node(int val)
    {
        data = val;
        link = NULL;
    }
    friend class Graph;
};


class Graph
{
    int nv, ne;
    Node **adjacentList;
public:
    Graph(int nv, int ne)
    {
        this->nv = nv;
        this->ne = ne;
        adjacentList = new Node* [nv];
        for(int i = 0; i<nv; i++)
        {
            adjacentList[i] = NULL;
        }
    }
    void acceptGraph()
    {
        int s, d;
        for (int i = 0; i < ne; i++)
        {
            cout << "Enter the " << i + 1 << " edge details:" << endl;
            cout << "Enter source point :";
            cin >> s;
            cout << "Enter destination point:";
            cin >> d;
            Node *temp=new Node(d);
            if(adjacentList[s]==NULL)
            {
                adjacentList[s]=temp;
            }
            else
            {
                Node *temp1=adjacentList[s];
                while(temp1->link!=NULL)
                    temp1=temp1->link;
                temp1->link=temp;
            }
        }
    }
    void displayAdjacent()
    {
        for(int i = 0; i<nv; i++)
        {
            cout<<i<<"---->";
            for(Node* it = adjacentList[i]; it != NULL; it = it->link )
            {
                cout<<it->data<<" ";
            }
            cout<<endl;
        }
    }
    void breadthFirstSearch(int startingNode)
    {
        bool *visited = new bool[nv];
        for(int i = 0; i < nv; i++)
        {
            visited[i] = false;
        }
        Queue q;
        int a;
        q.enqueue(startingNode);
        visited[startingNode] = true;
        while(!(q.isempty()))
        {
            a = q.delqueue();
            cout<<a<<" ";
            for (Node *it = adjacentList[a]; it != NULL; it=it->link)
            {
                if (!visited[it->data])
                {
                    visited[it->data] = true;
                    q.enqueue(it->data);
                }
            }
        }
        cout<<endl;
    }
    void depthFirstSearch(int startingNode)
    {
        bool *visited = new bool[nv];
        for(int i = 0; i < nv; i++)
        {
            visited[i] = false;
        }
        Stack s;
        int a;
        s.push(startingNode);
        visited[startingNode] = true;
        while(!(s.isEmpty()))
        {
            a = s.pop();
            cout<<a<<" ";
            for (Node *it = adjacentList[a]; it != NULL; it= it->link)
            {
                if(!visited[it->data])
                {
                    visited[it->data] = true;
                    s.push(it->data);
                }
            }
        }
        cout<<endl;
    }
};
int main()
{
    int nv, ne, startingNode;
    cout<<"Enter the number of landmarks: ";
    cin>>nv;
    cout<<"Enter the number of connections: ";
    cin>>ne;
    Graph g(nv,ne);
    g.acceptGraph();
    g.displayAdjacent();
    cout<<"Enter initial vertex of traversal: ";
    cin>>startingNode;
    cout<<"Breadth First Traversal of graph is: ";
    g.breadthFirstSearch(startingNode);
    cout<<"Depth First Traversal of graph is: ";
    g.depthFirstSearch(startingNode);
}
