#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void heapify(ll a[],ll i,ll n)
{
    ll l=(2*i)+1 , r=(2*i)+2;
    ll largest=i;
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,largest,n);
    }
}

void heap_sort(ll a[],ll n){
    for(ll i=(n/2)-1;i>=0;i--){
        heapify(a,i,n);
    }
    for(ll i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
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
    heap_sort(a,n); 
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}