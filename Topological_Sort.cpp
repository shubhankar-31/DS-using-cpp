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
class Graph
{

    int V;

    list<int> *adj;

    void topologicalSortUtil(int v, bool_v &visited,lli &topo_sort);
public:

    Graph(int V);
    void addEdge(int v, int w);
     void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{

    adj[v].push_back(w);
}


void Graph::topologicalSortUtil(int v, bool_v &visited,lli &topo_sort)
{
    visited[v] = true;

   for(auto x: adj[v])
        if (!visited[x])
            topologicalSortUtil(x, visited, topo_sort);
   topo_sort.push_front(v);
}


void Graph::topologicalSort()
{
   lli topo_sort;// using linked list instead of a stack


  bool_v visited(V,false);

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, topo_sort);

        for(auto x: topo_sort)
            cout<< x << " ";
}


int main()
{
     Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}

