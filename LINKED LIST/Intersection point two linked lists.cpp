/*
Sample Input
5
10 20 30 40 50
4
15 25 40 50
Sample Output
40
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


int check(node* h1,node*h2,int l1,int l2)
{
    int result = -1;
    if(l1>l2)
    {
        for(int i=0;i<l1-l2;i++)
        {
            h1=h1->next;
        }
    }
    else
    {
        for(int i=0;i<l2-l1;i++)
        {
            h2=h2->next;
        }
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data==h2->data)
        return h1->data;
        h1=h1->next;
        h2=h2->next;
    }
    return result;
}

int main() {
	int n,m,data;
	node *h1=NULL;
	node *h2=NULL;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>data;
	    h1=inserttail(h1,data);
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
	    cin>>data;
	    h2=inserttail(h2,data);
	}
	//print(h1);
	//print(h2);
	int result = check(h1,h2,n,m);
    cout<<result;
    return 0;
}
