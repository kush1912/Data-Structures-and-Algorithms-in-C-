/// Find nearest 3 cars to the origin.

/// This question explains the meaning and working of functors in heaps along with custom comparators.

#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

class car
{
public:
    int x,y,id;
    car(int id, int x,int y)
    {
        /// This is used when the parameters of the constructor have the same name as the variables of the class members.
        /// Its a pointer to the current object, and it refers to the current object.
        this->x=x;
        this->y=y;
        this->id= id;
    }

    int dist()
    {
        return x*x+y*y;
    }

    void print()
    {
        cout<<"ID: "<<id<<" Location is : "<<x<<" "<<y<<endl;
    }
};

/// Functor to compare two cars
/// Functors are functional objects i.e. objects which work as functions.
class comparecar
{
public:
    /// Method to overload  () operator
    bool operator()(car a, car b){
        return a.dist()<b.dist();
    }

};

int main()
{
    priority_queue<car,vector<car>,comparecar> pq;

    int x[8]={5,6,17,18,9,11,0,3};
    int y[8]={1,-2,8,9,10,91,1,2};

    for(int i=0;i<8;i++)
    {
        car c(i+1,x[i],y[i]);
        pq.push(c);
    }
    int poppings =1;
     while(!pq.empty() && poppings<=3)
     {
         car c=pq.top();
         c.print();
         pq.pop();
         poppings++;
     }
    return 0;
}

