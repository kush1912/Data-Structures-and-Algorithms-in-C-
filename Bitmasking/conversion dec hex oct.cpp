#include <iostream>
#include<string>
#include<bitset>
using namespace std;

int count(int m)
{
    int c= 0;
    while(m)
    {
        if(m%10==1)
        c++;
        m =m/10;
    }
	return c;
}


int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
	    /*
	    itoa (i,buffer,10);
        printf ("decimal: %s\n",buffer);
        itoa (i,buffer,16);
        printf ("hexadecimal: %s\n",buffer);
        itoa (i,buffer,2);
        printf ("binary: %s\n",buffer);
	    */
	    
	    string a = bitset<8>(arr[i]).to_string();
	    //cout<<a<<" ";
	    int m = stoi(a);
	    cout<< count(m)<<endl;
	}
	return 0;
}
