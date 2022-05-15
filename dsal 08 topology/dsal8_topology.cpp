/*
 Write a C++/Java program to implement topological sorting on graph using object
oriented programming features Design necessary class. .( Use of graph)
*/

#include<iostream>
#include<stack>
#include<list>
using namespace std;

class graph
{
    int no_of_vertices;
    list<int>* l1;

  public:
    graph(int n)
  {
      no_of_vertices=n;
      l1=new list<int>[n];
  }

    /* push_back function is used to add new element at the end of the list container */
    void add_edge(int x, int y)
  {
     l1[x].push_back(y);
  }
  void topological(int, int [], stack<int>& );
    void topological_sort();
};

void graph::topological(int vertex_no, int visited[], stack<int>& s)
{
  /* Marking vertex visited */
    visited[vertex_no]=1;

    /* we cannot iterate through list using normal integer. Hence we use iterator */
    list<int>::iterator i;
    for (i = l1[vertex_no].begin(); i != l1[vertex_no].end(); i++)
  {
        if (visited[*i]==0)
    {
            topological(*i,visited,s);
    }
  }

    /* push current vertex on stack */
    s.push(vertex_no);
}

void graph::topological_sort()
{
    stack<int> s;
    int i,visited[no_of_vertices];

  /* '0' means not visited and '1' means visited. here, we are marking all the vertices not-visited */
    for (i=0; i<no_of_vertices;i++)
  {
    visited[i]=0;
  }

  /* calling topological for each vertex */
    for (i=0; i<no_of_vertices;i++)
  {
    if (visited[i]==0)
    {
      topological(i,visited,s);
    }
  }

  /* display stack content */
    while(!s.empty())
  {
    int k=s.top();
        cout<<k<<" ";
        s.pop();
    }
}

int main()
{
    int n, e;
    cout<<"Enter no of vertices: ";
    cin>>n;
    graph p(n);  // 4: no of vertices

    cout<<"Enter no of edges: ";
    cin>>e;
    int s,d;
    for(int i=0;i<n;i++){
            cout<<"\nEnter edge "<<i+1<<" details-> "<<endl;
        cout<<"Enter edge start point: ";
        cin>>s;
        cout<<"Enter destination point: ";
        cin>>d;
        p.add_edge(s,d);
    }

    /* This graph is shown in above figure */

    cout <<"\nTopological order of the vertices of the graph: ";
    p.topological_sort();

    return 0;
}
