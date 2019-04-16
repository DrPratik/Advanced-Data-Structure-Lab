#include<iostream>
using namespace std;
struct node
{
	int vertex;
	node *next;
};
class graph
{
	node *hn[10];
	int m[10][10];
	int v;
	public:
	graph()
	{	v=0;
		for(int i=0;i<9;i++)
		{
			hn[i]=NULL;
		}
		for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		m[i][j]=0;
	}
	void adj_mat()
	{
		cout<<"enter number of vertices\n";
		cin>>v;
		int i,j,n;
		do
		{
		cout<<"enter pair of vertices to establish an edge:\n";
		cin>>i>>j;
		if(i>=v || j>=v)
		{
			cout<<"INVALID EDGE\n";
		}
		else
		m[i][j]=m[j][i]=1;
		cout<<"do you want to continue\n";
		cin>>n;
		}
		while(n==1);
	}
	void dis_mat()
	{
		for(int i=0;i<v;i++)
		{
			cout<<"\n";
			for(int j=0;j<v;j++)
			{
				cout<<m[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<endl;
	}
	void adj_list()
	{
		int i,j,n;
		cout<<"enter number of vertics\n";
		cin>>v;
		do
		{
			cout<<"enter pair of vertices to establish an edge\n";
			cin>>i>>j;
			if(i>=v || j>=v)
			cout<<"INVALID EDGE";
			else
			{
				add_edge(i,j);
				add_edge(j,i);
			}
			cout<<"do you want to continue\n";
			cin>>n;
		}
		while(n==1);
	}
	void add_edge(int i,int j)
	{
		node *cn,*nn;
		nn=new node;
		nn->vertex=j;
		nn->next=NULL;
		if(hn[i]==NULL)
		hn[i]=nn;
		else
		{
			cn=hn[i];
			while(cn->next!=NULL)
			cn=cn->next;
			cn->next=nn;
		}
	}
	void dis_list()
	{
		node *cn;
		for(int i=0;i<v;i++)
		{
			cn=hn[i];
			while(cn!=NULL)
			{
				cout<<i<<"->"<<cn->vertex;
				cout<<"\t";
				cn=cn->next;
			}
			cout<<"\n";
		}
	}
		
};
int main()
{
	graph h;
	int ch;
	do
	{
	cout<<"1.adjacent matrix\n2.display matrix\b\n3.adjacent list\n4.display list\n5.Exit\nenter..\n";
	cin>>ch;
	switch(ch)
	{
		case 1:h.adj_mat();break;
		case 2:h.dis_mat();break;
		case 3:h.adj_list();break;
		case 4:h.dis_list();break;
		case 5:break;
		default:cout<<"WRONG INPUT\n";break;
	}
	}
	while(ch!=5);
}
