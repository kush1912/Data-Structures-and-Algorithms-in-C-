/*
Andrew was attempting a mathematics test where he needed to solve problems with factorials. 
One such problem had an answer which equaled 100! ,He wondered what would this number look like. 
He tried to calculate 100! On his scientific calculator but failed to get a correct answer. 
Can you write a code to help Andrew calculate factorials of such large numbers?
*/
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

vector<int> multiply(vector<int> mult, int p)
{
    vector <int > v;
    int res,carry=0,temp;
    for( int i=0;i<mult.size();i++)
    {
        temp = p*mult[i];
        if(carry)
        {
            temp = temp + carry;
        }
        res = temp % 10;
        carry = temp/10;
        //cout<<res<<", ";
        v.push_back(res);
    }
    while(carry)
    {
        //cout<<carry%10<<" "<<endl;
        v.push_back(carry%10);
        carry = carry/10;
    }
   // v.reverse();
    return v;
}

void factorial(int n)
{
    vector <int> mult;
    mult.push_back(1);
    for(int i=2;i<=n;i++)
    {
        mult = multiply(mult,i);
    }
    //mult.reverse();
    for(int i =mult.size()-1;i>=0;i--)
    {
        cout<<mult[i];
    }
}

int main() {
	int n;
	cin>>n;
	factorial(n);
	return 0;
}
