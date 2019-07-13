/*
Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
*/

#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

//Insert at head
void inserthead(node* &head,int d)
{
    node *n = new node(d);
    n->next = head;
    head = n;
}

//Insert at tail
node* inserttail(node* &head,int d)
{
    if(head==NULL)
    {
        inserthead(head,d);
        return head;
    }
    node*n = new node(d);
    n->next = NULL;
    node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = n;
    return head;
}

node* kappend(node*&head,int n)
{
    node* runner = head;
    node* temp = head;
    for(int i=0;i<n;i++)
    {
        runner = runner->next;
    }
    while(runner->next!=NULL)
    {
        temp= temp->next;
        runner = runner->next;
    }
    runner->next = head;
    head = temp->next;
    temp->next=NULL;
    return head;
}

void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

int main() {
	int n,t,data;
	cin>>n;
	node *h1=NULL;
	for(int i=0;i<n;i++)
    {
        cin>>data;
    	h1 = inserttail(h1,data);
    }
    
    cin>>t;
    h1= kappend(h1,t);
    print(h1);
    
	return 0;
}
