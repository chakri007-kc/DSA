#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll partition(ll a[],ll low,ll high)
{
    ll pivot=a[high];
    ll index=low-1;
    for(ll i=low;i<high;i++){
        if(a[i]<pivot)
        {
            index++;
            swap(a[index],a[i]);
        }
    }
    swap(a[index+1],a[high]);
    return index+1;

}
void quick_sort(ll a[],ll low ,ll high)
{
    if(low>=high) return;
    ll p=partition(a,low,high);
    quick_sort(a,low,p-1);
    quick_sort(a,p+1,high);
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
    quick_sort(a,0,n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}