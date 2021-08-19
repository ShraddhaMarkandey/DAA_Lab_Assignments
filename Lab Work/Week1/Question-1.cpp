#include<iostream>
using namespace std;
void linearSearch(int arr[],int len,int key_element)
{
    int comparison=0;
    int flag=0;
    for(int i=0;i<len;i++)
    {   
        comparison++;
        if(*(arr+i)==key_element)
        {
          cout<<"Present"<<" "<<comparison<<endl;
          flag=1;
          break;
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
        linearSearch(arr,size,key);
        testCases--;
    }
    return 0;
}