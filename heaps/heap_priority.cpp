/// Implementation using priority Queue

#include<iostream>
#include<bits/stdc++.h>
#include<queue>

#include<vector>


using namespace std;

/// BY default priority Queue creates a max heap.


int main()
{
    //priority_queue<int> pq;

    /// Min heap
    priority_queue<int,vector<int>,greater<int> > pq;
   /// greater is the inbuilt comparator which replaces the smallest element to the top.
    int a[10] = {5,6,17,18,9,11};

    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}
