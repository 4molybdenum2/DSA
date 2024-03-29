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
 

Node *removeDuplicates(Node *head)
{
    if(head==NULL )
    {
        return head;
    }
    Node *t1=head;
    //Node *t2=head->next;
    while(t1 -> next  != NULL)
    {
        if(t1 -> data == t1 -> next -> data )
        {
            Node *n;
            n = t1 -> next -> next; //save this addres in n so tht when we delete t1->next adress of t1->next->next is not lost 
            delete(t1 -> next);
            t1 -> next = n ;
        }
        else{
        t1 = t1 -> next;
        }
    }
    
    return head;
/*
  while(t1->data==t2->data && t2->next!=NULL)
  {
      t2=t2->next;  
  }
    t1->next=t2;
    */
    //Write your code here
}

//Main Code

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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}


//AB KONSA QUESTION KARU?
TYPE BELOW