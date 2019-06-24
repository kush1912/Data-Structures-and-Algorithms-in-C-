//((a*b)+(c+d))

#include <iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main()
{
    stack<char> braces;
    string exp;
    getline(cin,exp);
    //cout<<exp;
    int i=0;
    while(exp[i]!=NULL)
    {
        //cout<<exp[i]<<endl;
        
        if(exp[i]=='(')
        {
            braces.push(exp[i]);
        }
        
        if(exp[i]==')')
        braces.pop();
        
        i++;
    }
    if(braces.empty())
    cout<<"BALANCED";
    else
    cout<<"NOT BALANCED";
    return 0;
}
