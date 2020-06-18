#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
//stable....in-place
using namespace std;
void selection (vector<int> &arr)
{
    int min_index;
    for(int i=0;i<arr.size()-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<arr.size();j++)
        {
             if(arr[min_index]>arr[j])
               min_index=j;
        }
        int key =arr[min_index];
        while(min_index>i)
        {
            arr[min_index]=arr[min_index-1];
            min_index--;
        }
        arr[i]=key;
    }
}
int main()
{

vector<int> arr={4,3,2,1,7,578,45,3,4,998,112,34,76};
//int n=sizeof(arr)/sizeof(int);
selection(arr);
for(int k=0;k<arr.size();k++)
    cout<< arr[k]<<" ";
 return 0;

}
