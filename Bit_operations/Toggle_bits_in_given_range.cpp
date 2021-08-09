#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,r;
    cin>>n>>l>>r;

    int val=0;
    int p=0;
    int mask=1;
    
    int i=1;
    while(i<l)
    {
        if(n&mask)
        {
            val=val+pow(2,p);
        }
        mask<<=1;
        p++;
        i++;
    }
    while(i<=r)
    {
        if(!(n&mask))      
        {
            val=val+pow(2,p);
        }
        mask<<=1;
        p++;
        i++;
    }
    while(i<=32)
    {
        if(n&mask)
        {
            val=val+pow(2,p);
        }
        mask<<=1;
        p++;
        i++;
    }
    cout<<val<<'\n';

}