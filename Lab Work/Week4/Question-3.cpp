#include<iostream>
using namespace std;
int Kth_SmallestOrLargest(int arr[],int left,int right,int k)
{
    int p=arr[right];
    int i=left-1;
    for(int j=left;j<=right;j++)
    {
        if(arr[j]<=p)
        {
            int t=arr[++i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    if(i==k)
       return arr[i];
    else if(i<k)
       return Kth_SmallestOrLargest(arr,i+1,right,k);
    else
       return Kth_SmallestOrLargest(arr,left,i-1,k);
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
        int k;
        cin>>k;
        k=k<=size?k-1:size-1;
        cout<<Kth_SmallestOrLargest(arr,0,size-1,k)<<endl;
        testCases--;
    }
    return 0;
}