#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


#define pb(x) push_back(x);
#define fo(i,l) for(int i=0;i<l;i++)
#define vi vector<int>
#define si set<int>
#define usi unordered_set<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define  space cout<<"\n\n\n\n";

using namespace std;

//understanding  set
int main()
{
    vi arr1={11, 1, 13, 21, 3, 7};
    vi arr2={11, 3, 7, 1};

 si test;

for(auto i :arr1)
    test.insert(i);
for(auto i :arr2)
    test.insert(i);


    usi test1;
    for(auto i :arr1)
    test1.insert(i);
for(auto i :arr2)
    test1.insert(i);


    multiset<int> test2;
 for(auto i :arr1)
    test2.insert(i);
for(auto i :arr2)
    test2.insert(i);

    unordered_multiset<int> test3;
 for(auto i :arr1)
    test3.insert(i);
for(auto i :arr2)
    test3.insert(i);




    cout<< " printing elements of set "<<endl;
       for(auto i : test)
        cout<< i<<"   ";
       space;
cout<< " printing elements of unordered_set "<<endl;
       for(auto i : test1)
        cout<< i<<"   ";
       space;
cout<< " printing elements of multiset "<<endl;
       for(auto i : test2)
        cout<< i<<"   ";
       space;
cout<< " printing elements of unordered_multiset "<<endl;
       for(auto i : test3)
        cout<< i<<"   ";
       space;

 return 0;

}
