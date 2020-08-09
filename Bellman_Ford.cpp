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
#define mp(x,y) make_pair(x,y)
#define INF 0x3f3f3f3f
#define bool_v vector<bool>
using namespace std;


void addEdge(vpii adj[],int u,int v,int weight)
{
    adj[u].push_back(mp(v,weight));
}

void Bellman_Ford(vpii adj[],int source,int V)
{

vi distance(V,INF);

distance[source]=0;

      for(int i=0;i<V;i++)
      { for(auto x: adj[i])
          {   int v=x.first;
              int weight=x.second;

              if(distance[i]!=INF&&distance[v]>distance[i]+weight)
                distance[v]=distance[i]+weight;
          }
      }
      //this loop check for negative-weight cycles.  The above step
    // guarantees shortest distances if graph does not contain
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
      for(int i=1;i<V;i++)
      { for(auto x: adj[i])
          {   int v=x.first;
              int weight=x.second;

              if(distance[i]!=INF&&distance[v]>distance[i]+weight)
               {  cout<<" Negative cycle in the graph can't process the graph";
                   return;
               }
          }
      }

cout<<"Vertex\t\t"<<" Distance from the source"<<endl;
     fo(i,distance.size())
     cout<< i<<"\t\t\t" <<distance[i]<<endl;

}

int main()
{
    int V=5;

    vpii adj[V];

    addEdge(adj,0,1,-1);
     addEdge(adj,0,2,4);
      addEdge(adj,1,2,3);
      addEdge(adj,1,3,2);
       addEdge(adj,1,4,2);
       addEdge(adj,3,1,1);
        addEdge(adj,3,2,5);
          addEdge(adj,4,3,-3);

Bellman_Ford(adj,0,V);
    return 0;
}

