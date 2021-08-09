#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int graph[1000][1000]={0};
void addEdge(int from,int to){
	graph[from][to]=1;
}

void DFS(int vertex,bool visited[])
{
    visited[vertex]=true;
    printf("%d ",vertex);
    for(int i=0;i<1000;i++)
    {
        if(visited[i]==false && graph[vertex][i]==1)
        {
            DFS(i,visited);
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
    bool visited[1000];
    for(int i=0;i<1000;i++) visited[i]=false;
    DFS(1,visited);
}