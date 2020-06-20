#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;
void quicksort(int arr[],int low,int high)
{    int i=low,j=high;
        int pivot=arr[(low+high)/2];

while(i<=j)
{    while(arr[i]<pivot)
        i++;
     while(arr[j]>pivot)
        j--;

        if(i<=j)
        { swap(arr[i],arr[j]);
            i++;j--;
        }

}

if(low<j)
    quicksort(arr,low, j);

    if(i<high)
    quicksort(arr,i, high);


}

int main()
{int arr[]={4,7,3,2,6};

int n=sizeof(arr)/sizeof(int);
quicksort(arr,0,n-1);


for(int k=0;k<n;k++)
    cout<< arr[k]<<" ";

 return 0;

}
