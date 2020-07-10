#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <list>
#include <algorithm>
#include <functional>
#include <utility>

#define pb(x) push_back(x);
#define fo(i,l) for(int i=0;i<l;i++)
#define vi vector<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define  space cout<<"\n\n\n\n";
using namespace std;

class Hash
{
    int bucket;    // No. of buckets
    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int b);
    void insertItem(int x);
    void deleteItem(int key);

    int hashFunction(int x) {

        return (x%bucket);
    }

    void displayHash();
};

Hash::Hash(int no_of_bucket)
{   bucket = no_of_bucket;
    table = new list<int>[bucket];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].pb(key);
}

void Hash::deleteItem(int key)
{  int index = hashFunction(key);
   list <int> :: iterator i;

  for ( i = table[index].begin();i!= table[index].end(); i++) {
    if (*i == key)//*i means pointing to the element(actual value)
      break;
  }
  // if key is found in hash table, remove it
  if (i != table[index].end())
    table[index].erase(i);
}

void Hash::displayHash() {

  fo(i,bucket) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;

    cout << endl;
  }
}
int main()
{

  vi arr = {50, 700, 76, 85, 92, 73, 101};
  Hash new_hash_table(7);   // 7 is count of buckets in hash table
  for (int i = 0; i < arr.size(); i++)
     new_hash_table.insertItem(arr[i]);

    new_hash_table.displayHash();
    space;
    new_hash_table.deleteItem(92);
    new_hash_table.displayHash();

  return 0;
}
