#include<iostream>
#include<iomanip>
#include<cstring>
#define size 10
using namespace std;
class hash1
{
	struct hashtable
	{
		long int no;
		string name;
		string company;
	}t1[size];
	public:
	hash1()
	{
		for(int i=0;i<size;i++)
		{
			t1[i].no=-1;
			t1[i].name="-----";
			t1[i].company="-----";
		}
	}
	void insert()
	{
		cout<<"enter number\t";
		long int n;
		cin>>n;
		cout<<"enter name";
		string na,c;
		cin>>na;
		cout<<"enter company name";
		cin>>c;
		int t=hash_fun(n);
		if(t1[t].no==-1)
		{
			t1[t].no=n;
			t1[t].name=na;
			t1[t].company=c;
		}
		else
		{
			collision(t,n,na,c);
		}
	}
	inline int hash_fun(long int n)
	{
		return (n % size);
	}
	void collision(int t,long int n,string na,string c)
	{
		for(int i=t;i!=(t-1);i++)
		{
			if(i==size)
			i=0;
			if(t1[i].no==-1)
			{
				t1[i].no=n;
				t1[i].name=na;
				t1[i].company=c;
				break;
			}
		}
	}
	void display()
	{
		cout<<setw(10)<<"Number"<<setw(20)<<"Name"<<setw(20)<<"ISP"<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<setw(10)<<t1[i].no<<setw(20)<<t1[i].name<<setw(20)<<t1[i].company<<endl;
		}
	}
	int search(long int n)
	{
		int t=hash_fun(n);
		int i;
		for( i=t;i!=(t-1);t++)
		{
			if(t1[i].no==n)
			{
			cout<<"record found\n";
			cout<<setw(10)<<t1[i].no<<setw(20)<<t1[i].name<<setw(20)<<t1[i].company<<endl;				
			return i;
			}
		}
		if(i==t-1)
		cout<<"record absent";
		return -1;
	}
	void delet(long int n)
	{
		int i=search(n);
		if(i==-1)
		{	
		}
		else
		{
			cout<<"Are you sure to delete above data[1/0]?";
			int c;
			cin>>c;
			if(c==1)
			{
				t1[i].no=-1;
				t1[i].name="-----";
				t1[i].company="-----";
			}
			else
			{
				cout<<"operation canceled";
			}
		}
	}
};
int main()
{
	int ch;
	long int n;
	hash1 h;
	do
	{
	cout<<"1.insert\n2.display\n3.search\n4.delete\n5.exit\nenter...\n";
	cin>>ch;
	switch(ch)
	{
		case 1:	h.insert();break;
		case 2: 	h.display();break;
		case 3: 	cout<<"enter number to find";
				cin>>n;
				h.search(n);break;
		case 4: 	cout<<"enter number to delete";
				cin>>n;
				h.delet(n);break;
		case 5: cout<<"exiting...\n";break;		
		default:cout<<"wrong input";break;
	}
	}while(ch<5);
}
