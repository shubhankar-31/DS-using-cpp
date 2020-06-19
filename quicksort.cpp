#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot=arr[end];
    int partition_index=start;

    for(int i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[partition_index]);
            partition_index++;
        }
    }

    swap(arr[end],arr[partition_index]);
    return partition_index;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {int index=partition(arr,low,high);

      quicksort(arr,low,index-1);
      quicksort(arr,index+1,high);

    }
}

int main()
{int arr[]={4,7,3,2,6};

int n=sizeof(arr)/sizeof(int);
quicksort(arr,0,n-1);


for(int k=0;k<n;k++)
    cout<< arr[k]<<" ";

 return 0;

}
