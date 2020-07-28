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

// this program checks for cycle in the directed graph
class Graph {
  int V;
  list<int> *adj;
bool isCyclicUtil(int v, bool_v &visited, bool_v &recStack);
   public:
  Graph(int V);
  void addEdge(int s, int d);
  bool isCyclic();
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int s, int d) {
  adj[s].push_back(d);
}

bool Graph:: isCyclicUtil(int v, bool_v &visited, bool_v &recStack)
{    if(!visited[v])
    {   visited[v]=true;
        recStack[v]=true;
        for(auto x: adj[v])
        {  if(!visited[x]&&isCyclicUtil(x,visited,recStack))
                return true;
            else if(recStack[x]==true)
               return true;
        }

    }

recStack[v]=false;
return false;
}

bool Graph:: isCyclic()
{
    bool_v visited(V,false);
    bool_v recStack(V,false);
    fo(i,V)
     if(isCyclicUtil(i,visited,recStack))
         return true;
    return false;
}
int main() {
  Graph g(5);
  g.addEdge(0, 2);
   g.addEdge(0, 3);
    g.addEdge(1,0);
     g.addEdge(2, 1);
      g.addEdge(3, 4);

  if(g.isCyclic())
    cout<< " cycle found ";
  else
    cout<< " cycle not found";

return 0;
}
