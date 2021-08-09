#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int mask=mask<<k;
    // cout<<b<<" "<<mask<<"\n";
    if(n&mask) cout<<"yes\n";
    else cout<<"no\n";
}