//============================================================================
// Name        : dsal06.cpp
// Author      : Sangmeshwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

/*

Represent a given graph using adjacency list to perform DFS and BFS. Use the map
of the area around the college as the graph. Identify the prominent landmarks as
nodes and perform DFS and BFS on that.

 */


#include <bits/stdc++.h>
using namespace std;

struct node{
	string landmark;
	struct node * next;
};

class GraphAdjan{
	int N = 10;
	node * arr[10] = {NULL};
public:
	void insertNode();
	void connectNodes();
	void DisplayNodes();
	bool SearchNode(string s);
	void BFS();
};

bool GraphAdjan::SearchNode(string s){
    for(int i=0;i<N;i++){
            if(arr[i] != NULL){
                if(arr[i]->landmark == s){
                    return true;
                }
            }
    }
    return false;
}

void GraphAdjan::insertNode(){
	int landMarkNum;
	cout<<"How many landmarks you have to add: "<<endl;
	cin>>landMarkNum;
	for(int i=0; i<landMarkNum; i++){
		node *x = new node;
		cout<<"Enter landmark: "<<endl;
		cin>>x->landmark;
		x->next = NULL;
		arr[i] = x;
	}
}

void GraphAdjan::connectNodes(){
	int n = 0;
	node *y = arr[0];
	while(y != NULL && n<N){
		node * a =y;
		string landM = "1";
		while(landM != "-1"){
			cout<<"Enter landmarks connecting to "<<y->landmark<<"(-1 to stop): "<<endl;
			cin>>landM;
			if(landM != "-1"){
			node *z = new node;
			if(SearchNode(landM)){
			z->landmark = landM;
			z->next = NULL;
			a->next = z;
			a = z;
			}else{
			cout<<"This landmark didn't added!"<<endl;
			}
          }
		}
		n += 1;
		y = arr[n];
	}
}

void GraphAdjan::DisplayNodes(){
	node *s = arr[0];
	int n=0;
	while(s != NULL && n<N){
		cout<<n<<". "<<s->landmark<<endl;
		node *t = s->next;
		while(t != NULL){
			cout<<n<<". "<<t->landmark<<endl;
			t = t->next;
		}
		n+=1;
		s = arr[n];
	}
}

void GraphAdjan::BFS(){
    queue<node *> q;
    vector<string> visited;
    node *a;
    a = arr[0]
    if(a != NULL){
        q.push(a);
    }
    while(q.front() != NULL){
        node *b = q.pop();
        while(b != NULL){
            cout<<b->landmark<<endl;
            if(find(visited.begin(),visited.end(),b->landmark)){
                visited.push_back(b->landmark);
            }
            q.push(b);
            b = b->next;
        }
    }
}
int main() {
	        GraphAdjan g;
			int ch;
			int flag = 1;
			while (true && flag){
			        cout << "\n<-----MENU----->" << endl;
			        cout << "1. Add total landmarks "<< endl;
			        cout << "2. Connect landmarks " << endl;
			        cout << "3. Display graph " << endl;
//			        cout << "4. Delete key" << endl;
			        cout << "4. Exit" << endl;
			        cout << "Enter choice : ";
			        cin >> ch;
			        switch (ch)
			        {
			        case 1:
			        {
			            g.insertNode();
			        	break;
			        }
			        case 2:
			        {
			            g.connectNodes();
			            break;
			        }
			        case 3:
			        {
			        	g.DisplayNodes();
						break;
			        }
//			        case 4:
//			        {
//
//			        	break;
//			        }
			        case 4:
			        	cout<<"\nProgram ended successfully!"<<endl;
			        	flag = 0;
			            break;
			        default:
			            cout << "Please, enter valid choice!" << endl;
			        }
			    }
			return 0;
}
