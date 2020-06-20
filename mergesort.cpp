#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;
void merge(int arr[],int firstindex,int middle,int lastindex)
{
//now we have to create a temp array to store the array elements
//and then we have to calculate the max element it can store

int leftlimit=(middle - firstindex)+1;
int rightlimit=(lastindex - middle);

int l_array[leftlimit];
int r_array[rightlimit];

//first coping element form the array to left sub array
for(int i=0;i<leftlimit;i++)
    l_array[i]=arr[firstindex+i];
//second coping element form the array to right sub array
for(int j=0;j<rightlimit;j++)
    r_array[j]=arr[middle+1+j];


    int x=0;
    int y=0;
    int z=firstindex;

    //comparing the left and right subarray
    while(x<leftlimit&&y<rightlimit)
    {
        if(l_array[x]<r_array[y])
        {
           arr[z]=l_array[x];
           x++;
        }
        else{
            arr[z]=r_array[y];
            y++;
        }
        z++;
    }

while(x<leftlimit)
{
    arr[z]=l_array[x];
    x++;z++;
}
while(y<rightlimit)
{
    arr[z]=r_array[y];
    y++;z++;
}
}
void mergesort(int arr[],int firstindex,int lastindex)
{

    if(firstindex<lastindex)
    {
         //to avoid overflow
         //we could also use L+R/2
        int middle=(firstindex+lastindex)/2;

        //these two recursive function call are going to
        //divide the array into sub array
        mergesort(arr,firstindex,middle);
         mergesort(arr,middle+1,lastindex);


         merge(arr,firstindex,middle,lastindex);
    }
}
int main()
{
 int arr[]={6,1};
 int n=sizeof(arr)/sizeof(int);
 mergesort(arr,0,n-1);

 for(int k=0;k<n;k++)
    cout<<arr[k]<<" ";

 return 0;

}
