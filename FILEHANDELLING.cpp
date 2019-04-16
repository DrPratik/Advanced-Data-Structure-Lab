#include<iostream>
#include<fstream>
using namespace std;
class stud
{
	int rno;
	char name[30];
	char add[30];
	char div;
	
	public:
	void get()
	{
		cout<<"enter details";
		cout<<"enter name";
		cin>>name;
		cout<<"enter div";
		cin>>div;
		cout<<"enter roll no";
		cin>>rno;
		cout<<"enter address city";
		cin>>add;
	}
	void addrecord()
	{
		fstream fout;
		stud st;
		st.get();
		fout.open("Myfile.bin",ios::binary|ios::out|ios::app);
		fout.write((char*)&st,sizeof(st));
		cout<<"Record added succefully!";
		fout.close();
	}
	void display()
	{
		ifstream fin;
		stud st;
		fin.open("Myfile.bin",ios::binary|ios::in);
		while(fin.read((char*)&st,sizeof(st)))
		{
			cout<<"rrecord";
			cout<<st.name<<"\t"<<st.rno<<"\t"<<st.add<<"\t"<<st.div;
			cout<<endl;
		}
		fin.close();
	}
	void delet()
	{
		remove("Myfile.bin");
	}
	stud search(int no)
	{
		ifstream f;
		stud st;
		f.open("Myfile.bin",ios::binary|ios::in);
		while(f.read((char*)&st,sizeof(st)))
		{
			if(st.rno==no)
			{
				cout<<"record found!!\n";
				cout<<st.rno<<"\t"<<st.name<<"\t"<<st.div<<"\t"<<st.add;
				cout<<endl;
				return st;
			}
		}
		cout<<"No record found";
		
	}
	void update(int no)
	{
		fstream f;
		stud st;
		f.open("Myfile.bin",ios::binary|ios::in|ios::out);
		while(f.read((char*)&st,sizeof(st)))
		{
			if(st.rno==no)
			{
				cout<<"record found!!";
				  cout<<"\n Details:\n";
		          cout<<" Name: ";
		          cout<<st.name<<endl;
		          cout<<" RollNumber: ";
		          cout<<st.rno<<endl;
		          cout<<" Division: ";
		          cout<<st.div<<endl;
		          cout<<" Address: ";
		          cout<<st.add<<endl;
		          st.get();
		          int pos=-1*sizeof(st);
		          f.seekp(pos,std::ios::cur);
		          f.write((char*)&st,sizeof(st));
		          return;
		         }
		 }
		 cout<<"record absent";
	}
};
int main()
{
	stud obj;
	int ch,no;
	do
	{
	cout<<"1.add record\n2.display\n3.delete\n4.search\n5.update\nenter...";
	cin>>ch;
	switch(ch)
	{
		case 1:obj.addrecord();
			break;
		case 2:obj.display();
			break;
		case 3:obj.delet();
			break;
		case 4:cout<<"enter number to search";
			cin>>no;
			obj.search(no);break;
		case 5:cout<<"enter number to update";
			cin>>no;
			obj.update(no);break;
		default:break;
		
	}
	}
	while(ch<6);
}
