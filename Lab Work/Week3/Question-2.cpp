#include<iostream>
using namespace std;
void selectionSort(int arr[],int len)
{
    int temp,pos,comparison=0,swap=0;
    for(int i=0;i<len-1;i++)
    {
        pos=i;
        for(int j=i+1;j<len;j++)
        {
            comparison++;
            if(arr[pos]>arr[j])
            {
               pos=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
        swap++;
    }
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Comparisons="<<comparison<<endl;
    cout<<"Swaps="<<swap<<endl;
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
        selectionSort(arr,size);
        testCases--;
    }
    return 0;
}