#include<iostream>
#include<cstring>
using namespace std;
struct node
{
	node *l;
	node *r;
	string w;
	string m;
};
class tree
{
	node *root;
	node *nn;
	node *parent;
	node *cn;
	public:
	tree()
	{
		root=NULL;
	}
	void create()
	{
		cout<<"enter w";
		nn=new node;
		cin>>nn->w;
		cout<<"enter meaning";
		cin>>nn->m;
		nn->l=NULL;
		nn->r=NULL;
		if(root==NULL)
		{
			root=nn;
		}
		else
		{
			node *temp=root;
			while(temp!=NULL)
			{
				parent=temp;
				if(nn->w<temp->w)
				{
					temp=temp->l;
				}
				else
				{
					temp=temp->r;
				}
			}
			if(nn->w<parent->w)
			{
				parent->l=nn;
			}
			else
			{
				parent->r=nn;
			}
		}
	}
	void preorder(node *temp)
	{
		if(temp!=NULL)
		{
			cout<<temp->w<<"-"<<temp->m<<"\t";
			preorder(temp->l);
			preorder(temp->r);
		}
		cout<<endl;
	}
	void inorder(node *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->l);
			cout<<temp->w<<"-"<<temp->m<<"\t";
			inorder(temp->r);
		}		
		cout<<endl;
	}
	void postorder(node *temp)
	{
		if(temp!=NULL)
		{
			postorder(temp->l);
			postorder(temp->r);
			cout<<temp->w<<"-"<<temp->m<<"\t";
		}
		cout<<endl;
	}	
	void display()
	{
		cout<<"PREORDER\n";
		preorder(root);
		cout<<endl<<"INORDER"<<endl;
		inorder(root);
		cout<<endl<<"POSTORDER"<<endl;
		postorder(root);
	}	
	node search(string key)
	{
		cn=root;
		while(cn!=NULL)
		{
			if(key==cn->w)
			{
				cout<<"m-\t"<<cn->m;
				return *cn;
			}
			else if(key<cn->w)
			{
				parent= cn;
				cn=cn->l;
			}
			else
			{
				parent= cn;
				cn=cn->r;
			}
		}
		if(cn==NULL)
		{
			cout<<"w absent\n";
		}
	}
	void modify()
	{
		cout<<"enter w to modify its m\n";
		string k;
		cin>>k;
		search(k);
		cout<<"enter new meaning";
		cin>>cn->m;
	}
	void delet(string key)
	{
	
    		node *cn,*parent;
		cn=root;
		while(cn!=NULL)
		{
			
			if(cn->w==key)
			break;
			else
			{
				parent=cn;
				if(cn->w>key)
				cn=cn->l;
				else
				cn=cn->r;
			}
		}
		if(cn==NULL)
		cout<<"Word absent";
		//0
		if(cn->l==NULL && cn->r==NULL)
		{
			if(cn==root)
			{
				root=NULL;
				return;
			}
			else
			{
				if(cn->w<parent->w)
				parent->l=NULL;
				else
				parent->r=NULL;
			}
			delete cn;
		}
		//l	
		if(cn->l!=NULL && cn->r==NULL)
		{
			if(cn==root)
			{
				root=cn->l;
				return;
			}
			else
			{
				if(cn->l->w<parent->w)
				parent->l=cn->l;
				else
				parent->r=cn->l;
			}
			delete cn;
		}		
		//r	
		if(cn->l==NULL && cn->r!=NULL)
		{
			if(cn==root)
			{
				root=cn->r;
				return;
			}
			else
			{
				if(cn->r->w<parent->w)
				parent->l=cn->r;
				else
				parent->r=cn->r;
			}
			delete cn;
		}		
		//2
		if(cn->l!=NULL && cn->r!=NULL)
		{
			node *temp=cn->l;
			while(temp->r)
			temp=temp->r;
			string val,mean;
			val=temp->w;
			mean=temp->m;
			delet(val);
			cn->w=val;
			cn->m=mean;
		}
			
}
};
int main()
{
	tree t;
	int ch;
	string ke;
	do
	{
	cout<<"1.create\n2.display\n3.search\n4.modify\n5.delete\nenter...\t";
	cin>>ch;
	switch(ch)
	{
		case 1:t.create();break;
		case 2:t.display();break;
		case 3:cout<<"enter string to search";
			cin>>ke;
			t.search(ke);
			break;
		case 4:t.modify();break;
		case 5:cout<<"enter string to delete";
			cin>>ke;
			t.delet(ke);
			break;
		default:cout<<"wrong input\n";break;
	}
	}
	while(ch<6);
}			
