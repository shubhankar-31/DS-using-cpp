#include <iostream>
#include <cmath>
#include <cstdio>

#include <vector>
#include <array>
#include <queue>
#include <list>
#include <stack>

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
#define  space cout<<"\n\n\n\n";
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

 void Graph::DFS(int source)
{
    vector<bool> visited(V,false);
    visited[source]=true;

   stack<int> s;
   s.push(source);

   while(!s.empty())
   { cout<<s.top() <<" ";

   int temp=s.top();
   s.pop();

 for(auto x: adj[temp])
 {  if(!visited[x])
     {   visited[x]=true;
         s.push(x);
     }
 }

}

}

int main()
{Graph graph_1(4);
    graph_1.add_Edge(0, 1);
    graph_1.add_Edge(0, 2);
    graph_1.add_Edge(1, 2);
    graph_1.add_Edge(2, 0);
    graph_1.add_Edge(2, 3);
    graph_1.add_Edge(3, 3);

cout<< "BFS starting from nodes 0->1->2->3"<<endl<<endl;
        graph_1.DFS(0);space;
         graph_1.DFS(1);space;
        graph_1.DFS(2);space;
        graph_1.DFS(3);

return 0;
}
