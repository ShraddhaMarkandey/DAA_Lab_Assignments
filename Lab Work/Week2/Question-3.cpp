#include<iostream>
using namespace std;
int countPairs(int arr[],int len,int diff)
{
    int count=0;
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(arr[i]-arr[j]==diff||arr[j]-arr[i]==diff)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size,key;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        cin>>key;
        int total=countPairs(arr,size,key);
        cout<<total<<endl;
        testCases--;
    }
    return 0;
}