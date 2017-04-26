#include<iostream>
using namespace std;
class node
{
 int data;
 node *prev;
 node *next;
 public:
        node()
		{
		 data=-1;
		 prev=next=NULL;
		}
		node(int x)
		{
		 data=x;
		 prev=next=NULL;
		}
		friend class Doubly;
};
class Doubly
{
 node *first;
 public:
 	    Doubly()
 	    {
 	      first=NULL;	
		}
        void create();
		void insertbeg();
		void insertend();
		void insertpos();
		void delbeg();
		void delend();
		void delpos();
		void delele();
		int search(int);
		void reverse();
		void concat(Doubly &);
		void display();
		int length();
		int delval();
};
void Doubly::create()
{
 node *temp=first;
 int num,n,i;
 cout<<"Enter no. of nodes: ";
 cin>>n;
 for(i=0;i<n;i++)
 {
 	cout<<"Enter data: ";
 	cin>>num;
 	node *newnode=new node(num);
 	if(first==NULL)
 	{
 	  first=temp=newnode;	
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
		temp=temp->next;
	}
  }
}
void Doubly::display()
{
   node *temp=first;
   while(temp!=NULL)
   {
   	 cout<<temp->data<<"->"; 
   	 temp=temp->next;
   }	
   cout<<"NULL";
}
void Doubly::delbeg()
{
	node *temp=first;
	if(first==NULL)
	{
		cout<<"List is empty";
		return;
	}
	first=first->next;
	first->prev=NULL;
	delete temp;
}
void Doubly::insertbeg()
{
   node *temp=first;
   int num;
   cout<<"Enter data to be inserted at beginning: ";
   cin>>num;
   node *newnode=new node(num);
   newnode->next=first;
   first->prev=newnode;
   first=newnode;	
}
void Doubly::insertend()
{
	node *temp=first;
	int num;
    cout<<"Enter data to be inserted at end: ";
    cin>>num;
    node *newnode=new node(num);
    if(first==NULL)
	{
		first=temp=newnode;
	}
    while(temp->next!=NULL)
    {
    	temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void Doubly::insertpos()
{
	node *temp=first;
	int num,pos,i;
    cout<<"Enter data to be inserted: ";
    cin>>num;
    cout<<"Enter position: ";
    cin>>pos;
    node *newnode=new node(num);
    if(first==NULL)
	{
		first=temp=newnode;
	}
	else
	{
		for(i=1;i<pos-1;i++)
        {
            temp=temp->next;	
	    }
	    newnode->next=temp->next;
	    temp->next->prev=newnode;
     	temp->next=newnode;
    	newnode->prev=temp;
	}
}
void Doubly::delend()
{
	node *temp=first,*temp1;
	if(first==NULL)
	{
		cout<<"List is empty";
		return;
	}
    while(temp->next!=NULL)
    {
    	temp=temp->next;
	}
	temp1=temp->prev;
	temp1->next=NULL;
	delete temp;
}
int Doubly::length()
{
	node *temp;
	int count=0;
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		count++;
	}
	return count;
}
void Doubly::delpos()
{
	node *temp=first,*temp1,*temp2;
	int pos,i;
	label:
    cout<<"Enter the position of element to be deleted: ";
    cin>>pos;
    if(first==NULL)
    {
    	cout<<"No element in list";
    	return;
	}
	if(pos==1)
	{
		delbeg();
	}
	else 
	{
	  for(i=0;i<pos-1||temp->next!=NULL;i++)
      {
    	temp=temp->next;
	  }	
	  if(temp->next==NULL)
	  {
	  	delend();
	  }
	  else if(temp->next!=NULL)
	  {
	  temp->prev->next=temp->next;
	  temp->next->prev=temp->prev;
	  delete temp;
      }
      else
      {
      	cout<<"Enter valid position";
      	goto label;
	  }
    }
}
int Doubly::search(int val)
{
	int count=-1,flag=-1;
	node *temp=first;
	while(temp!=NULL)
	{
	  count++;
	  if(temp->data==val)
	  {
	  	flag=1;
	  	break;
	  }	
	  temp=temp->next;
	}
	if(flag!=-1)
	 return count;
	else
	 return -1;
}
int Doubly::delval()
{
	int val,ch;
	cout<<"Enter element to be deleted: ";
	cin>>val;
	node *temp=first,*back=NULL,*temp1=NULL;
    ch=search(val);
	if(ch!=-1)
	{
	  if(ch==0)
	  {
	  	delbeg();
	  }
	  else
	  {
	    for(int i=0;i<ch;i++)
	    {
	  	 temp=temp->next;
	    }	
	    temp->prev->next=temp->next;
	    temp->next->prev=temp->prev;
	    delete temp1;
	  }
	}
	else
	{
		return -1;
	}
}
void Doubly::reverse()
{
   node *curr=first,*temp1;	
   while(curr!=NULL)
   {
   	temp1=curr->prev;
   	curr->prev=curr->next;
   	curr->next=temp1;
   	curr=curr->prev;
   }
   first=temp1->prev;
}
void Doubly::concat(Doubly &db1)
{
	node *temp=first,*temp1=db1.first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp1!=NULL)
	{
	   node *newnode=new node(temp1->data);	
	   if(temp==NULL)
	   {
	   	first=temp=newnode;
	   }	
	   else
	   {
         temp->next=newnode;
         newnode->prev=temp;
         temp=temp->next;
       }
       temp1=temp1->next;
	}
}
main()
{
	Doubly db,db1;
	int k,c,flag,val,f1;
	while(1)
	{
	 cout<<"\nEnter your choice:\n1. Create\n2. Display\n3. Insert at beginning\n4. Insert at end\n5. Insert at position";
	 cout<<"\n6. Calculate length\n7. Delete from beginning\n8. Delete from end\n9. Delete from position";
	 cout<<"\n10. Delete by value\n11. Search an element\n12. Reverse\n13. Concatenate\n14.Exit\n";
	 cin>>k;
	 switch(k)
	 {
		case 1:db.create();
		       break;
		case 2:db.display();
		       break;
		case 3:db.insertbeg();
		       db.display();
		       break;
		case 4:db.insertend();
		       db.display();
		       break;
		case 5:db.insertpos();
		       db.display();
		       break;
		case 6:c=db.length();
               cout<<"\nLength is :"<<c;
			   break; 
	    case 7:db.delbeg();
		       db.display(); 
			   break;
	    case 8:db.delend();
		       db.display(); 
			   break;
		case 9:db.delpos();
		       db.display(); 
			   break;
		case 10:f1=db.delval();
		        if(f1!=-1)
		        {
		        	db.display();
		        } 
		        else
				{
					cout<<"Element not found";
				}  
			    break;
		case 11:cout<<"Enter element to be searched: ";
	            cin>>val;
		        flag=db.search(val);
		        if(flag!=-1)
	            {
		          cout<<"Element found at "<<flag+1;
	            }
	            else if(flag==-1)
	            {
		          cout<<"Element not found";
	            }
			    break;
		case 12:db.reverse();
		        db.display();
		        break;
		case 13:cout<<"Enter 2nd list\n";
		        db1.create();
		        db.concat(db1);
		        db.display();
				break;         
	    case 14:exit(0);		        
	 }
    }
}

		
