#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;



int BS(int arr[],int key,int low,int high)
{
    if(high==low)
    {
        if(key>arr[low])
           return (low+1);
            else
           return low;
    }

    int mid=(low+high)/2;

    if(key==arr[mid])
        return mid+1;

    if(key>arr[mid])
        return BS(arr,key,mid+1,high);
    else
    return BS(arr,key,low,mid-1);

}
void insertionSort(int arr[], int n)
{for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j=i-1;
        int location=BS(arr,key,0,j);

       while ( j >= location)
        { arr[j+1] = arr[j];
           j--;
        }
        arr[j + 1] = key;
    }
}
  int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
   for(int k=0;k<n;k++)
    cout<<arr[k]<<" ";

    return 0;
}
