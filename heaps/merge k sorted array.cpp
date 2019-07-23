///merge K sorted arrays

#include<bits/stdc++.h>
#include<queue>
#include<vector>
#include <utility>

using namespace std;

/// A pair of pair first part contains the element second part contains the indexes.
typedef pair<int, pair<int,int> > ppi;

vector<int> mergearray(vector<vector <int> > arr)
{
    vector <int> output;

    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0], {i,0} });   /// Way to insert values in pair

    }

    while(!pq.empty())
    {
        ppi t = pq.top();
        int i = t.second.first;
        int j = t.second.second;

        output.push_back(t.first);

        pq.pop();

        if(j+1<arr[i].size())
            pq.push({arr[i][j+1], {i,j+1} });
    }
    return output;
}

int main()
{
    int k,n,d;
    cin>>k>>n;

    /// In 2d vector we have to specify the number of rows during deceleration else it gives issues.
    vector< vector<int> > arr(k);

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>d;
            arr[i].push_back(d);  /// Input to 2d vectors.
        }
    }

    vector <int> v = mergearray(arr);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
