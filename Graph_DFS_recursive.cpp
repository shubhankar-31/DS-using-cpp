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
#define si set<int>
#define usi unordered_set<int>
#define lli list<int>
#define vpii  vector< pair <int,int> >
#define pii pair <int,int>
#define space cout<<"\n\n\n\n";
#define ll (long long)


using namespace std;


class Graph
{
    int V;
   lli *adj;

public:
    Graph(int V);
    void add_Edge(int u, int v);
    void DFS(int source);
    void DFS_Until(int source,vector< bool> &visited);
} ;

Graph::Graph(int V)
{
    this->V=V;
    adj = new lli[V];
}
void Graph::add_Edge(int u, int v)
{
    adj[u].pb(v);//since this is a directed graph
}

 void Graph:: DFS_Until(int source,vector< bool> &visited)
 {
     visited[source]=true;
     cout<< source<<" ";

     for(auto x: adj[source])
     {  if(!visited[x])
        DFS_Until(x,visited);
     }
 }
 void Graph::DFS(int source)
{
    vector<bool> visited(V,false);
     DFS_Until(source,visited);

}
//the program is working as it should be
int main()
{Graph graph_1(4);
    graph_1.add_Edge(0, 1);
    graph_1.add_Edge(0, 2);
    graph_1.add_Edge(1, 2);
    graph_1.add_Edge(2, 0);
    graph_1.add_Edge(2, 3);
    graph_1.add_Edge(3, 3);

cout<< "DFS starting from nodes 0->1->2->3"<<endl<<endl;
        graph_1.DFS(0);space;
         graph_1.DFS(1);space;
        graph_1.DFS(2);space;
        graph_1.DFS(3);

return 0;
}
