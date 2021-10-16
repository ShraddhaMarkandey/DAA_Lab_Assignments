#include<bits/stdc++.h>
using namespace std;
long long shortest_KEdge(long long **arr,int vertex,int u,int v,int k)
{
    if(k<=0)
       return INT_MAX;
    else if(k==0)
    {
        if(u==v)
           return 0;
        else
           return INT_MAX;
    }
    else if(k==1)
    {
        if(u!=v)
           return arr[u][v];
        else
           return INT_MAX;
    }
    long long result=INT_MAX;
    for(int i=0;i<vertex;i++)
    {
        if(i!=u&&i!=v&&arr[u][i]!=0)
           result=min(result,arr[u][i]+shortest_KEdge(arr,vertex,i,v,k-1));
        
    }
    return result;
}
int main()
{
    int vertex,u,v,k;
    cin>>vertex;
    long long **arr=(long long **)malloc(vertex*sizeof(long long*));
    for(int i=0;i<vertex;i++)
    {
        arr[i]=(long long *)malloc(vertex*sizeof(long long));
    }
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>u>>v>>k;
    long long result=shortest_KEdge(arr,vertex,u-1,v-1,k);
    if(result==INT_MAX)
       cout<<"No path of length K is available"<<endl;
    else
       cout<<"Weight of shortest path from ("<<u<<","<<v<<") with "<<k<<" edges: "<<result<<endl;
    return 0;
}