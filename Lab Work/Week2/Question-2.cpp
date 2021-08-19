#include<iostream>
using namespace std;
void indices(int arr[],int len)
{
    int flag=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            for(int k=0;k<len;k++)
            {
                if(arr[i]+arr[j]==arr[k])
                {
                    cout<<i+1<<","<<j+1<<","<<k+1<<endl;
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0)
    {
        cout<<"No sequence found."<<endl;
    }
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        indices(arr,size);
        testCases--;
    }
    return 0;
}