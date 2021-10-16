#include<bits/stdc++.h>
using namespace std;
void displayParent(vector<int>&parent,int x)
{
    cout<<x+1<<" ";
    if(parent[x]>=0)
       displayParent(parent,parent[x]);
}
void bellmanFord(int **arr,int vertex,int source)
{
    vector<int>weight(vertex,INT_MAX);
    vector<int>parent(vertex,-1);
    weight[source]=0;
    for(int i=0;i<vertex-1;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            for(int k=0;k<vertex;k++)
            {
                if(arr[j][k]!=0)
                {
                    if(weight[j]!=INT_MAX&&weight[k]>weight[j]+arr[j][k])
                    {
                        weight[k]=weight[j]+arr[j][k];
                        parent[k]=j;
                    }
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
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            cin>>arr[i][j];
        }
    }
    cin>>source;
    bellmanFord(arr,vertex,source-1);
    return 0;

}