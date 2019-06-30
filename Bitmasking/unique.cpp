#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	int ct[16]={0};
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	for(int i=0;i<n;i++)
	{
	    int c = 0;
	    while(arr[i]>0)
	    {
	        if(arr[i]&1)
	        {
	            ct[c]++;
	        }
	        c++;
	        arr[i]=arr[i]>>1;
	    }
	}
    int p =1,ans= 0;
	for(int i=0;i<16;i++)
	{
	    ct[i] = ct[i]%2;
	    ans+=ct[i]*p;
	    p = p<<1;      //p = p*2
	    //cout<<ct[i]<<" "<<endl;
	}
    cout<<ans;
	return 0;
}
