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
#include<list>


#define pb(x) push_back(x);
#define fo(i,l) for(int i=0;i<l;i++)
#define vi vector<int>
#define si set<int>
#define usi unordered_set<int>
#define lli list<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define  space cout<<"\n\n\n\n";

using namespace std;
 //List1: 10->15->4->20
  // lsit2:  8->4->2->10


  void intersection_of_LL(si &main_set,lli &list2)
  { cout<< "intersection of list 1 and list 2 is";
      lli result;
      for(auto i: list2)
     {
        if( main_set.count(i))
            result.pb(i);
     }
       for(auto i : result)
      cout<< i <<" ";

      space;
  }


void union_of_LL(si &main_set, lli &list2)
  {
      cout<< "intersection of list 1 and list 2 is";

      for(auto i: list2)
      main_set.insert(i);

    for(auto i : main_set)
    cout<< i <<" ";



  }
int main()
{
  list<int> list1={10,15,4,20};
  list<int>list2={8,4,2,10};


  si main_set;
     for(auto i: list1)
      main_set.insert(i);

    intersection_of_LL(main_set,list2);
      union_of_LL(main_set,list2);
 return 0;

}
