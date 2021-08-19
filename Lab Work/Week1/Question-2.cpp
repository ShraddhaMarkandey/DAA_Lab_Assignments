#include<iostream>
using namespace std;
void binarySearch(int arr[],int len,int key_element)
{
    int begin=0;
    int end=len-1;
    int comparison=0;
    int middle;
    int flag=0;
    while(begin<=end)
    {
        middle=begin+(end-begin)/2;
        comparison++;
        if(arr[middle]==key_element)
        {
            cout<<"Present"<<" "<<comparison<<endl;
            flag=1;
            break;
        }
        else if(arr[middle]<key_element)
        {
            begin=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }
    if(flag==0)
    {
        cout<<"Not Present"<<" "<<comparison<<endl;
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
        binarySearch(arr,size,key);
        testCases--;
    }
    return 0;
}