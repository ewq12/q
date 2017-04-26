#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class node
{
	int data;
	node *left,*right;
	public: 
		node(int n)
		{
			data = n;
			left = right = NULL;
		}
		friend class tree;
};

class tree
{
	node *root;
	public:
		tree()
		{
			root =NULL;
		}
		void create();
		void preorder();
		void preorder(node *currentnode);
		void inorder();
		void inorder(node *currentnode);
		void postorder();
		void postorder(node *currentnode);
		void copy(tree &c);
		node* copy(node*,node*);
		int countnode();
		int countnode(node *root);
		int countleafnode();
		int countleafnode(node *root);
		
}c,c1;

void tree::create()
{
	node *temp,*newnode;
	char ans,choice,l,r;
	int c,f=1;
	
	do
	{
		cout<<"Enter the elements to be stored : ";
		cin>>c;
		newnode = new node(c); //call constructor of node class
		if(root == NULL)
		{
			root = newnode;
		}
		else
		{
			temp =root;
			while(1)
			{
				cout<<"Left of right(l/r) :";
				cin>>ans;
				if(ans == l)
				{
					if(temp ->left == NULL)
					{
						temp-> left = newnode;
						break;
					}
					else
					{
						temp = temp->left;						
					}
				}
				else
				{
					if(temp ->right == NULL)
					{
						temp -> right = newnode;
						break;
					}
					else
					{
						temp = temp-> right;
					}
				} 
			}
		}
		cout<<"Any more element you want to enter (1/0): ";
    	cin>>f;	
		}while(f == 1);
}
void tree::preorder()
{
	preorder(root);
}
void tree::preorder(node *currentnode)
{
	
	
	if(currentnode != NULL)
	{
		cout<<currentnode -> data ;   
		preorder(currentnode -> left);
		preorder(currentnode -> right);
	}
}
void tree::inorder()
{
	inorder(root);
}
void tree::inorder(node *currentnode)
{
	if(currentnode != NULL)
	{
		cout<<currentnode -> data ;   
		preorder(currentnode -> left);
		preorder(currentnode -> right);
	}
}
void tree::postorder()
{
	postorder(root);
}
void tree::postorder(node *currentnode)
{
	if(currentnode != NULL)
	{
		cout<<currentnode -> data ;   
		preorder(currentnode -> left);
		preorder(currentnode -> right);
	}
}
/*void tree::copy(tree &c)
{
	
	copy(root,c.root);
}
node *tree::copy(node *root1,node *root2)
{
	if(root1 != NULL)
	{
		root2 =new node(root1 -> data);
		root2 -> left = copy(root1 -> left);
		root2 -> right = copy(root1 -> right);
		return root2;
	}
	else
		return NULL;
}*/
int tree::countnode()
{
	return countnode(root);
}
int tree::countnode(node *root)
{
	static int count = 0; 
	if(root !=NULL)
	{
		count++;
		countnode(root -> left);
		countnode(root -> right);
	}
	cout<<"Total nodes  : "<<count<<endl;
	return count;
}
int tree::countleafnode()
{
	return countleafnode(root);
}
int tree::countleafnode(node *root)
{
	static int countleaf = 0; 
	if(root =NULL)
	{
		return NULL;
	}
	if(root -> left && root -> right != NULL)
	{
		return ++countleaf;
		countleafnode(root -> left);
		countleafnode(root -> right);
	}
	cout<<"Total nodes  : "<<countleaf<<endl;
}
main()
{
	while(1)
	{
		cout<<"1. Create Tree."<<endl;
		cout<<"2. Display Tree in Preorder form."<<endl;
		cout<<"3. Display Tree in Inorder form."<<endl;
		cout<<"4. Display Tree in Postorder form."<<endl;	
		cout<<"5. Create A Copy of tree."<<endl;
		cout<<"6. Create A Mirrior of tree."<<endl;
		cout<<"7. Count Total Number of Nodes."<<endl;
		cout<<"8. Count Total Number of LeafNodes."<<endl;
		cout<<"9. Exit."<<endl;
		cout<<"Enter your choice :"<<endl;
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1: c.create();
					break;
			case 2: c.preorder();
					break;
			case 3:	c.inorder();
					break;
			case 4:	c.postorder();
					break;
			/*case 5: c1.create();
					c.copy(tree &c1);
					break;
			case 6: mirror(tree &c);
					break;*/
			case 7: c.countnode();
					break;
			case 8: c.countleafnode();		
					break;
			case 9: exit(0);					
		}
	}
}

