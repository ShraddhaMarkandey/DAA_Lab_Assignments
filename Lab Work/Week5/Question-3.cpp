#include<iostream>
using namespace std;
int main()
{
    int size1,size2,i=0,j=0;
    cin>>size1;
    int arr1[size1];
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }
    cin>>size2;
    int arr2[size2];
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }
    while(i!=size1&&j!=size2)
    {
        if(arr1[i]==arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j])
            i++;
        else
            j++;
    }
    return 0;
}