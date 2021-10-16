#include<bits/stdc++.h>
using namespace std;
void displayParent(vector<int>&parent,int x)
{
    cout<<x+1<<" ";
    if(parent[x]>=0)
       displayParent(parent,parent[x]);
}
void dijkstra(int **arr,int vertex,int source)
{
    vector<int>parent(vertex,-1);
    vector<int>weight(vertex,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
    weight[source]=0;
    min_heap.push(make_pair(weight[source],source));
    while(!min_heap.empty())
    {
        int x=min_heap.top().second;
        min_heap.pop();
        for(int i=0;i<vertex;i++)
        {
            if(arr[x][i]!=0)
            {
                if(weight[i]>weight[x]+arr[x][i])
                {
                    weight[i]=weight[x]+arr[x][i];
                    min_heap.push(make_pair(weight[i],i));
                    parent[i]=x;
                }
            }
        }
    }
    for(int i=0;i<vertex;i++)
    {
        displayParent(parent,i);
        if(weight[i]==INT_MAX)
           cout<<": INT_MAX"<<endl;
        else
           cout<<": "<<weight[i]<<endl;
    }
}
int main()
{
    int vertex,source;
    cin>>vertex;
    int **arr=(int **)malloc(vertex*sizeof(int *));
    for(int i=0;i<vertex;i++)
    {
        arr[i]=(int *)malloc(vertex*sizeof(int));
    }
    for(int  i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>source;
    dijkstra(arr,vertex,source-1);
    return 0;
}