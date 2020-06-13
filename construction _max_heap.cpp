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
    int largest = i; // Initialize largest as root
    int l = (2 * i) + 1;//left child index
    int r = (2 * i) + 2;//right child index

    // If left child is larger than root
    if (l< n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
       heapify(arr, n, largest);
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
void printHeap(vector<int> &arr, int &n)
{
    cout << "Array representation of Heap is:\n";

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
//delete function is working fine
void delete_root(vector<int> &arr, int &x)
{
    arr[0]=arr[x-1];
    arr.pop_back();


heapify(arr, x, 0);
}
void insertNode(vector<int> &arr, int &x, int key)
{
    // Increase the size of Heap by 1
    x++;
    // Insert the element at end of Heap which is a vector of int
       arr.push_back(key);

    //  heapify the new node following a
    // Bottom-up approach
    buildHeap(arr, x);
}

int main()
{

    vector<int> arr = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

     int n = arr.size();

    buildHeap(arr, n);
    printHeap(arr, n);
    space;
    cout<<arr.size()<<endl;
insertNode(arr,n,99);
 printHeap(arr, n);
    space;
    cout<<arr.size()<<endl;
    insertNode(arr,n,2);
 printHeap(arr, n);
    space;
    cout<<arr.size()<<endl;

    return 0;
}
