/// Implementation of Heap without queue.

#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
class heap
{
    vector<int> v;
    bool minheap;

/// Compare for min and max heap
    bool compare(int a,int b)
    {
        if(minheap)
            return a<b;
        else
            return a>b;
    }

    /// heapify
    void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i+1;

        int minindex = i;
        if(left < v.size() && compare(v[left],v[minindex]))
        {
            minindex = left;
        }
        if(right<v.size() && compare(v[right],v[minindex]))
        {
            minindex = right;
        }

        if(minindex!=i)
        {
            swap(v[i],v[minindex]);
            heapify(minindex);
        }
    }
public:
    heap(bool type = true){
    minheap = type;
    v.push_back(-1);
    }

    /// Insert the element
    void push(int data)
    {
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;

        while(index >1 && compare(v[index],v[parent]))
        {
            swap(v[index],v[parent]);
            index= parent;
            parent =index/2;
        }
    }
///  Topmost element
    int top()
    {
        return v[1];
    }
/// check if heap is empty
    bool isempty(){
    if(v.size()==1)
        return true;
    else
        return false;
    }

/// print the heap
    void printheap()
    {
        for(int i=1;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    /// Delete or Pop the element
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }
};


int main()
{
    heap h(false);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);
    h.push(1);

    //cout<<h.top()<<endl;
    while(!h.isempty())
    {
        cout<<h.top()<<endl;
        h.printheap();
        h.pop();
    }
    return 0;
}
