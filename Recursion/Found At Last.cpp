#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int k, int n)
{
    if(n<0)
    return -1;
    if(arr[n]==k)
    {
        return n;
    }
    search(arr,k,n-1);
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	
	int k;
	cin>>k;
	int index = search(arr,k,n);
	cout<<index;
	return 0;
}
