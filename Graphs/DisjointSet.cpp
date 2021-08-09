#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>dsuf;
ll find(ll k){
    if(dsuf[k]==-1) return k;
    return find(dsuf[k]);
}
ll union_op(ll u,ll v){
    ll a=find(u);
    ll b=find(v);
    dsuf[a]=b;
    // cout << a<<" "<<b<<"\n";
}

bool iscyclic(vector<pair<ll,ll>>list){
    for(auto i:list){
        // cout<<find(i.first)<<" "<<find(i.second)<<"\n";
        if(find(i.first)==find(i.second)) return true;
        union_op(i.first,i.second);
    }
    return false;
}
int main(){
    ll e,v;
    cin>>e>>v;
    dsuf.resize(v,-1);
    vector<pair<ll,ll>>list;
    for(ll i=0;i<e;i++){
        ll from,to;
        cin>>from>>to;
        list.push_back({from,to});
    }
    if(iscyclic(list)){
        cout<<"cycle is found\n";
    }
    else cout<<"cycle is not found\n";

}