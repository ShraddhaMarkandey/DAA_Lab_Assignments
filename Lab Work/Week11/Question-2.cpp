#include<bits/stdc++.h>
using namespace std;
int count(int S[],int n,int sum)
{
    int i,j,x,y;
    int table[sum+1][n];
    for(i=0;i<n;i++)
    {
        table[0][i]=1;
    }
    for(i=1;i<sum+1;i++)
    {
        for(j=0;j<n;j++)
        {
            x=(i-S[j]>=0)?table[i-S[j]][j]:0;
            y=(j>=1)?table[i][j-1]:0;
            table[i][j]=x+y;
        }
    }
    return table[sum][n-1];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<count(arr,n,sum);
    return 0;
}