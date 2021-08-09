#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map
 
 
void solve(){
    //code
    // mtv("hii");
        vector<vector<int>>v{{4,5},{5,7},{1,2,3},{5,6}};
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<v[i][j]<<" ";;
            }
            cout<<"\n";
        }
}
 
 
int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);

#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t = 1;
	// cin >> t;
    for(ll i = 1; i <= t; i++){
        solve();
    }
}