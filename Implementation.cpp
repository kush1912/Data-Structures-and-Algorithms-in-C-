#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;

class graph{
int V;
list<int> *l;
public:
    graph(int v)
    {
        V = v;
        ///Array of Linked Lists
        l = new list<int> [V];
    }

    void addedge(int u,int v,bool bidir = true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }

    void printadjlist()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            /// don't use int vertex here it goes into an infinite loop.
            for(vertex: l[i])
                cout<<vertex<<", ";

            /*
            list<int> :: iterator it;
            for(it = l[i].begin(); it!=l[i].end();it++)
            {
                cout<<*it<<", ";
            }
            */
            cout<<endl;
        }
    }
};


int main()
{
    graph g(5);s
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.printadjlist();
    return 0;
}
