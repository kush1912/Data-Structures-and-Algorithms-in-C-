/// Palindrome check

/*
Sample Input
5
1 2 3 6 8
Sample Output
False
*/


#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

bool palindrome(list<int> l)
{
    while(!l.empty())
    {
        //cout<<l.front()<<" "<<l.back()<<endl;
        if(l.front()!=l.back())
        {
            return false;
        }
        else
        {
            l.pop_back();
            l.pop_front();
        }
    }
    return true;
}
int main()
{
    list <int> l;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        l.push_back(data);
    }
    if(palindrome(l))
        cout<<"True";
    else
        cout<<"False";
    return 0;
}
