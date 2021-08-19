#include<iostream>
using namespace std;
int linearSearch(int arr[],int len,int key_element)
{ 
    for(int i=0;i<len;i++)
    {
       if(arr[i]==key_element)
       {
          return 1;
       }
    }
    return -1;
}
int main()
{
   int test_cases,size,key;
   cin>>test_cases;
   for(int i=0;i<test_cases;i++)
   {
       cin>>size;
       int arr[size];
       for(int j=0;j<size;j++)
       {
           cin>>arr[j];
       }
       cin>>key;
       if(linearSearch(arr,size,key)==1)
       {
           cout<<"Present"<<endl;
       }
       else
       {
           cout<<"Not Present"<<endl;
       }
   }
   return 0;
}