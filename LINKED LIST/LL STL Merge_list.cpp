///Merge list using STL

#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;

//function for printing the elements in a list
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout <<*it<<" ";
    cout << '\n';
}

list<int> merge_list(list<int> l1,list<int> l2)
{
    list<int> l3;
    list<int> :: iterator i1,i2;
    i1 = l1.begin();
    //it!=l1.end;it++
    i2 = l2.begin();
    while(i1 != l1.end() && i2 != l2.end())
    {
        if(*i1>*i2)
        {
            l3.push_back(*i2);
            i2++;
        }
        else if(*i1 == *i2)
        {
            l3.push_back(*i1);
            i1++;
            l3.push_back(*i2);
            i2++;
        }
        else
        {
            l3.push_back(*i1);
            i1++;
        }
    }

    while(i1 != l1.end())
    {
        l3.push_back(*i1);
        i1++;
    }
    while(i2 != l2.end())
    {
        l3.push_back(*i2);
        i2++;
    }
    return l3;
}

int main()
{
    list<int> l1,l2,l3;

    int t,data;
    cin>>t;

    while(t)
    {
        int n1,n2;
        cin>>n1;
        //cout<<"n1:  "<<n1<<endl;
        for(int i=0;i<n1;i++)
        {
            cin>>data;
            l1.push_back(data);
        }
        cin>>n2;
        //cout<<"n2:  "<<n2<<endl;
        for(int i=0;i<n2;i++)
        {
            cin>>data;
            l2.push_back(data);
        }
        l3 = merge_list(l1,l2);
        showlist(l3);
        l3.erase(l3.begin(),l3.end());
        l2.erase(l2.begin(),l2.end());
        l1.erase(l1.begin(),l1.end());
        t--;
    }
    return 0;
}
