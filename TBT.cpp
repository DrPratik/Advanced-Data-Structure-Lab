#include<iostream>
using namespace std;
struct node
{
	int data,lch,rch;
	node *l,*r,*p;
};
node *root,*dummy;
class tbt
{
	public:
	tbt()
	{
		root=NULL;
		dummy=new node;
		dummy->lch=dummy->rch=0;
		dummy->l=dummy->r=NULL;
	}
	void create()
	{
		node *nn;
		cout<<"enter data";
		nn=new node;
		cin>>nn->data;
		nn->lch=nn->rch=0;
		nn->l=nn->r=NULL;
		if(root==NULL)
		{
			root=nn;
			root->l=root->r=dummy;
			dummy->l=nn;
			return;
		}
		else
		{
			node *cn,*parent;
			cn=root;
			while(cn!=NULL)
			{
				parent=cn;
				if(nn->data<cn->data)
				{
					if(cn->lch==1)
					cn=cn->l;
					else
					cn=NULL;
				}
				else
				{
					if(cn->rch==1)
					cn=cn->r;
					else
					cn=NULL;
				}
			}
			nn->p=parent;
			if(nn->data < parent->data)
			{
				nn->l=parent->l;
				nn->r=parent;
				parent->l=nn;
				parent->lch=1;
			}
			else
			{
				nn->r=parent->r;
				nn->l=parent;
				parent->r=nn;
				parent->rch=1;
			}
			return;
		}
	}
	void inorder()
	{
		node *cn=root;
		while(1)
		{
			while(cn->lch==1)
			{
				cn=cn->l;
			}
			cout<<cn->data;
			while(cn->rch==0)
			{
				if(cn->r==dummy)
				return;
				else
				{
					cn=cn->r;
					cout<<cn->data;
				}
			}
			cn=cn->r;
		}
	}
	node *post_succ(node *t)
	{
		node *t1,*prev;
		if(t->p->r==t)
		return t->p;
		else
		{
			prev=t->p;
			if(prev->rch==0)
			return prev;
			else
			{
				t=prev->r;
				while(t!=NULL)
				{
					t1=t;
					if(t->lch==1)
					t=t->l;
					else
					{
						if(t->rch==1)
						t=t->r;
						else
						t=NULL;
					}
				}
				return t1;
			}
		}
	}
	void postorder()
	{
		node *cn,*parent;
		cn=root;
		while(cn!=NULL)
		{
			parent=cn;
			if(cn->lch==1)
			cn=cn->l;
			else
			{
				if(cn->rch==1)
				cn=cn->r;
				else
				cn=NULL;
			}
		}
		cout<<parent->data<<" ";
		cn=parent;
		while(cn!=root)
		{
			cn=post_succ(cn);
			cout<<cn->data<<" ";
		}
	}
	void preorder()
	{
		node *cn;
		cn=root;
		while(1)
		{
			while(cn->lch==1)
			{cout<<cn->data<<" ";
			 cn=cn->l;
			}
			cout<<cn->data<<" ";
			while(cn->rch==0)
			{
				if(cn->r==dummy)
				return;
				else
				cn=cn->r;
			}
			cn=cn->r;
		}
	}	
};
int main()
{
	int ch;
	tbt t;
	do
	{
	cout<<"1.enter\n2.inorder\n3.Postorder\n4.Preorderenter..\t";
	cin>>ch;
	switch(ch)
	{
		case 1: t.create();break;
		case 2:t.inorder();break;
		case 3:t.postorder();break;
		case 4:t.preorder();break;
		default:break;
	}
	}
	while(ch<5);
}
