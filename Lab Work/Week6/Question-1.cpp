#include<bits/stdc++.h>
using namespace std;
void markVisited(int **arr,int len,int j)
{
    for(int i=0;i<len;i++)
    {
        arr[i][j]=2;
    }
}
bool dfs(int **arr,int len,int source,int dest)
{
    stack<int>st;
    st.push(source);
    markVisited(arr,len,source);
    while(!st.empty())
    {
        int x=st.top();
        st.pop();
        if(arr[x][dest]==1)
           return true;
        else
        {
            for(int i=0;i<len;i++)
            {
                if(arr[x][i]==1)
                   st.push(i);
            }
            markVisited(arr,len,x);
        }
    }
    return false;
}
int main()
{
    int size,source,destination;
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
    cin>>source>>destination;
    bool isPath=dfs(arr,size,source-1,destination-1);
    if(isPath)
       cout<<"Yes Path Exists"<<endl;
    else
       cout<<"No Such Path Exists"<<endl;
    return 0;
}