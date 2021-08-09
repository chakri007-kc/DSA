#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll n;
    cin>>n;
    
    for(ll i=1;i<=n;i++)
    {
        ll  k=1;
        for(ll j=0;j<i;j++)
        {
            k=k*26;
        }
        for(ll j=0;j<k;j++)
        {
            string s="";
            ll z=j;
            ll h=i;
            while(h)
            {
                ll x=z%26;
                s=char('a'+ x)+s;
                z=z/26;
                h--;
            }
            cout<<s<<" "; 


        }
         
    }
}