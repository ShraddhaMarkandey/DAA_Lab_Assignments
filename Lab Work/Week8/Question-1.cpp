#include<bits/stdc++.h>
using namespace std;
int prims(int **arr,int vertex)
{
    vector<bool>visited(vertex,false);
    vector<int>weight(vertex,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    int source=0;
    weight[source]=0;
    min_heap.push(make_pair(weight[source],source));
    while(!min_heap.empty())
    {
        int u=min_heap.top().second;
        min_heap.pop();
        if(!visited[u])
        {
            visited[u]=true;
            for(int v=0;v<vertex;v++)
            {
                if(!visited[v]&&arr[u][v]!=0&&arr[u][v]<weight[v])
                {
                    weight[v]=arr[u][v];
                    min_heap.push(make_pair(weight[v],v));
                }
            }
        }
    }
    int sum=0;
    for(auto i:weight)
    {
        sum=sum+i;
    }
    return sum;
}
int main()
{
    int vertex;
    cin>>vertex;
    int **arr;
    arr=(int **)malloc(vertex*sizeof(int *));
    for(int i=0;i<vertex;i++)
    {
        arr[i]=(int *)malloc(vertex*sizeof(int));
    }
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Minimum spanning weight : "<<prims(arr,vertex);
    return 0;
}