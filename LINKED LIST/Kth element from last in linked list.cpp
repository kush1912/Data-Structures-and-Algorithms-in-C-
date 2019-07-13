Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4

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

int klastelement(node*head,int n)
{
    node*temp =head;
    node*run=head;
    for(int i=1;i<n;i++)
    {
        temp=temp->next;
    }
    while(temp->next!=NULL)
    {
        run=run->next;
        temp=temp->next;
    }
    return run->data;
}

int main() {
	int n,data;
	node *h1=NULL;
	cin>>data;
	while(data!=-1)
	{
	    h1= inserttail(h1,data);
	    cin>>data;
	}
    cin>>n;
    int k=klastelement(h1,n);
	cout<<k;
	return 0;
}
