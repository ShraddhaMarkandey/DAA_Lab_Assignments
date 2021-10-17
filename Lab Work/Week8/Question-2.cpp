#include<bits/stdc++.h>
using namespace std;
int findParent(vector<int>parent,int u)
{
    if(parent[u]<0)
    {
        return u;
    }
    return findParent(parent,parent[u]);
}
bool UnionByWeight(vector<int>&parent,int u,int v)
{
    int pu=findParent(parent,u);
    int pv=findParent(parent,v);
    if(pu!=pv)
    {
        if(parent[pu]<=parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
        return true;
    }
    return false;
}
int kruskals(int **arr,int vertex)
{
    vector<pair<int,pair<int,int>>>G;
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            if(arr[i][j]!=0)
            {
                G.push_back(make_pair(arr[i][j],make_pair(i,j)));
            }
        }
    }
    sort(G.begin(),G.end());
    vector<int>parent(vertex,-1);
    int sum=0;
    for(auto i:G)
    {
        int u=i.second.first;
        int v=i.second.second;
        int w=i.first;
        if(UnionByWeight(parent,u,v))
        {
            sum=sum+w;
        }
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
    cout<<"Minimum spanning weight : "<<kruskals(arr,vertex)<<endl;
    return 0;
}
