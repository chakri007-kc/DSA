#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int queue[1000];
int start=0;
int size=0;

void push(int k)
{
    queue[size]=k;
    size=size+1;
    // printf("%d %d\n",size-1,queue[size-1]);
}
void pop()
{
    start=start+1;
}
int front()
{
    return queue[start];
}
bool isempty()
{
    // printf("%d ",size-start);
    if((size-start)==0) return true;
    else return false;
}


int graph[1000][1000]={0};
void addEdge(int from,int to){
	graph[from][to]=1;
}

void BFS(int vertex,bool visited[])
{
     push(vertex);
    //  printf("%d",vertex);
    while(!isempty())
    {
        // printf("HII ");
        int z=front();
        printf("%d ",z);
        visited[z]=true;
        pop();
        for(int i=0;i<1000;i++)
        { 
            if(visited[i]==false && graph[z][i]==1)
            {
                visited[i]=true;
                push(i);
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
    bool visited[1000];

    for(int i=0;i<1000;i++) visited[i]=false;
    BFS(3,visited);
}