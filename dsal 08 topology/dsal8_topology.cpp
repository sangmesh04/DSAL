/*
 Write a C++/Java program to implement topological sorting on graph using object
oriented programming features Design necessary class.( Use of graph)
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string *numbers = NULL;

class graph;

class node
{
private:
    int number;
    node *next;

public:
    node(int number = 0)
    {
        this->number = number;
        next = NULL;
    }
    friend class graph;
};
class graph
{
private:
    int vertices;
    int edges;
    node **arr;

public:
    graph(int vertices = 0)
    {
        this->vertices = vertices;
        edges = 0;
        arr = new node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            arr[i] = NULL;
        }
    }
    void create()
    {
        for (int i = 0; i < vertices; i++)
        {
            int n;
            cout << "\nEnter number of  directed edges connected from " << numbers[i] << " ( " << i << " ):";
            cin >> n;
            for (int j = 0; j < n; j++)
            {
                int x;
                cout << "\nEnter index of incident node no." << j + 1 << ":";
                cin >> x;
                if (arr[i] == NULL)
                {
                    arr[i] = new node(x);
                }
                else
                {
                    node *q = new node(x);
                    node *p = arr[i];
                    node *follow = p;
                    if (p == NULL)
                    {
                        p = q;
                    }
                    else
                    {
                        while (p != NULL)
                        {
                            follow = p;
                            p = p->next;
                        }
                        follow->next = q;
                    }
                }
            }
        }
    }
    void display_adj_list()
    {
        cout << "\nAdjacency list:\n"
             << endl;
        for (int i = 0; i < vertices; i++)
        {

            node *p = arr[i];
            cout << "|" << i << "|-> ";
            while (p != NULL)
            {

                cout << p->number << " -> ";

                p = p->next;
            }
            cout << "NULL" << endl;
            cout << endl;
        }
    }

    void topo()
    {
        stack<int> topo_stack;
        bool visited[vertices];
        //initialize visited of  elements to false
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }
        //call toposort for all vertices in adjacency list
        for (int i = 0; i < vertices; i++)
        {
            topological_sort(i, topo_stack, visited);
        }
        //display stack contents from top to bottom
        while (!topo_stack.empty())
        {
            int x=topo_stack.top();
            cout<<x<<" ";
            topo_stack.pop();
        }


    }
    void topological_sort(int start, stack<int> &st, bool v[])
    {
        node *p = arr[start];
        if (p == NULL)
        {
            if (v[start] == false)
            {
                st.push(start);
                v[start] = true;
            }
            return;
        }
        else
        {
            while (p != NULL)
            {
                topological_sort(p->number, st, v);
                p = p->next;
            }
            if (v[start] == false)
            {
                st.push(start);
                v[start] = true;
            }
        }
    }
};

int main()
{
    int k;
    int v;
    cout << "\nEnter no of nodes:";
    cin >> v;
    graph g(v);

    int choice = 0;
    do
    {
        cout << "\n\n----------------------------MENU------------------------------------\n"
             << endl;
        cout << "\n1.Create\n2.Display adjacency list\n3.Display Topological sorting\n4.Exit\n"
             << endl;
        cout << "\nEnter choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            numbers = new string[v + 1];

            for (int i = 0; i < v; i++)
            {
                string s;
                cout << "\nEnter node name:";
                cin >> s;
                numbers[i] = s;
            }
            cout << endl;
            cout << "\n-----------------Node indixes(starting from 0)----------------------\n"
                 << endl;
            for (int i = 0; i < v; i++)
            {
                cout << i << " " << numbers[i] << endl;
            }
            g.create();
            break;

        case 2:
            g.display_adj_list();
            break;

        case 3:
            cout << "\nTopological sorting: " << endl;
            g.topo();

            break;

        case 4:

            cout << "\n\n-------------------------------Thank You-----------------------------\n\n"
                 << endl;
            choice = 0;
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}
