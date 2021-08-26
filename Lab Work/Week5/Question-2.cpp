#include<iostream>
using namespace std;
void findPair(int arr[],int left,int right,int key)
{
    int flag=1;
    while(left<=right)
    {
        if(arr[left]+arr[right]>key)
           right--;
        else
        {
            if(arr[left]+arr[right]==key)
            {
                cout<<arr[left]<<","<<arr[right]<<" ";
                flag=0;
            }
            left++;
        }
    }
    if(flag==1)
       cout<<"No such pair exist";
    cout<<endl;
}
void merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        b[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=left;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
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
        mergeSort(arr,0,size-1);
        findPair(arr,0,size-1,key);
        testCases--;
    }
    return 0;
}