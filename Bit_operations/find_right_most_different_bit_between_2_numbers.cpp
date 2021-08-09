#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int b;
    cin>>a>>b;
    int mask=1;
    int c=1;
    while( (a&mask) == (b&mask) )
    {
        mask<<=1;
        c++;
    }
    cout<<c<<"\n";
}