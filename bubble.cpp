#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;

void bubbleSort(vector<int>&arr, int n)
{
     bool flag;

    for (int i = 0; i < n-1; i++)
{     flag=0;
     // Last i elements are already in place
    for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            swap(arr[j],arr[j+1]);
            flag=1;
        }
         if(!flag)
          break;
}
 }

void printArray(vector<int>&arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
     cout << arr[i] << " ";

}

// Driver code
int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90,54,48,77,2};
    int n = arr.size();

    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}
