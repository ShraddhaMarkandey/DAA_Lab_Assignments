#include<iostream>
using namespace std;
int swaps,comparisons;
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int left,int right)
{
    int pivot=arr[right];
    int i=left-1;
    for (int j=left;j<right;j++)
    {
        comparisons++;
        if(arr[j]<=pivot)
        {
            swaps++;
            i++;
            swap(arr,i,j);
        }
    }
    swaps++;
    swap(arr,i+1,right);
    return i+1;
}
void quickSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int pivot=partition(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
    }
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        comparisons=0;
        swaps=0;
        int size;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        quickSort(arr,0,size-1);
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\nComparisons="<<comparisons<<endl;
        cout<<"Swaps="<<swaps<<endl;
        testCases--;
    }
    return 0;
}