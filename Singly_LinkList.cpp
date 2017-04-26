#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
		node(int n)
		{
			data = n;
			next = NULL;
		}
	friend class list;
};

class list
{
	node *listptr;
	public :
		list()
		{
			listptr = NULL;
		}
	node *newnode;
	void create();
	void display();
	void insert_beg();
	void insert_end();
	void insert_pos();
	void delete_beg();
	void delete_end();
	void delete_pos();
	void reverse_list();
	void concat_list(list);
}c,c1;
void list::create()
{
	int i,num,dt;
	node *temp;	
	cout<<"\nEnter the  number of data you want to enter : ";
	cin>>num;
	for(i=0;i<num;i++)
	{
		cout<<"Enter the data value : ";
		cin>>dt;
		node *newnode = new node(dt);	
		if(listptr == NULL)
			listptr = temp = newnode;
		else
		{
			temp -> next = newnode;
			temp = temp -> next ;
		} 
	}
}
void list::insert_beg()
{
	int dt;
	cout<<"Enter the data value: ";
	cin>>dt;
	node *newnode = new node(dt);
	newnode -> next = listptr;
	listptr = newnode; 
}
void list::insert_end()
{
	int dt;
	node *temp=listptr;
	cout<<"Enter the data value: ";
	cin>>dt;
	node *newnode = new node(dt);
	while(temp->next !=NULL)
	{
		temp = temp -> next;
	}
		newnode -> next = NULL;
		temp -> next = newnode;
}
void list::insert_pos()
{
	int dt,pos;
	node *temp = listptr;
	cout<<"Enter the position where you want to store : ";
	cin>>pos;
	cout<<"Enter the data value :";
	cin>>dt;
	node *newnode =new node(dt);
	for(int i=1;i<pos-1;i++)
	{
		temp = temp -> next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void list::delete_beg()
{
	node *temp;
	temp = listptr;
	listptr = temp ->next ;
	delete (temp);
}
void list::delete_end()
{
	node *temp,*temp1;
	temp = listptr;
	while(temp->next !=NULL)
	{
		temp1 =temp;
		temp=temp->next;
	}
	temp1 -> next = NULL;
	delete temp;
}
void list::delete_pos()
{
	node *temp=listptr,*temp1;
	int dt,pos;
	cout<<"Enter the position of element you want to remove : ";
	cin>>dt;
	for(int i=1;i<pos-1;i++)
	{
		temp1 =temp;
		temp = temp ->next;
	}
	temp1 -> next = temp ->next;
	delete temp;
}
void list::reverse_list()
{
	node *forward, *curr ,*backward;
	forward = listptr;
	curr = NULL;	
	while(forward != NULL)
	{
		backward = curr;
		curr = forward ;
		forward = forward -> next;
		curr -> next = backward;
	}
	listptr = curr;
}
void list::concat_list(list c1)
{
	node *temp,*temp1;
	temp=listptr;
	temp1=c1.listptr;
	for(temp=listptr;temp!=NULL;temp=temp->next);
	while(temp1!=NULL)
	{
		temp->next=c1.listptr;
		c1.listptr=temp;
	}	
}
void list::display()
{
	node *temp = listptr;
	int i,count;
	count = 0;
	cout<<"\nData Displayed here :"<<endl;
	while(temp != NULL)
	{
		cout<<temp -> data<<" -> ";
		temp = temp -> next;
		count++;
	}
	cout<<" NULL ";
	cout<<"\nNO. of data present in the list are : "<<count<<endl;
}

main()
{
	while(1)
	{
		cout<<"1. Create Linklist."<<endl;
		cout<<"2. Display."<<endl;
		cout<<"3. Insert At Begining."<<endl;
		cout<<"4. Insert At End."<<endl;
		cout<<"5. Insert At Specific Position."<<endl;
		cout<<"6. Delete From Begining."<<endl;
		cout<<"7. Delete From End"<<endl;
		cout<<"8. Delete From Specific Position."<<endl;
		cout<<"9. Reverse List."<<endl;
		cout<<"10. Concate Two Linklist"<<endl;
		cout<<"11. Exit."<<endl;
		int opt;
		cin>>opt;
		switch(opt)
		{
			case 1: c.create();
					break;
			case 2: c.display();
					break;
			case 3:	c.insert_beg();
					c.display();
					break;	
			case 4: c.insert_end();
					c.display();
					break;
			case 5: c.insert_pos();
					c.display();	
					break;
			case 6: c.delete_beg();
					c.display();
					break;
			case 7: c.delete_end();
					c.display();
					break;
			case 8: c.delete_pos();
					c.display();
					break;
			case 9: c.reverse_list();
					c.display();
					break;
			case 10: c1.create();
					 c.concat_list(c1);
					 c.display();
					 break;
			case 11: exit(0);		  											
		}
	}
}

