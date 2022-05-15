/*
Implement the Heap sort algorithm implemented in CPP/Java demonstrating heap
data structure with modularity of programming language
*/

#include <iostream>
using namespace std;

int n1=0;
int*arr;

class heap1{
public:

void MAX_HEAPIFY(int a[], int i, int n)
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
       largest=l;
    else
       largest=i;

    if((r<=n)&&(a[r]>a[largest]))
       largest=r;
   if(largest!=i)
    {
         loc=a[i];
         a[i]=a[largest];
         a[largest]=loc;
         MAX_HEAPIFY(a, largest,n);
    }
}
void BUILD_MAX_HEAP(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        MAX_HEAPIFY(a, k, n);
    }
}
void HEAPSORT(int a[], int n)
{

    BUILD_MAX_HEAP(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MAX_HEAPIFY(a, 1, i - 1);
    }
}

void accept(){
	    cout<<"Enter the number of elements: "<<endl;
	    cin>>n1;
	    arr=new int[n1];
	    cout<<"Enter elements: "<<endl;
	    for (int i = 1; i <= n1; i++)
	    {
	        cin>>arr[i];
	    }
}
void display(){
      cout<<"\n<---- ELEMENTS ---->"<<endl;
	    for (int i = 1; i <=n1; i++)
	    {
	        cout<<arr[i]<<endl;
	    }

}

};

int main()
{
    heap1 h;
	int choice = 0;
	do
	{
		cout << "\n<---- MENU ---->"<< endl;
		cout << "\n1.Input \n2.Display \n3.Heap sort  \n4.Exit"<< endl;
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl;
			h.accept();
			break;

        case 2:
            cout<<endl;
            h.display();
            break;

		case 3:
			cout << endl;
            h.HEAPSORT(arr,n1);
			cout << endl;
			break;

		case 4:
			cout << "\nTHANK YOU!" << endl;
			choice = 0;
			break;
		default:
			break;
		}

	} while (choice != 0);

	return 0;
}
