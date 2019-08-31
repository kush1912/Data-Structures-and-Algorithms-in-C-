///Graphs 04 - Adjacency List Implementation for Generic Data

#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<queue>

using namespace std;

template<typename T>
class graph
{
    map<T,list<T> > adjlist;

public:
    ///Dynamic graph without defining number of nodes.
    graph()
    {

    }
    void addedge(T u,T v,bool bidir = true)
    {
        adjlist[u].push_back(v);
        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
        for( i:adjlist)
        {
            cout<<i.first<<"->";
            for(T entry:i.second)
            {
                cout<<entry<<", ";
            }
            cout<<endl;
        }
    }

    ///Breadth first Search.
    void bfs(T src)
    {
        queue<T> q;
        map<T, bool> Visited;

        q.push(src);
        Visited[src]=true;

        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            /// For the neighbours of the current node, find nodes which are not visited.
            for(neighbour: adjlist[node])
            {
                if(!Visited[neighbour])
                {
                    q.push(neighbour);
                    Visited[neighbour]=true;
                }
            }
        }
    }

/// Using BFS - Single Source Shortest Path
    void ssp(T src)
    {
        queue<T> q;
        map<T, int> dist;
        ///Another map to store the parents.
        map<T,T> parent;

        for(node:adjlist)
            dist[node.first] = INT_MAX;

        q.push(src);
        dist[src]=0;
        parent[src] = src;

        while(!q.empty())
        {
            T node = q.front();
            //cout<<node<<" ";
            q.pop();
            /// For the neighbours of the current node, find nodes which are not visited.
            for(neighbour: adjlist[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour] = node;
                }
            }
        }

        ///Print distances to all the nodes.
        for(auto i:adjlist)
        {
            T node = i.first;
            cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }

    }

    void dfshelper(T node, map<T, bool> &visited)
    {
        /// whenever come to a node mark it visited.
        visited[node] = true;
        cout<<node<<" ";

        /// Find neighbour which is not visited.
        for(T neighbour: adjlist[node])
        {
            if(!visited[neighbour])
                dfshelper(neighbour,visited);
        }
    }

    ///Recursive call for DFS
    void dfs(T src)
    {
        map<T,bool> visited;
        dfshelper(src,visited);
    }

    ///Conncted Components.
    void connected_components(T src)
    {
        map<T,bool> visited;
        int c = 1;
        dfshelper(src,visited);
        cout<<endl;
        for(auto i:adjlist)
        {
            T node = i.first;
            if(!visited[node])
            {
                dfshelper(node,visited);
                c++;
            }
        }
        cout<<endl<<"The current graph has "<<c<<" components.";
    }
/// Cycle Detection using BFS.
    bool iscyclicbfs(T src)
    {
        map<T,bool> visited;
        map<T,T> parent;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(T nbr:adjlist[node])
            {
                if(visited[nbr]!=true && parent[node]!=nbr)
                {
                    return true;
                }
                /// if and else if working without else part.
                else if(!visited[nbr])
                {
                    visited[nbr]=true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return false;
    }

    /// Cycle Detection using DFS.
    cychelper(T node, map<T,bool> &visited, map<T,bool> &instack)
    {
        instack[node]=true;
        visited[node]=true;
        for(T nbr: adjlist[node])
        {
            if(!visited[nbr] && cychelper(nbr,visited,instack)|| instack[nbr])
            {
                return true;
            }
        }
        return false;
    }

    bool iscyclicdfs(T src)
    {
        map<T,bool>visited;
        map<T,bool> instack;
        visited[src]=true;
        instack[src]=true;
        bool c;
        for(auto i: adjlist)
        {
            T node = i.first;
            if(!visited[node])
            {
                c = cychelper(src,visited,instack);
            }
        }
        if(c)
            cout<<"Cyclic"<<endl;
        else
            cout<<"Not Cyclic"<<endl;
    }


};

int main()
{
    graph <int> g;
    g.addedge(1,2,false);
    g.addedge(2,3,false);
    g.addedge(3,4,false);
    g.addedge(4,2,false);
    g.addedge(4,1,false);
    g.addedge(5,3,false);
    g.addedge(5,6,false);
    g.addedge(6,6,false);
    //g.addedge(6,7);
    g.print();
    cout<<endl<<endl;
    //g.bfs(0);
    cout<<endl<<endl;
    //g.ssp(0);
    cout<<endl<<endl;
    g.dfs(1);
    cout<<endl<<endl;
    g.connected_components(1);
    cout<<endl<<endl;
    if(g.iscyclicbfs(1))
    {
        cout<<"Cyclic"<<endl;
    }
    else
        cout<<"Not, Cyclic "<<endl;

    g.iscyclicdfs(1);


    cout<<endl<<endl;
    graph <string> g1;
    g1.addedge("PUTIN","TRUMP",false);
    g1.addedge("PUTIN","MODI",false);
    g1.addedge("PUTIN","POPE",false);
    g1.addedge("MODI","TRUMP",true);
    g1.addedge("MODI","YOGI",true);
    g1.addedge("YOGI","PRABHU",false);
    g1.addedge("PRABHU","MODI",false);
    //g1.print();
    cout<<endl<<endl;
    //g1.bfs("MODI");

    return 0;
}
