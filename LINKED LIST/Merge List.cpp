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

void print(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

node* merge_list(node*h1,node*h2)
{
    node *h3 =NULL;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data >h2->data)
        {
            h3 = inserttail(h3,h2->data);
            h2 = h2->next;
        }
        else if(h1->data = h2->data)
        {
            h3 = inserttail(h3,h1->data);
            h1 = h1->next;
            h3 = inserttail(h3,h2->data);
            h2 = h2->next;
        }
        else
        {
            h3 = inserttail(h3,h1->data);
            h1 = h1->next;
        }
    }
    if(h1==NULL)
    {
        node* temp=h3;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=h2;
    }
    else
    {
        node* temp=h3;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next=h1;
    }
    return h3;
}

int main() {
	int t,data;
	cin>>t;
	
	while(t)
	{
    	int n,n1;
    	cin>>n;
    	node *h1=NULL,*h2=NULL;
    	for(int i=0;i<n;i++)
    	{
    	    cin>>data;
    	    h1 = inserttail(h1,data);
    	}
    	cin>>n1;
    	for(int i=0;i<n1;i++)
    	{
    	    cin>>data;
    	    h2 = inserttail(h2,data);
    	}
    	node* h3 = merge_list(h1,h2);
    	//print(h1);
    	//print(h2);
    	print(h3);
    	t--;
	}
	

	return 0;
}
