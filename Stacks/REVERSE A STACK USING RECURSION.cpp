#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void bottom(stack<int>&s, int tp)
{
    if(s.empty())
    {
        s.push(tp);
        return;
    }

    int y = s.top();
    s.pop();
    bottom(s,tp);
    s.push(y);
}

void reversestack(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
   
    int tp = s.top();
    s.pop();
    reversestack(s);
    bottom(s,tp);
}



int main() {
	stack <int>s;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>temp;
	    s.push(temp);
	}
	reversestack(s);
	while(!s.empty())
	{
	    cout<<s.top()<<endl;
	    s.pop();
	}
	return 0;
}
