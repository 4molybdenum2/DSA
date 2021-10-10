//Your Code

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int length(Node *head)
{
   int c=0;
    Node *temp=head;
    while(temp != NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
    
    //Write your code here
}

Node *appendLastNToFirst(Node *head, int n)
{ if(head==NULL || n==0)
{
    return head;
}
    Node *p=head;
  Node *q=NULL;
    int l=length(head);
    int i=1;
    while(i<=l-n)
    { q=p;
        p=p->next;
    i++;
    } 
 q->next=NULL;
  Node *head2=head;
 head=p;

 while(p->next!=NULL)
 {
     p=p->next;
     
 } p->next = head2;
 return head;
 //Write your code here
}


//main code

#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}