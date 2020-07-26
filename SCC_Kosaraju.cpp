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
void DFS_2(int source,bool_v &visited);
void DFS_1(int source,bool_v &visited,stack<int> &s);

public:

Graph(int V);
void add_Edge(int u, int v);
Graph transpose();
void print_SSC();
} ;

Graph::Graph(int V)
{   this->V=V;
    adj = new lli[V];
}
void Graph :: add_Edge(int u,int v)
{    adj[u].pb(v);
}

Graph Graph :: transpose()
{    Graph g(V);

   fo(i,V)
   {
       for(auto x: adj[i])
        g.adj[x].push_back(i);
   }
   return g;
}
void Graph:: DFS_1(int source,bool_v &visited,stack<int> &s)
{    visited[source]=true;
    for(auto x: adj[source])
        if(!visited[x])
          DFS_1(x,visited,s);

    s.push(source);
}
 void Graph :: DFS_2(int source,bool_v &visited)
{    visited[source]=true;
    cout<< source<< " ";
    for(auto x: adj[source])
    {  if(!visited[x])
            DFS_2(x,visited);
    }
}
void Graph:: print_SSC()
{    stack<int> s;
    bool_v visited(V,false);
//step 1

    fo(i,V)
    {  if(!visited[i])
        DFS_1(i,visited,s);
    }
    //step 2
    Graph adj2=transpose();
//step 3
    fo(i,V)
      visited[i]=false;
     while(!s.empty())
     { int temp =s.top();
         s.pop();

         if(!visited[temp])
         {adj2.DFS_2(temp,visited);
         space;
         }
     }
}
int main()
{
 Graph g(5);

g.add_Edge(0,2);
 g.add_Edge(0,3);
   g.add_Edge(1,0);
     g.add_Edge(2,1);
       g.add_Edge(3,4);

       cout<< "SSC of the graph g"<<endl;
       g.print_SSC();

return 0;
}
