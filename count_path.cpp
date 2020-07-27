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



using namespace std;

class Graph {

    int V;
    lli* adj;

    // A recursive function
    // used by countPaths()
    void countPathsUtil(int start_node, int target_node,int &pathCount);

public:
    // Constructor
    Graph(int V);
    void addEdge(int u, int v);
    int countPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new lli[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

// Returns count of paths from 's' to 'd'
int Graph::countPaths(int s, int d)
{
     int pathCount = 0;
    countPathsUtil(s, d, pathCount);
    return pathCount;
}


void Graph::countPathsUtil(int start_node, int target_node,int &pathCount)
{
       if (start_node == target_node)
        pathCount++;


    else {  for(auto x: adj[start_node])
         countPathsUtil(x, target_node, pathCount);
            }


}

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int s = 0, d = 3;
    cout << g.countPaths(s, d);

    return 0;
}
