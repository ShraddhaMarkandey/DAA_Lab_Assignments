#include<bits/stdc++.h>
using namespace std;
void markVisited(int **arr,int len,int j)
{
    for(int i=0;i<len;i++)
    {
        if(arr[i][j]==1)
          arr[i][j]=2;
    }
}
bool isBipartite(int **arr,int len)
{
    queue<int>que;
    que.push(0);
    int color[len]={1};
    markVisited(arr,len,0);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        int currentColor=color[u]*-1;
        for(int i=0;i<len;i++)
        {
            if(arr[u][i]!=0)
            {
                if(color[i]==0)
                  color[i]=currentColor;
                else if(color[i]!=currentColor)
                  return false;
                if(arr[u][i]==1)
                {
                    que.push(i);
                    markVisited(arr,len,i);
                }
            }
        }
    }
    return true;
}
int main()
{
    int size;
    cin>>size;
    int **arr;
    arr=(int **)malloc(size*sizeof(int *));
    for(int i=0;i<size;i++)
      arr[i]=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cin>>arr[i][j];
        }
    }
    bool bipartite=isBipartite(arr,size);
    if(bipartite)
      cout<<"Bipartite"<<endl;
    else
      cout<<"Not Bipartite"<<endl;
    return 0;
}