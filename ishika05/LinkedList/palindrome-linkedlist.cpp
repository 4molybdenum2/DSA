// YOUR CODE

int length(Node *head) {
    // Write your code here
    
    if(head==NULL)
        return 0;
    int ans=length(head->next);
    return ans+1;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head==NULL || head->next==NULL)
        return head;
    
    Node* smallAns=reverseLinkedListRec(head->next);
    Node* temp= smallAns;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    
        
    temp->next=head;
    head->next=NULL;
    return smallAns;
}


bool isPalindrome(Node *head)
{
    //Write your code here
    int mid= length(head)/2;
    if(mid==0)
        return true;
    int i=1;
    Node*temp=head;
    while(i<mid){
        temp=temp->next;
        i++;
    }
    Node* tempHead=reverseLinkedListRec(temp->next);
    temp->next=NULL;
    
    while(head!=NULL && tempHead!=NULL){
        if(head->data != tempHead->data)
            return false;
        head=head->next;
        tempHead=tempHead->next;
        
    }
    return true;
}

//MAIN CODE

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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}