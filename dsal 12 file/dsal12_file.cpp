/*
Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use
sequential file to main the data.
*/

#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
	char name[10];
	int roll;
	void getdata()
	{
		cout << "\n Enter the roll no and name:";
		cin >> roll >> name;
	}

	void putdata()
	{
		cout << "\n The roll no and name:";
		cout << roll << "    " << name;
	}
};

class file
{
	fstream fp;

public:
	void create()
	{
		char ans;
		student s;
		fp.open("stu.txt", ios::out);
		do
		{
			s.getdata();
			fp.write((char *)&s, sizeof(s));
			cout << "\n Add More?(y/n)" << endl;
			cin >> ans;
		} while (ans == 'Y' || ans == 'y');
		fp.close();
	}
	void append()
	{
		char ans;
		student s;
		fp.open("stu.txt", ios::app);
		do
		{
			s.getdata();
			fp.write((char *)&s, sizeof(s));
			cout << "\n Add More?(y/n)" << endl;
			cin >> ans;
		} while (ans == 'Y' || ans == 'y');
		fp.close();
	}
	void display()
	{
		student s;
		fp.open("stu.txt", ios::in);
		while (!fp.eof())
		{
			fp.read((char *)&s, sizeof(s));
			if (!fp.eof())
				s.putdata();
		}
		fp.close();
	}
	void search()
	{
		student s;
		int flag = 0;
		cout << "\n Enter roll to be searched:";
		int r;
		cin >> r;
		fp.open("stu.txt", ios::in);
		while (!fp.eof())
		{
			fp.read((char *)&s, sizeof(s));
			if (!fp.eof() && s.roll == r)
			{
				flag = 1;
				s.putdata();
				break;
			}
		}
		if (flag == 0)
			cout << "\n Not found" << endl;
		fp.close();
	}
	void delete1()
	{
		student s;
		int flag = 0;
		fstream fp1;
		cout << "\n Enter roll to be deleted:";
		int r;
		cin >> r;
		fp.open("stu.txt", ios::in);
		fp1.open("temp.txt", ios::out);
		while (fp.read((char *)&s, sizeof(s)))
		{

			if (s.roll != r)
			{
				flag = 1;
				fp1.write((char *)&s, sizeof(s));
			}
		}
		if (flag == 0)
			cout << "\n Not found" << endl;
		fp.close();
		fp1.close();
		remove("stu.txt");
		rename("temp.txt", "stu.txt");
	}
};

int main()
{
	file f;
	int choice = 0;
	do
	{
		cout << "\n<---- MAIN MENU ---->"
			 << endl;
		cout << "\n 1 Create \n 2 Display \n 3 Search \n 4 Append \n 5 Delete \n 6 Exit";
		cout << "\n Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			f.create();
			break;
		case 2:
			f.display();
			break;
		case 3:
			f.search();
			break;
		case 4:
			f.append();
			break;
		case 5:
			f.delete1();
			break;
		case 6:
			cout << "\nThank You!"
				 << endl;
			choice = 0;
			break;
		}
	} while (choice != 0);
}
