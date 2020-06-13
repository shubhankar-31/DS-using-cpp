#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#define  space cout<<"\n\n\n\n";
using namespace std;
void heapify(vector<int> &arr, int n, int i)
{
    int minimum = i; // Initialize minimum as root
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;


    if (l< n && arr[l] < arr[minimum])
        minimum = l;


    if (r < n && arr[r] < arr[minimum])
        minimum = r;

    // If minimum is not root
    if (minimum != i) {
        swap(arr[i], arr[minimum]);
        // Recursively heapify the affected sub-tree
       heapify(arr, n, minimum);
    }
}

// Function to build a Max-Heap from the given array
void buildHeap(vector<int> &arr, int n)
{
    // Index of last non-leaf node
    int startIdx = (n -2)/2;

    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
//this is also a level order traversal(original)
void printHeap(vector<int> &arr, int n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void delete_root(vector<int> &arr, int &x)
{
    arr[0]=arr[x-1];
    x--;

heapify(arr, x, 0);
}
int main()
{

    vector<int> arr = { 7,2,9,6,4,3,1 };
     int n = arr.size();

    buildHeap(arr, n);

    printHeap(arr, n);
delete_root(arr,n);
printHeap(arr, n);
    return 0;
}
