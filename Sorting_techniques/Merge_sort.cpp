#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void merge(ll a[],ll l,ll m,ll r)
{
    ll n1=m-l+1 , n2=r-m;
    // cout<<l<<" "<<m<<" "<<r<<"\n"; 
    ll left[n1],right[n2];

    for(ll i=0;i<n1;i++){
        left[i]=a[i+l];
    }

    for(ll i=0;i<n2;i++){
        right[i]=a[i+m+1];
    }

    ll i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j]){
            a[k]=left[i];
            k++;
            i++;
        }
        else{
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        i++;k++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        j++;k++;
    }
}
void merge_sort(ll a[],ll l,ll r)
{
    if(l>=r) return;
    ll m=(l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    merge_sort(a,0,n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}