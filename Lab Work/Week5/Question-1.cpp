#include<iostream>
using namespace std;
void countOccurrences(char arr[],int len)
{
    int count[26]={0};
    int index;
    int pos=-1,max=0;
    for(int i=0;i<len;i++)
    {
        index=arr[i]-'a';
        count[index]++;
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]!=0&&count[i]>max)
        {
            pos=i;
            max=count[i];
        }
    }
    if(max>1)
       cout<<char('a'+pos)<<" - "<<count[pos]<<endl;
    else
       cout<<"No Duplicates Present"<<endl; 
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size;
        cin>>size;
        char arr[size];
        for(int i=0;i<size;i++)
        {
           cin>>arr[i];
        }
        countOccurrences(arr,size);
        testCases--;
    }
    return 0;
}