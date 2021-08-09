#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,vector<ll>>m;
void addEdge(ll from, ll to)
{
    m[from].push_back(to);
}
map<ll,bool>visited;
void BFS(ll vertex)
{
    queue<ll>q;
    q.push(vertex);
    visited[vertex]=true;
    while(!q.empty())
    {
        ll z=q.front();
        cout<<z<<" ";
       
        q.pop();
        for(ll i=0;i<m[z].size();i++)
        { 
            if(visited[m[z][i]]==false)
            {
                visited[m[z][i]]=true;
                q.push(m[z][i]);
            }
        }
    }
}
int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    addEdge(3, 4);
    addEdge(4, 1);
    BFS(3);
}