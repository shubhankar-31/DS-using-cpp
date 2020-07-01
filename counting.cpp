#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <functional>
#define  space cout<<"\n\n\n\n";
#define vi vector<int>

#define limit 1000
using namespace std;

void countsort(vi &arr,int size)
{
    int count_array[limit];
    int output[size];

    int max=INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }

    for(int i=0;i<max+1;i++)
        count_array[i]=0;

    for(int i=0;i<size;i++)
       count_array[arr[i]]++;


    for(int i=1;i<max+1;i++)
        count_array[i]+=count_array[i-1];



    for(int i=size-1;i>=0;i--)
        {output[count_array[arr[i]]-1]=arr[i];
        count_array[arr[i]]--;
        }

    for(int i=0;i<size;i++)
        arr[i]=output[i];
}

int main()
{
vi arr={4,2,2,8,3,3,1,7,7,33,4,9};
countsort(arr, arr.size());

for(int k=0;k<arr.size();k++)
    cout<< arr[k]<<" ";

 return 0;

}
