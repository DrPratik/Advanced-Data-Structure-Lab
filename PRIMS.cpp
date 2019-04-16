#include<iostream>
using namespace std;
class prim
{
private:
	int M[30][30],n,i,j,v1,v2,flag;
	char z;
	int cost[10][10];
	public:
	void create()
    	{
    		for(i=0;i<10;i++)
    		{
    			for(j=0;j<10;j++)
    			{
    				cost[i][j]=0;
    			}
    		}
    	int visited[50];
	       cout<<"\nEnter 0.For Directed Graph 1.For undirected graph :";
        cin>>flag;

        cout<<"\nEnter number of vertices in the graph :";
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                M[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
            visited[i]=0;

        do
        {
            cout<<"\nEnter the two vertices having edge :";
            cin>>v1>>v2;

            if(v1>=n || v2>=n)
            {
                cout<<"\nInvalid input for vertices."<<endl;
            }
            else
            {
            	cout<<"enter cost";
            	cin>>cost[v1][v2];
                M[v1][v2]=cost[v1][v2];

                if(flag==1)
                {
                    M[v2][v1]=cost[v1][v2];
                }
            }
            cout<<"\nWant to continue inserting edges in adjacency matrix? (Y/N) :";
            cin>>z;
        }while(z=='Y'|| z=='y');
        for(i=0;i<n;i++)
        {
        	for(j=0;j<n;j++)
        	{
        	cout<<M[i][j]<<"\t";
        	}
        	cout<<endl;
        }
	}
	void prims()
	{
		int visited[10],source[10],dist[10];
		int sp[n][n];
		int min_cost=0,u,v,i,j,E,mindist;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		sp[i][j]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(M[i][j]==0)
				cost[i][j]=99;
				else
				cost[i][j]=M[i][j];
			}
		}
		dist[0]=0;
		visited[0]=1;
		for(i=1;i<n;i++)
		{
			dist[i]=cost[0][i];
			source[i]=0;
			visited[i]=0;
		}
		min_cost=0;
		E=n-1;
		while(E>0)
		{
			mindist=99;
			for(i=1;i<n;i++)
			{
				if(visited[i]==0 && dist[i]<mindist)
				{
					mindist=dist[i];
					v=i;
				}
			}
			u=source[v];
			sp[u][v]=dist[v];
			sp[v][u]=dist[v];
			E--;
			visited[v]=1;
			for(i=1;i<n;i++)
			{
				if(visited[i]==0 && cost[v][i]<dist[i])
				{
					dist[i]=cost[v][i];
					source[i]=v;
				}
			}
			min_cost=min_cost+cost[u][v];
		}
		cout<<"\nminimum cost:"<<min_cost;
		cout<<"\nMinimum spanning tree\n";
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<sp[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
};
int main()
{
	prim p;
	p.create();
	p.prims();
}
	
