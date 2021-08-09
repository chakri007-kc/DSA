#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,vector<ll>>m;
map<ll,bool>visited;
void addEdge(ll from, ll to)
{
    m[from].push_back(to);
}
void DFS(ll n)
{
    visited[n]=true;
    cout<<n<<" ";
    for(ll i=0;i<m[n].size();i++)
    {
        if(visited[m[n][i]]==false)
        {
            // visited[m[n][i]]=true;
            DFS(m[n][i]); 
        }
    }
}
int main()
{
    addEdge(0,1);
    addEdge(0, 9);
    addEdge(1, 2);
    addEdge(1,5);
    addEdge(2, 0);
    addEdge(2,6);
    addEdge(2, 3);
    addEdge(3,10);
    addEdge(9, 3);
    DFS(1);
}