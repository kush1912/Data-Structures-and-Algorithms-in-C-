/*
The first line contains space separated integers.
The integers are such that all the values are distinct but the value start repeating once the cycle gets completed.
The list of integers given ends when -1 is input.

Sample Input
1 2 3 4 5 2 3 -1
Sample Output
1 2 3 4 5



public boolean detectRemoveLoop() {

        // detect loop
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {

            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        if (slow == fast) {

            // loop remove
            Node start = head;
            Node loop = slow;

            while (start.next != loop.next) {
                start = start.next;
                loop = loop.next;
            }

            loop.next = null;

            return true;

        } else {

            // loop doesnot exist
            return false;
        }

    }

*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int data,n=0;
    vector<int> v;
    int freq[100000]={0};
    cin>>data;
    freq[data]=1;
    v.push_back(data);

    while(data!=-1)
    {
        if(freq[data]==0)
        {
            freq[data]=1;
            v.push_back(data);
        }
        cin>>data;
    }
    for(int i=0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
