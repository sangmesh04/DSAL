//============================================================================
// Name        : dsal04 hash using node.cpp
// Author      : sangmeshwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================



/*

Consider telephone book database of N clients. Make use of a hash table
implementation to quickly look up client‘s telephone number. Make use of two
collision handling techniques and compare them using number of comparisons
required to find a set of telephone numbers (use linear probing with replacement and
without replacement)

 */


#include <iostream>
using namespace std;

struct node{
	long long int tel;
	string name;
	int nextIndex;
	struct node * next;
};

class HashTable{
	int N = 10;
	node * telArr[10] = {NULL};
public:

	int divisionMethod(long long int a);
	node * InsertByChainingTel();
	void insertByWithOutReplacement();
	void insertByWithReplacement();
	void searchForTelByWithOutReplacement();
	void displayDiary();
};


int HashTable::divisionMethod(long long int a){
	int index;
	index = a%N;
	return index;
}

/*node * HashTable::InsertByChainingTel(){
	long long int t;
	string s;
	cout<<"Enter telephone number: "<<endl;
	cin>>t;
	cout<<"Enter person's name: "<<endl;
	cin>>s;
	int i;
	i = divisionMethod(t);
	node * x;
	x = new node;
	x->name = s;
	x->tel = t;
	if(telArr[i] == NULL){
		telArr[i] = x;
	}else{
		node * y = telArr[i];
		while(y->next != NULL){
			y = y->next;
		}
		y->next = x;
	}
	return x;
}*/

void HashTable::insertByWithReplacement(){
	long long int t;
	string s;
	cout<<"Enter telephone number: "<<endl;
	cin>>t;
	cout<<"Enter person's name: "<<endl;
	cin>>s;
	int i;
	i = divisionMethod(t);
	int flag = 1;
	node * x;
	x = new node;
	x->name = s;
	x->tel = t;
	x->nextIndex = -1;
	if(telArr[i] == NULL){
		flag = 0;
		telArr[i] = x;
	}else{
		int l;
		l = telArr[i]->nextIndex;
	}
}


void HashTable::insertByWithOutReplacement(){
	long long int t;
	string s;
	int flag =1;
	cout<<"Enter telephone number: "<<endl;
	cin>>t;
	cout<<"Enter person's name: "<<endl;
	cin>>s;
	int i;
	i = divisionMethod(t);
	node * x;
	x = new node;
	x->name = s;
	x->tel = t;
	if(telArr[i] == NULL){
		telArr[i] = x;
		flag  = 0;
	}else{
		for(int j=i;j<N;j++){
			if(telArr[j] == NULL){
				telArr[j] = x;
				flag = 0;
				break;
			}
		}
		if(flag){
			for(int k =0; k< i;k++){
				if(telArr[k] == NULL){
						telArr[k] = x;
						flag = 0;
						break;
				}
			}
		}
	}
	if(flag){
		cout<<"The diary capacity is full!"<<endl;
		cout<<"Unable to insert telephone number in diary!"<<endl;
	}
}

void HashTable::searchForTelByWithOutReplacement(){
	int count = 0;
	long long int tel;
	cout<<"Enter telephone to be searched: "<<endl;
	cin>>tel;
	int flag = 1;
	int i = divisionMethod(tel);
	if(telArr[i]->tel == tel){
		flag = 0;
		cout<<"Telephone found!"<<endl;
		cout<<i<<". "<<telArr[i]->name<<"   |   "<<telArr[i]->tel<<endl;
		count+=1;
		cout<<"The number of comparisons: "<<count<<endl;
	}else{
		cout<<"test";
		for(int j=i;j<N;j++){
			count+=1;
					if(telArr[j]->tel == tel){
						flag = 0;
						cout<<"Telephone found!"<<endl;
						cout<<j<<". "<<telArr[j]->name<<"   |   "<<telArr[j]->tel<<endl;
						cout<<"The number of comparisons: "<<count<<endl;
						break;
					}
				}
				if(flag){
					for(int k =0; k< i;k++){
						count+=1;
						if(telArr[k]->tel == tel){
							flag = 0;
							cout<<"Telephone found!"<<endl;
							cout<<k<<". "<<telArr[k]->name<<"   |   "<<telArr[k]->tel<<endl;
							cout<<"The number of comparisons: "<<count<<endl;
							break;
						}
					}
				}

	}
	if(flag){
		cout<<"The telephone is not present in diary!"<<endl;
		cout<<"Count for comparisons are: "<<count<<endl;
	}
}

void HashTable::displayDiary(){
	cout<<"index| "<<" Name"<<"       "<<"| Telephone  "<<endl;
	node * temp;
	for(int j =0;j<N;j++){
		temp = telArr[j];
		if(temp != NULL){
			if(temp->next == NULL){
			cout<<j<<". |"<<temp->name<<"     | "<<temp->tel<<endl;
			}else{
				node * y = temp;
				while(y != NULL){
					cout<<j<<". |"<<y->name<<"     | "<<y->tel<<endl;
					y = y->next;
				}
			}
		}else{
			cout<<j<<". |"<<"Person"<<"     | "<<0<<endl;
		}
	}
}


int main() {
	HashTable h;
		int ch;
		int flag = 1;
		int num;
		while (true && flag){
		        cout << "\n<-----MENU----->" << endl;
		        cout << "1. Insert telephone by linear probing without replacement "<< endl;
		        cout << "2. Insert telephone by chaining method " << endl;
		        cout << "3. Display " << endl;
		        cout << "4. Search Telephone" << endl;
		        cout << "5. Exit" << endl;
		        cout << "Enter choice : ";
		        cin >> ch;
		        switch (ch)
		        {
		        case 1:
		        {
		            cout<<"How many contacts you want to add? "<<endl;
		            cin>>num;
		            for(int i=0;i<num;i++)
                        h.insertByWithOutReplacement();
		        	break;
		        }
		        case 2:
		        {
		        	h.InsertByChainingTel();
		            break;
		        }
		        case 3:
		        {
					h.displayDiary();
					break;
		        }
		        case 4:
		        {
		        	h.searchForTelByWithOutReplacement();
		        	break;
		        }
		        case 5:
		        	cout<<"\nProgram ended successfully!"<<endl;
		        	flag = 0;
		            break;
		        default:
		            cout << "Please, enter valid choice!" << endl;
		        }
		    }
		return 0;
}

