#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right) 
{
   int i=0,j=0,k=left,nl,nr;
   nl=mid-left+1; 
   nr=right-mid;
   int larr[nl],rarr[nr];
   for(i=0;i<nl;i++)
      larr[i]=arr[left+i];
   for(j=0;j<nr;j++)
      rarr[j]=arr[mid+1+j];
   while(i<nl&&j<nr) 
   {
      if(larr[i]<=rarr[j]) 
      {
         arr[k]=larr[i];
         i++;
      }
      else
      {
         arr[k]=rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) 
   {      
      arr[k]=larr[i];
      i++; 
      k++;
   }
   while(j<nr) 
   {  
      arr[k]=rarr[j];
      j++; 
      k++;
   }
}
void mergeSort(int arr[],int left,int right) 
{
   int mid;
   if(left<right) 
   {
      int mid=left+(right-left)/2;
      mergeSort(arr,left,mid);
      mergeSort(arr,mid+1,right);
      merge(arr,left,mid,right);
   }
}
void findDuplicate(int arr[],int len)
{
   mergeSort(arr,0,len-1);
   int flag=0;
   for(int i=0;i<len-1;i++)
   {
       if(arr[i]==arr[i+1])
       {
           flag=1;
           break;
       }
   }
   if(flag==1)
       cout<<"YES"<<endl;
   else
       cout<<"NO"<<endl;
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
        findDuplicate(arr,size);
        testCases--;
    }
    return 0;
}