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

};

int main()
{
    graph <int> g;
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.addedge(5,6);
    g.addedge(6,7);
    g.print();
    cout<<endl<<endl;
    //g.bfs(0);
    cout<<endl<<endl;
    //g.ssp(0);
    cout<<endl<<endl;
    //g.dfs(0);
    g.connected_components(0);



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
