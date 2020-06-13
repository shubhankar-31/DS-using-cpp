#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
//checking weather the heap in min heap or not ??
using namespace std;
bool checking_heap(int arr[],int n)
{
    for(int i=0; i<=ceil((n-2)/2); i++)
{
       if(arr[i]>=arr[(2*i)+1])
       return false;

    if((2*i)+2<n&&arr[i]>=arr[(2*i)+2])
    return false;

}
return true;
}

int main()
{
int arr[]={1,3,6,5,9,8,17,19};
int n=sizeof(arr)/sizeof(int);


  checking_heap(arr,n)?cout<< "yess it's a heap ":cout<<"NO it's not a heap";

 return 0;
}
