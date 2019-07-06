#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int s,int e)
{
    int mid = (s+e)/2;
    int i=s,j=mid+1,k=s;
    //cout<<"s--mid--e-->"<<s<<mid<<e<<endl;
    int temp[100];
    while(i<=mid && j<=e )
    {
        //cout<<arr[i]<<" - "<<arr[j]<<endl;
        if(arr[i]<arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        cout<<arr[i]<<" * "<<endl;
        temp[k++] = arr[i++];
    }
    while(j<=e)
    {
        //cout<<arr[j]<<" & "<<endl;
        temp[k++] = arr[j++];
    }
    for( int i=0;i<=e;i++)
    {
        arr[i] = temp[i];
    }
}

void mergesort(int arr[], int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int mid = (s+e)/2;
    
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(int i = 0;i<n;i++)
	{
	    cout<<arr[i];
	}
	return 0;
}
