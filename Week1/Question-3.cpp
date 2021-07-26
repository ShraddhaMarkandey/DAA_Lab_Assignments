#include<iostream>
#include<math.h>
using namespace std;
int jumpSearch(int arr[],int key_element,int len,int *comp)
{
	int step=sqrt(len);
	int prev=0;
	while(arr[int(min(step,len)-1)]<key_element)
	{ 
        *comp+=1;
		prev=step;
		step+=sqrt(len);
		if(prev>=len)
			return -1;
	}
	while(arr[int(prev)]<key_element)
	{ 
        *comp+=1;
		prev++;
		if(prev==min(step,len))
			return -1;
	}
	if(arr[int(prev)]==key_element)
    {
        *comp+=1;
		return 1;
    }
	return -1;
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases)
    {
        int size,key,comparison=0;
        cin>>size;
        int arr[size];
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        cin>>key;
        int result=jumpSearch(arr,key,size,&comparison);
        if(result==1)
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
