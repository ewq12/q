#include<iostream>
#include "stack_linklist.h"
using namespace std;
class tree
{
	node *root;
	public:
		tree()
		{
			root=NULL;
		}
		void create();
		void insert();
		void rec_preorder();
		void rec_preorder(node *);
		void rec_inorder();
		void rec_inorder(node *);
		void rec_postorder();
		void rec_postorder(node *);
		void preorder();
		void inorder();
		void postorder();
		void copy(tree &);
		node *copy(node *);
	    void mirror(tree &);
	    node *mirror(node *);
	    int countnode();
	    int countnode(node *);
	    int countleafnode();
	    int countleafnode(node *);
};
void tree::create()
{
	char ch,ans;
	int num;
	node *temp=root;
	do
	{
	 cout<<"\nEnter data: ";
	 cin>>num;
	 node *newnode=new node(num);
	 if(root==NULL)
	 {
		root=newnode;
	 }
	 else
	 {
		temp=root;
		while(1)
		{
			cout<<"\nLeft or Right? (l/r) of "<<temp->data<<" ";
			cin>>ans;
			if(ans=='l')
			{
				if(temp->left==NULL)
				{
				  temp->left=newnode;
				  break;	
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(ans=='r')
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
	 }
	 cout<<"\nAny more nodes? ";
	 cin>>ch;
    }while(ch=='y'||ch=='Y');
}
void tree::insert()
{
	 char ans;
	 int num;
	 node *temp=root;
     cout<<"\nEnter data: ";
	 cin>>num;
	 node *newnode=new node(num);
	 if(root==NULL)
	 {
		root=newnode;
	 }
	 else
	 {
		temp=root;
		while(1)
		{
			cout<<"\nLeft or Right? (l/r) of "<<temp->data<<" ";
			cin>>ans;
			if(ans=='l')
			{
				if(temp->left==NULL)
				{
				  temp->left=newnode;
				  break;	
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(ans=='r')
			{
				if(temp->right==NULL)
				{
					temp->right=newnode;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
		}
	 }	
}
void tree::rec_preorder()
{
	rec_preorder(root);
}
void tree::rec_preorder(node *currnode)
{
	if(currnode!=NULL)
	{
		cout<<currnode->data<<" ";   //V
		rec_preorder(currnode->left);    //L
		rec_preorder(currnode->right);   //R
	}
}
void tree::rec_inorder()
{
	rec_inorder(root);
}
void tree::rec_inorder(node *currnode)
{
	if(currnode!=NULL)
	{
		rec_inorder(currnode->left);    //L
		cout<<currnode->data<<" ";   //V
		rec_inorder(currnode->right);   //R
	}
}
void tree::rec_postorder()
{
	rec_postorder(root);
}
void tree::rec_postorder(node *currnode)
{
	if(currnode!=NULL)
	{
		rec_postorder(currnode->left);    //L
		rec_postorder(currnode->right);   //R
		cout<<currnode->data<<" ";   //V
	}
}
void tree::preorder()
{
	stack s;
	node *temp=root;
	if(!temp)
	{
		return;
	}
	s.push(temp);
	while(!s.isempty())
	{
	  temp=s.pop();
	  cout<<temp->data<<" ";
	  if(temp->right)
	  {
		s.push(temp->right);
	  }
	  if(temp->left)
	  {
		s.push(temp->left);
	  }	
	}
}
void tree::inorder()
{
	stack s;
	node *temp=root;
	while(temp||!s.isempty())
	{
	  if(temp)
	  {
	  	s.push(temp);
		temp=temp->left;
	  }
	  else
	  {
	  	if(!s.isempty())
	  	{
	  		temp=s.pop();
	  		cout<<temp->data<<" ";
	  		temp=temp->right;
		}
	  }
	}
}
void tree::postorder()
{
	stack s;
	node *temp=NULL;
	s.push(root);
	node *prev=NULL;
	while(temp||!s.isempty())
	{
		if(s.isempty())
		 return;
		temp=s.peek();
		if(!prev||prev->right==temp||prev->left==temp)
		{
			if(temp->left)
			 s.push(temp->left);
			else if(temp->right)
			 s.push(temp->right);
			else
			{
				cout<<temp->data<<" ";
				temp=s.pop();
			}
		}
		else if(temp->left==prev)
		{
		   if(temp->right)
		    s.push(temp->right);
		   else 
		   {
		     	cout<<temp->data<<" ";
		     	temp=s.pop();
		   }
		}
		else if(temp->right==prev)
		{
			cout<<temp->data<<" ";
			temp=s.pop();
		
		}
		prev=temp;
	}
}
void tree::copy(tree &t)
{
	t.root=copy(root);
}
node *tree::copy(node *root1)
{
	node *root2;
	if(root1!=NULL)
	{
		root2=new node(root1->data);
		root2->left=copy(root1->left);
		root2->right=copy(root1->right);
		return root2;
	}
	else
	  return NULL;
}
void tree::mirror(tree &t)
{
	t.root=mirror(root);
}
node *tree::mirror(node *root1)
{
	node *root2;
	if(root1!=NULL)
	{
		root2=new node(root1->data);
		root2->left=mirror(root1->right);
		root2->right=mirror(root1->left);
		return root2;
	}
	else
	  return NULL;
}
int tree::countnode()
{
   return countnode(root);	
}
int tree::countnode(node *root)
{
	static int count=0;
	if(root!=NULL)
	{
		count++;
		countnode(root->left);
		countnode(root->right);
	}
	return count;
}
int tree::countleafnode()
{
	return countleafnode(root);
}
int tree::countleafnode(node *root)
{
	static int count=0;
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
		 count++;
		countleafnode(root->left);
		countleafnode(root->right);
	}
	return count;
}
main()
{
	tree t,t1;
	int k,n,n1;
	//cout<<"\t\t\tBINARY TREE";
	while(1)
	{
		cout<<"\n\nEnter your choice:\n1. Create tree\n2. Insert element\n3. Recursive Preorder traversal\n4. Recursive Inorder traversal\n5. Recursive Postorder traversal";
        cout<<"\n6. Non-recursive Preorder traversal\n7. Non-recursive Inorder traversal\n8. Non-recursive Postorder traversal\n9. Copy tree\n10. Mirror tree";
		cout<<"\n11. Count total nodes\n12. Count leaf nodes\n13. Exit\n";
		cin>>k;
		switch(k)
		{
		  case 1:t1.create();
		         break;
		  case 2:t1.insert();
		         break;
		  case 3:cout<<"Recursive Preorder traversal : ";
		         t1.rec_preorder();
		         break;
		  case 4:cout<<"Recursive Inorder traversal : ";
		         t1.rec_inorder();
		         break;
		  case 5:cout<<"Recursive Postorder traversal : ";
				 t1.rec_postorder();
		         break;
		  case 6:cout<<"Non-recursive Preorder traversal : ";
		         t1.preorder();	
				 break;
		  case 7:cout<<"Non-recursive Inorder traversal : ";
		         t1.inorder();
				 break;
		  case 8:cout<<"Non-recursive Postorder traversal : ";
		         t1.postorder();
				 break;
		  case 9:cout<<"Copied tree is (inorder traversal) : ";
		         t1.copy(t);
		         t.inorder();
		         break;
		  case 10:cout<<"Mirror tree is (inorder traversal) : ";
		          t1.mirror(t);
		          t.inorder();
				  break;
		  case 11:cout<<"Total number of nodes = ";
		          n=t1.countnode();
                  cout<<n<<endl;
				  break;
		  case 12:cout<<"Total number of leaf nodes = ";
		          n1=t1.countleafnode();
                  cout<<n1<<endl;	
                  break;
          case 13:exit(0);
		}		
	}
}
