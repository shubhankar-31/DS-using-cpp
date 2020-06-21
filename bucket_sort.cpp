#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#define  space cout<<"\n\n\n\n";
using namespace std;

void bucketsort(float arr[],int n)
{
    vector<float>bucket[n];
    int weird_index;

    for(int i=0;i<n;i++)
    {
        weird_index=int(n*arr[i]);
        bucket[weird_index].push_back(arr[i]);
    }

    for(int i=0;i<n;i++)
        sort(bucket[i].begin(),bucket[i].end());

      static int x=0;
      for(int i=0;i<n;i++)
      {
          while(!bucket[i].empty())
          {
              arr[x++]=*(bucket[i].begin());
              bucket[i].erase(bucket[i].begin());

          }
      }
}
int main()
{
float arr[]={0.897,0.565,0.656,0.1234,0.665,0.3434,0.254};
int n =sizeof(arr)/sizeof(float);

bucketsort(arr,n);

 for(int i= 0; i<n; i++)
      cout << arr[i] << "   ";


 return 0;

}
