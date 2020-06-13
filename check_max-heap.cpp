#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>

//checking whether the array is max heap or not ??
using namespace std;
bool checking_heap(int arr[],int n)
{
    for(int i=0; i<=(n-2)/2; i++)
{
       if(arr[i]<=arr[(2*i)+1])
       return false;

    if((2*i)+2<n&&arr[i]<=arr[(2*i)+2])
    return false;

}
return true;
}

int main()
{
int arr[]={90, 15, 10, 7, 12, 2};
int n=sizeof(arr)/sizeof(int);


  checking_heap(arr,n)?cout<< "yess":cout<<"NO";
 return 0;

}
