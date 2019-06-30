#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int countbits(int a)
{ 
     int count =0;    
     while(a>0)
	        {
	            //cout<<a<<" ";
	            if(a&1)
	            {
	                count++;
	            }
	            a=a>>1;
	        }
	        return count;
}

int main() {
	int n;
	cin>>n;
	while(n)
	{
	    int a,b,count=0;
	    cin>>a>>b;
	    while(a<=b)
	    {
	       count+=countbits(a);  
	        a++;
	    }
	    cout<<count<<endl;
	    n--;
	}
	return 0;
}
