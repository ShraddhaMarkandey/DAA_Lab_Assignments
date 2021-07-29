#include<iostream>
using namespace std;
int firstOccurence(int arr[],int len,int key_element)
{
    int begin=0;
    int end=len-1;
    int mid;
    while(begin<=end)
    {   
        mid=begin+(end-begin)/2;
        if(arr[mid]==key_element)
        {
            if(mid-1>=0&&arr[mid-1]==key_element)
            {
                end=mid-1;
                continue;
            }
            return mid;
        }
        else if(arr[mid]<key_element)
        {
            begin=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int lastOccurence(int arr[],int len,int key_element)
{
    int begin=0;
    int end=len-1;
    int mid;
    while(begin<=end)
    {   
        mid=begin+(end-begin)/2;
        if(arr[mid]==key_element)
        {
            if(mid+1>=0&&arr[mid+1]==key_element)
            {
                begin=mid+1;
                continue;
            }
            return mid;
        }
        else if(arr[mid]<key_element)
        {
            begin=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return -1;
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size,key,first_index,last_index;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        cin>>key;
        first_index=firstOccurence(arr,size,key);
        last_index=lastOccurence(arr,size,key);
        if(first_index!=-1||last_index!=-1)
            cout<<key<<"-"<<last_index-first_index+1<<endl;
        else
            cout<<"Key not present"<<endl;
        testCases--;
    } 
    return 0;
}