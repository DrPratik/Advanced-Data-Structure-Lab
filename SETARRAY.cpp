#include<iostream>
using namespace std;
class set
{
	int a[10],b[10],un[10],in[10],difff[10];
	int n,m;
	public:
	set()
	{
		for(int i=0;i<10;i++)
		{
			a[i]=b[i]=un[i]=in[i]=difff[i]=0;
		}
		n=m=0;
	}
	void create()
	{
		cout<<"enter number of elements in a";
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cout<<"enter "<<i+1<<" element:";
			cin>>a[i];
		}
		cout<<"enter number of elements in b";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"enter "<<i+1<<" element:";
			cin>>b[i];
		}
	}
	void display()
	{
		cout<<"elements of a\n";
		for(int i=0;i<m;i++)
		{
			cout<<a[i]<<"\t";
		}
		cout<<endl;
		cout<<"elements of b\n";
		for(int i=0;i<n;i++)
		{
			cout<<b[i]<<"\t";
		}
		cout<<endl;
	}
	void uni()
	{
		int flag=0;
		int u,j;
		for(u=0;u<m;u++)
		{
			un[u]=a[u];
		}
		for(j=0;j<n;j++)
		{
			flag=0;
			for(int k=0;k<m;k++)
			{
				if(a[k]==b[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				un[u]=b[j];
				++u;
			}
		}
		cout<<"UNion:\n";
		for(int i=0;i<u;i++)
		cout<<un[i]<<"\t";
	}
	void inte()
	{
		int u=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[j]==b[i])
				{
					in[u]=a[j];
					
					u++;
					break;
				}
			}
		}
		cout<<"INtersectio\n";
		for(int i=0;i<u;i++)
		cout<<in[i]<<"\t";
	}
	void diff()
	{
		int flag=0;
		int u=0;
		for(int i=0;i<m;i++)
		{
			flag=0;
			for(int j=0;j<n;j++)
			{
				if(a[i]==b[j])
				{
				flag=1;
				break;
				}
			}
			if(flag==0)
			{
				difff[u]=a[i];
				u++;
			}
		}
		cout<<"\nA-B\t";
		for(int i=0;i<u;i++)
		cout<<difff[i]<<"\t";
		flag=0;
		u=0;
		for(int i=0;i<u;i++)
		difff[i]=0;
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=0;j<m;j++)
			{
				if(b[i]==a[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				difff[u]=b[i];
				u++;
			}
		}
		cout<<"B-A\t";
		for(int i=0;i<u;i++)
		cout<<difff[i]<<"\t";
	}
};
int main()
{
	set s;
	s.create();
	s.display();
	s.uni();
	s.inte();
	s.diff();
}
		
