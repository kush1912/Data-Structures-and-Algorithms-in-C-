#include <iostream>
using namespace std;


int dec(int ct[])
{
    int p =1,ans= 0;
	for(int i=0;i<32;i++)
	{
	    ans+=ct[i]*p;
	    p = p<<1;      //p = p*2
	}
    return ans;
}

int axorb(int a,int b)
{
    int arr[32]={0};
    int i = 0 ;
    while(a>0||b>0)
    {
        //cout<<a<<b<<" "<<endl;
        
        if((a&1) && (!(b&1)) || ( !(a&1) && (b&1)))
        {
            arr[i] = 1;
        }
        //cout<<arr[i]<<" "<<endl;
        i++;
        a = a>>1;
        b = b>>1;
    }
    return dec(arr);
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<< axorb(a,b);
	
	return 0;
}
