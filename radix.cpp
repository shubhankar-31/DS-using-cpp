#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <functional>
#define vi vector<int>
#define  space cout<<"\n\n\n\n";
#define limit 250
using namespace std;
void countsort(vi &arr,int size,int place)
{
    int count[limit];
    int output[size];

    for(int i=0;i<limit;i++)
        count[i]=0;

    for(int i=0;i<size;i++)
       count[(arr[i]/place)%10]++;

    for(int i=1;i<limit;i++)
        count[i]+=count[i-1];

    for(int i=size-1;i>=0;i--)
    {
        output[count[(arr[i]/place)%10]-1]=arr[i];
         count[(arr[i]/place)%10]--;
    }
    for(int i=0;i<size;i++)
        arr[i]=output[i];
}

int get_max(vi &arr,int size)
{
  int max=INT_MIN;
  for(int i=0;i<size;i++)
  {
      if(arr[i]>max)
        max=arr[i];
  }
return max;
}
void radix(vi &arr,int size)
{
    int max=get_max(arr,size);

    for(int place=1;(max/place)>0;place*=10)
        countsort(arr,size,place);

}

int main()
{
vi arr= {78,49,58,121,432,564,23,1,45,788};

radix(arr,arr.size());

cout<<"array after sorting "<<endl;
for(int k=0;k<arr.size();k++)
    cout<<arr[k]<<" ";
 return 0;

}
