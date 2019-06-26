#include <iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
    stack <int>s;
    int n,temp;
    cin>>n;
    pair<int,int> grt[2*n]; 
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        grt[i].first=temp;
        grt[i].second=-1;
        grt[n+i].first=temp;
        grt[n+i].second=-1;
    }
    int i=2*n-1,flag=0;
    while(i>=0)
    {
        if(s.empty())
        {
            s.push(grt[i].first);
            i--;
            continue;
        }
        if(grt[i].first < s.top())
        {

            grt[i].second = s.top();
            s.push(grt[i].first);
        }
        while(grt[i].first >= s.top())   // Equal to is added here for duplicate numbers 7 8 1 1 4 --> 8 -1 4 4 7
        {
            s.pop();
            if(s.empty())
            {
                flag=1;
                break;
            }
            if(grt[i].first<s.top())
            {

             grt[i].second = s.top();
             s.push(grt[i].first); 
             break;
            }
        }
        if(flag==1)
        {
            flag=0;
            continue;
        }
        i--;
    }
    
    
    for(int k=0;k<n;k++)
    {
        cout<<grt[k].second<<" ";
    }
    
    return 0;
}
