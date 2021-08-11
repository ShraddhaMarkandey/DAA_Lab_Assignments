#include<iostream>
using namespace std;
void insertionSort(int arr[],int len)
{
    int temp,comparison=0,shift=0,j;
    for(int i=1;i<len;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>temp)
        {
            comparison++;
            shift++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        shift++;
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Comparisons="<<comparison<<endl;
    cout<<"Shifts="<<shift<<endl;
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size,temp;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        insertionSort(arr,size);
        testCases--;
    }
    return 0;
}