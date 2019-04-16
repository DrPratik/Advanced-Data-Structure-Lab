#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class set
{
	node *h1,*h2;
	public:
	set()
	{
		h1=NULL;
		h2=NULL;
	}
	void create()
	{
		cout<<"enter number of elements in set A";
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			node *nn;
			nn=new node;
			cout<<"enter "<<i<<" element";
			cin>>nn->data;
			nn->next==NULL;
			if(h1==NULL)
			{
				h1=nn;
			}
			else
			{
				node *cn=h1;
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}
				cn->next=nn;
			}
		}
		cout<<"enter number of elements in set B";
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			node *nn;
			nn=new node;
			cout<<"enter "<<i<<" element";
			cin>>nn->data;
			nn->next==NULL;
			if(h2==NULL)
			{
				h2=nn;
			}
			else
			{
				node *cn=h2;
				while(cn->next!=NULL)
				{
					cn=cn->next;
				}
				cn->next=nn;
			}
		}
	}
	void display()
	{
		node *cn1,*cn2;
		cn1=h1;
		cout<<"A\n";
		while(cn1!=NULL)
		{
			cout<<cn1->data<<"\t";
			cn1=cn1->next;
		}
		cout<<"\nB\n";
		cn2=h2;
		while(cn2!=NULL)
		{
			cout<<cn2->data<<"\t";
			cn2=cn2->next;
		}
	}
	void un()
	{
		node *cn1=h1;
		node *cn2=h2;
		cout<<"Union\t";
		while(cn1!=NULL)
		{
			cout<<cn1->data<<"\t";
			cn1=cn1->next;
		}
		int flag=0;
		while(cn2!=NULL)
		{
			flag=0;
			cn1=h1;
			while(cn1!=NULL)
			{
				if(cn2->data==cn1->data)
				{
					flag=1;
					break;
				}
				cn1=cn1->next;
			}
			if(flag==0)
			{
				cout<<cn2->data<<"\t";
			}
			cn2=cn2->next;
		}
	}
			
	void ine()
	{
		node *cn1,*cn2;
		cn1=h1;
		cn2=h2;
		cout<<"intersection\t";
		while(cn1!=NULL)
		{
			cn2=h2;
			while(cn2!=NULL)
			{
				if(cn1->data==cn2->data)
				{
					cout<<cn1->data<<"\t";
					break;
				}
				cn2=cn2->next;
			}
			cn1=cn1->next;
		}
	}
	void diff()
	{
		cout<<"A-B\n";
		node *cn1=h1;
		node *cn2=h2;
		int flag=0;
		while(cn1!=NULL)
		{
			flag=0;
			cn2=h2;
			while(cn2!=NULL)
			{
				if(cn1->data==cn2->data)
				{
					flag=1;
					break;
				}
				cn2=cn2->next;
			}
			if(flag==0)
			{
				cout<<cn1->data<<"\t";
			}
			cn1=cn1->next;
		}
		cout<<"B-A\n";
		cn1=h1;
		cn2=h2;
		flag=0;
		while(cn2!=NULL)
		{
			flag=0;
			cn1=h1;
			while(cn1!=NULL)
			{
				if(cn2->data==cn1->data)
				{
					flag=1;
					break;
				}
				cn1=cn1->next;
			}
			if(flag==0)
			{
				cout<<cn2->data<<"\t";
			}
			cn2=cn2->next;
		}
	}
};
int main()
{
	set s;
	s.create();
	s.display();
	s.ine();
	s.un();
	s.diff();
}					
