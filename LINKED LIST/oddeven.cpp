/*Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2
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

//delete node if not the last element
void del(node*& n)
{
    //cout<<n->data <<"  "<<n->next->data;
    n->data = n->next->data;
    node* l = n->next;
    n->next = l->next;
    delete l;
}
node* evenodd(node*&head)
{
    node*h1_e = NULL;
    node*temp=head;
    node*prev =NULL;
    while(temp->next!=NULL)
    {
        //cout<<temp->data<<"---> "<<endl;
        if(temp->data%2==0)
        {
            h1_e = inserttail(h1_e,temp->data);
            del(temp);
            continue;
            //cout<<h1_e->data<<"-> "<<endl;
        }
        prev = temp;
        temp = temp->next;
    }
    
    if(temp->data%2==0)
    {
        h1_e=inserttail(h1_e,temp->data);
        prev->next=h1_e;
    }
    else
    {
        temp->next =h1_e;
    }
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
	int n,data;
	cin>>n;
	node *h1=NULL;
	for(int i=0;i<n;i++)
    {
        cin>>data;
    	h1 = inserttail(h1,data);
    }
    //print(h1);
    h1= evenodd(h1);
    print(h1);
    
	return 0;
}
