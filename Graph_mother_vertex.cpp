#include <iostream>
#include <cmath>
#include <cstdio>

#include <vector>
#include <array>
#include <queue>
#include <list>
#include<stack>
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

using namespace std;
class Graph
{
    int V;
   lli *adj;
void DFS(int source,bool_v &visited);


public:
Graph(int V);
void add_Edge(int u, int v);
int mother_vertex();
} ;

Graph::Graph(int V)
{   this->V=V;
    adj = new lli[V];
}
void Graph :: add_Edge(int u,int v)
{    adj[u].pb(v);
}

 void Graph :: DFS(int source,bool_v &visited)
{    visited[source]=true;
        for(auto x: adj[source])
    {  if(!visited[x])
            DFS(x,visited);
    }
}

int Graph:: mother_vertex()
{
    bool_v visited(V,false);

    int last_node;

    fo(i,V)
    { if(!visited[i])
        {DFS(i,visited);
            last_node=i;
        }
    }


    fill_n(visited.begin(),V,false);
    DFS(last_node,visited);

    fo(i,V)
    {
        if(!visited[i])
            return -1;
    }

return last_node;
}

int main()
{
 Graph g(5);

g.add_Edge(0,2);
 g.add_Edge(0,3);
   g.add_Edge(1,0);
     g.add_Edge(2,1);
       g.add_Edge(3,4);



       cout<< "mother vertex of the graph g is "<< g.mother_vertex()<<endl;

return 0;
}
