#include<iostream>
using namespace std;
int comparison=0;
int linearSearch(int arr[],int len,int begin,int key_element)
{
    for(int i=begin;i<len;i++)
    {
        comparison++;
        if(arr[i]==key_element)
        {
            return 1;
        }
    }
    return -1;
}
int binarySearch(int arr[],int begin,int end,int key_element)
{
    int middle;
    while(begin<=end)
    {
        middle=begin+(end-begin)/2;
        comparison++;
        if(arr[middle]==key_element)
        {
            return 1;
        }
        if(arr[middle]<key_element)
        {
            begin=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }
    return -1;
}
int exponentialSearch(int arr[],int len,int key_element)
{
    comparison=0;
    if(arr[0]==key_element)
    { 
        comparison++;
        return 1;
    }
    else
    {
        comparison++;
    }
    int i=1;
    while(i<len&&arr[i]<=key_element)
    { 
        comparison++;
        i=i*2;
    }
    return linearSearch(arr,len,int(i/2),key_element);
    // return binarySearch(arr,int(i/2),min(i,len-1),key_element);
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
        if(exponentialSearch(arr,size,key)==1)
        {
            cout<<"Present"<<" "<<comparison<<endl;
        }
        else
        {
            cout<<"Not Present"<<" "<<comparison<<endl;
        }
        testCases--;
    }
    return 0;
}