#include <bits/stdc++.h>
using namespace std;
int minDist(bool visited[],int value[],int n)
{
    int m=INT_MAX,index;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false && value[i]<=m)
        {
            m=value[i];
            index=i;
        }
    }
    return index;
}
void prims(vector<vector<int>> &graph,bool visited[],int parent[],int value[],int source)
{
    int n=graph.size();
    value[source]=0;
    for(int i=0;i<n-1;i++)
    {
        int u=minDist(visited,value,n);
        // cout<<u<<"\n";
        visited[u]=true;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && graph[u][j]!=0 && graph[u][j]<value[j])
            {
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
}

int main()
{
    //  vector<vector<int>> graph = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
    //                             { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
    //                             { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
    //                             { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
    //                             { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
    //                             { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
    //                             { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
    //                             { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
    //                             { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    vector<vector<int>> graph ;
    int n,e;
    cin>>n>>e;
    graph.resize(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        int from,to,c;
        cin>>from>>to>>c;   
        graph[from][to]=c;
        graph[to][from]=c;

    }

    // int n = graph.size();
    bool visited[n];
    // memset(visited,false,sizeof(visited));
    int parent[n];
    parent[0]=-1;
    // memset(parent,-1,sizeof(parent));
    int value[n];
    // memset(value,INT_MAX-1,sizeof(value));
    for(int i = 0; i < n; i++){
        value[i] = INT_MAX;       
        visited[i] = false;        
    }
    prims(graph,visited,parent,value,0);

    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<"->"<<i<<" "<<graph[i][parent[i]]<<" "<<value[i]<<" "<<graph[parent[i]][i]<<"\n";
    }
} 
