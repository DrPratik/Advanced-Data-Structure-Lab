#include<iostream>
#include<iomanip>
using namespace std;
struct node
{
	string name,type,inival;
	int line[10];
	int count;
	node *next;
};
class symb
{
	node *hn;
	node *cn1;
	public: 
	symb()
	{
		hn=NULL;
	}
	void insert()
	{
		node *nn;
		nn= new node;
		nn->next=NULL;
		cout<<"enter variable name";
		cin>>nn->name;
		cout<<"enter type";
		cin>>nn->type;
		cout<<"enter initial value";
		cin>>nn->inival;
		int ch;
		int i=0;
		do
		{
			cout<<"enter line number";
			cin>>nn->line[i++];
			cout<<"do you want to add another line number";
			cin>>ch;
		}
		while(ch==1);
		nn->count=i;
		if(hn==NULL)
		{
			hn=nn;
		}
		else
		{
			node *cn=hn;
			while(cn->next!=NULL)
			{
				cn=cn->next;
			}
			cn->next=nn;
		}
	}
	void display()
	{
		cout<<setw(10)<<"Name"<<setw(10)<<"Type"<<setw(10)<<"Initial"<<setw(10)<<setw(20)<<"line"<<setw(20)<<"count"<<endl;
		node *cn=hn;
		while(cn!=NULL)
		{
			cout<<setw(10)<<cn->name<<setw(10)<<cn->type<<setw(10)<<cn->inival<<setw(20);
			for(int i=0;i<cn->count;i++)
			{
				cout<<cn->line[i]<<",";
			}
			cout<<setw(20)<<cn->count;
			cn=cn->next;
			cout<<endl;
		}
	}
	node* search(string k)
	{
		cn1=hn;
		while(cn1!=NULL)
		{
			if(cn1->name==k)
			{
				cout<<"record found\n";
				cout<<setw(10)<<cn1->name<<setw(10)<<cn1->type<<setw(10)<<cn1->inival<<setw(20);
				for(int i=0;i<cn1->count;i++)
				{
					cout<<cn1->line[i]<<",";
				}
					cout<<setw(10)<<cn1->count<<endl;
				return cn1;
			}
			cn1=cn1->next;
		}
		cout<<"404:Not found\n";
		return NULL;
	}
	void modify(string k)
	{
		node *cn=search(k);
		if(cn==NULL)
		{
		}
		else
		{
			cout<<"enter new name";
			cin>>cn->name;
			cout<<"enter type";
			cin>>cn->type;
			cout<<"enter initial value";
			cin>>cn->inival;
			int ch;
			int i=0;
			do
			{
				cout<<"enter line number";
				cin>>cn->line[i++];
				cout<<"do you want to add another line number";
				cin>>ch;
			}
			while(ch==1);
			cn->count=i;
		}
	}
	void delet()
	{
		cout<<"enter string to delete";
		string k;
		cin>>k;
		node *cn=hn;
		if(hn->name==k)
		{
			node *temp=hn;
			hn=hn->next;
			delete(temp);
		}
		else
		{
			while(cn->next!=NULL)
			{
				if(cn->next->name==k)
				{
					node *temp=cn->next;
					cn->next=cn->next->next;
					delete(temp);
					return;
				}
				if(cn->next==NULL)
			{
				delete(cn);
			}
				cn=cn->next;
			}
			
			cout<<"variable not found";
		}
	}
			
};
int main()
{
	int ch;
	symb s;
	string k;
	do
	{
	cout<<"1.Insert\n2.display\n3.search\n4.modify\n5.delete\nenter..";
	cin>>ch;
	switch(ch)
	{
		case 1:s.insert();break;
		case 2:s.display();break;
		case 3:cout<<"enter variable to search";cin>>k;s.search(k);break;
		case 4:cout<<"enter variable to modify";cin>>k;s.modify(k);break;
		case 5:s.delet();break;
		default:break;
	}
	}while(ch<6);
}
