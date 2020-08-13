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

class Graph
{
int V;
lli *adj;
void APU_util(int source,bool_v &visited,vi &discovery,vi &low,vi &parent,bool_v &ap);

  public:
      Graph(int V)
      {
          this->V=V;
          adj=new lli[V];
      }
      void AP();
      void addEdge(int u,int v)
      {
          adj[u].push_back(v);
          adj[v].push_back(u);
      }


};

void Graph::AP()
{
 bool_v visited(V,false),ap(V,false);
vi parent(V,-1);

 vi discovery,low;
 discovery.resize(V);
 low.resize(V);

// step 1 -->> DFS
 for(int i=0;i<V;i++)
    if(!visited[i])
     APU_util(i,visited,discovery,low,parent,ap);


     for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";

}
void Graph:: APU_util(int source,bool_v &visited,vi &discovery,vi &low,vi &parent,bool_v &ap)
{
static int time=0;
int children=0;
visited[source]=true;
discovery[source]=low[source]= ++time;

for(auto x: adj[source])
{
    if(!visited[x])
    {
        children++;
        parent[x]=source;
        APU_util(x,visited,discovery,low,parent,ap);

        low[source]=min(low[x],low[source]);

        if(parent[source]== -1&&children>1)
            ap[source]=true;

        if(parent[source]!= -1&&low[x]>= discovery[source])
            ap[source]=true;
    }

    else if(x!=parent[source])
         low[source]=min(low[source],discovery[x]);
   }
}
int main()
{
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
    return 0;
}
