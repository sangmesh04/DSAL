//============================================================================
// Name        : assignment05.cpp
// Author      : Sangmeshwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*

Implement all the functions of a dictionary (ADT) using hashing and handle
collisions using separate chaining using linked list.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
comparable, Keys must be unique.
Standard Operations: Insert (key, value), Find(key), Delete(key)

*/

#include<iostream>
using namespace std;

struct node{
    string key;
    string value;
    struct node * next;
};

class HashTable{
    int N=10;
    node * dictionary[10] = {NULL};
public:
    int hashMethod(string s);
    void insertByChaining();
    void displayHashTable();
    bool find(string s);
    void deleteKey();
};

int HashTable::hashMethod(string s){
    int ascii = 0;
    int x;
    for(int i=0;i<1;i++){
        x = s[i];
        ascii += x;
    }
    int index = ascii%N;
    return index;
}

void HashTable::insertByChaining(){
	string c;
	string s;
	cout<<"Enter key: "<<endl;
	cin>>c;
	cout<<"Enter value: "<<endl;
	cin>>s;
	int i;
	i = hashMethod(c);
	node * x;
	x = new node;
	x->key = c;
	x->value = s;
	x->next = NULL;
	if(dictionary[i] == NULL){
		dictionary[i] = x;
	}else{
		node * y = dictionary[i];
		while(y->next != NULL){
			y = y->next;
		}
		y->next = x;
	}
}

void HashTable::displayHashTable(){
    node *x;
    for(int j=0;j<N;j++){
        x = dictionary[j];
        if(x != NULL){
            while(x != NULL){
                if(x != NULL){
                    cout<<j<<". "<<x->key<<" : "<<x->value<<endl;
                }
                x = x->next;
            }
        }else{
            cout<<j<<". "<<"KEY"<<" : "<<"VALUE"<<endl;
        }
    }
}

bool HashTable::find(string s){
	int index;
	index = hashMethod(s);
	node * x;
	int flag = 1;
	x = dictionary[index];
	//cout<<"index: "<<index<<endl;
if(x != NULL){
		while(flag and x != NULL){
			if(x->key == s){
				flag = 0;
				cout<<"Key is present!"<<endl;
				cout<<x->key<<" : "<<x->value<<endl;
				return true;
			}
			x= x->next;
		}
	}
if(flag){
	cout<<"Key is not present!"<<endl;
}
return false;
}

void HashTable::deleteKey(){
	string s;
	cout<<"Enter the key to be deleted: "<<endl;
	cin>>s;
	if(find(s)){
		int index;
		index = hashMethod(s);
		node *x,*y;
		x = dictionary[index];
		int flag = 1;
		if(x->key == s){
			y = x->next;
			dictionary[index] = y;
			delete x;
			flag = 0;
			cout<<"Key deleted successfully!"<<endl;
		}else{
			y = x->next;
			while(y != NULL and flag){
				if(y->key == s){
					x->next = y->next;
					delete y;
					flag = 0;
					cout<<"Key deleted successfully!"<<endl;
				}
					x = x->next;
					y = x->next;
			}
		}
	}
}

int main(){
    HashTable h;
		int ch;
		int flag = 1;
		int num;
		while (true && flag){
		        cout << "\n<-----MENU----->" << endl;
		        cout << "1. Insert element in dictionary "<< endl;
		        cout << "2. Display dictionary " << endl;
		        cout << "3. Search key " << endl;
		        cout << "4. Delete key" << endl;
		        cout << "5. Exit" << endl;
		        cout << "Enter choice : ";
		        cin >> ch;
		        switch (ch)
		        {
		        case 1:
		        {
		            cout<<"How many words you want to add? "<<endl;
		            cin>>num;
		            for(int i=0;i<num;i++)
                        h.insertByChaining();
		        	break;
		        }
		        case 2:
		        {
		            h.displayHashTable();
		            break;
		        }
		        case 3:
		        {
		        	string s;
		        	cout<<"Enter key to be searched: "<<endl;
		        	cin>>s;
		        	h.find(s);
					break;
		        }
		        case 4:
		        {
		        	h.deleteKey();
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
