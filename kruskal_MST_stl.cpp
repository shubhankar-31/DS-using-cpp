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
#define usi unordered_set<int>
#define lli list<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define  space cout<<"\n\n\n\n";
#define ll (long long)
#define mp(x,y) make_pair(x,y)
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
int find(int x)
    {   if (parent[x] != x) {
           int result = find(parent[x]);
             parent[x]=result;
             return result;
        }
        else
        return parent[x];
    }
void Union(int x, int y)
    {   int xset = find(x);
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

class Graph
{int V,E;

 vector< pair<int, pii>> weight_edges_pair;
public:
    Graph(int V,int E)
    {  this->V=V;
      this->E=E;
    }

    void addEdge(int u,int v,int weight)
    {
        weight_edges_pair.push_back(mp(weight,mp(u,v)));
    }

    int Mst_kruskal();
};

int Graph::Mst_kruskal()
{
    int minimum_weight=0;
    sort(weight_edges_pair.begin(),weight_edges_pair.end());
// the disjoint set is basically going to prevent us from using
//any edges which can create a cycle in the new graph
//while we are selecting the minimum weight edges from the original graph g.
    DisjointSet set1(V);
cout<< " MST edges are"<<endl<<endl;
    for(auto x: weight_edges_pair)
    {
        int u= x.second.first;
        int v= x.second.second;

        int set_u=set1.find(u);
        int set_v=set1.find(v);


       if(set_u!=set_v)
       {
           cout<< u << " --- " << v<<endl;
            minimum_weight+=x.first;
            set1.Union(set_u,set_v);
       }
    }

    return minimum_weight;
}

int main()
{
int vertices=9,edges=14;
Graph g(vertices,edges);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int mst_wgt=g.Mst_kruskal();
space;
    cout<<" minimum weight of the mst graph is "<<mst_wgt;
return 0;
}
