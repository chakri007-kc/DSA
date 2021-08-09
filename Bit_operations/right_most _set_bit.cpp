#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=1;
    while(n!=0)
    {
        if(n%2==0) c++;
        n=n/2;
    }
    cout<<c<<"\n";
}