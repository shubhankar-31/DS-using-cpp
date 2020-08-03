#include <iostream>
#include <cmath>
#include <cstdio>

#include <vector>
#include <array>
#include <queue>
#include <list>

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
#define bool_v vector<bool>
#define si set<int>
#include<stack>
#define usi unordered_set<int>
#define lli list<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define space cout<<"\n\n\n\n";
#define ll (long long)

#define bool_v vector<bool>
using namespace std;
class DisjointSet {
    int n;
    vi rank,parent;

public:
DisjointSet(int n)
    {  rank.resize(n);
        parent.resize(n);
        this->n = n;
        for (int i = 0; i < n; i++)
        {parent[i] = i;
         rank[i]=0;}
    }

//Path compression
//modification in find()
int find(int x)
    {   if (parent[x] != x) {
            // if x is not the parent of itself
        int result = find(parent[x]);
             parent[x]=result;
             return result;
        }

        else
        return parent[x];
    }
//Union by rank
void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }

        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }

        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main()
{
    DisjointSet obj(5);

    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);

    if (obj.find(4) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (obj.find(1) == obj.find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
         if (obj.find(4) == obj.find(2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
