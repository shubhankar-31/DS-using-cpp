#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
//my macros
#define pb(x) push_back(x);
#define fo(i,l) for(int i=0;i<l;i++)
#define vi vector<int>
#define si set<int>
#define usi unordered_set<int>
#define lli list<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define  space cout<<"\n\n\n\n";
#define ll (long long)

using namespace std;
int n = 8; // array size
int a[] = { 2, 3, 3, 5, 5, 5, 6, 6 }; // Sorted array

bool contains(int low, int high, int key)
{    bool ans = false;
    while (low <= high) {
        int mid = low + (high - low)/ 2;
        int midVal = a[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
              high = mid - 1;

        else if (midVal == key) {

            ans = true;
            break;
        }
    }

    return ans;
}

/* Find first occurrence index of key in array
 * Returns: an index in range [0, n-1] if key belongs
 *          to array, -1 if key doesn't belong to array
 */
int first(int low, int high, int key)
{
    int ans = -1;

    while (low <= high) {

        int mid = low + ((high - low + 1) / 2);
        int midVal = a[mid];

        if (midVal < key)
          low = mid + 1;

        else if (midVal > key)
              high = mid - 1;

        else if (midVal == key) {
            // if mid is equal to key, we note down
            //  the last found index then we search
            // for more in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int last(int low, int high, int key)
{
    int ans = -1;

    while (low <= high) {
        int mid = low + ((high - low + 1) / 2);
        int midVal = a[mid];

        if (midVal < key)
            low = mid + 1;

        else if (midVal > key)
            high = mid - 1;

        else if (midVal == key) {
            // if mid is equal to key, we note down
            // the last found index then we search
            // for more in right side of mid
            // so we now search in [mid + 1, high]
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}


int leastgreater(int low, int high, int key)
{
    int ans = -1;

    while (low <= high) {
        int mid = low + ((high - low + 1) / 2);
        int midVal = a[mid];

        if (midVal < key) {

            // if mid is less than key, all elements
            // in range [low, mid - 1] are <= key
            // then we search in right side of mid
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > key) {

            // if mid is greater than key, all elements
            // in range [mid + 1, high] are >= key
            // we note down the last found index, then
            // we search in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
        else if (midVal == key) {

            // if mid is equal to key, all elements in
            // range [low, mid] are <= key
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
    }

    return ans;
}


int greatestlesser(int low, int high, int key)
{
    int ans = -1;

    while (low <= high) {
        int mid = low + ((high - low + 1) / 2);
        int midVal = a[mid];

        if (midVal < key) {

            // if mid is less than key, all elements
            // in range [low, mid - 1] are < key
            // we note down the last found index, then
            // we search in right side of mid
            // so we now search in [mid + 1, high]
            ans = mid;
            low = mid + 1;
        }
        else if (midVal > key) {

            // if mid is greater than key, all elements
            // in range [mid + 1, high] are > key
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
        else if (midVal == key) {

            // if mid is equal to key, all elements
            // in range [mid + 1, high] are >= key
            // then we search in left side of mid
            // so we now search in [low, mid - 1]
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{


    printf("Contains\n");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, contains(0, n - 1, i));

    printf("First occurrence of key\n");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, first(0, n - 1, i));

    printf("Last occurrence of key\n");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, last(0, n - 1, i));

    printf("Least integer greater than key\n");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, leastgreater(0, n - 1, i));

    printf("Greatest integer lesser than key\n");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, greatestlesser(0, n - 1, i));

    return 0;
}
