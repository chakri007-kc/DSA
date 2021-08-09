#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll key;
    cin>>key;
    ll l=0,r=n-1;
    ll mid=(l+r)/2;
    if(a[0]>key)
    {
        cout<<"-1\n";
        return 0;
    }
    if(a[n-1]<key)
    {
        cout<<"-2\n";
        return 0;
    }

    while(l<=r)
    {
        if(a[mid]==key){
            cout<<mid<<"\n";
            return 0;
        }
        else if(a[mid]>key){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
        mid=(l+r)/2;
    }
    cout<<mid<<"\n";
}