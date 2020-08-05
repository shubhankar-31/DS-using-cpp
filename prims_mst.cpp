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
#define INF 0x3f3f3f3f // 1061109567
using namespace std;
void addEdge(vpii adj[],int u,int v,int weight)
{
    adj[u].push_back(mp(v,weight));
    adj[v].push_back(mp(u,weight));
}


void Prims_MST(vpii adj[],int V)
{
    priority_queue<pii,vpii,greater<pii>> pq;

    int source=0;
    vi key(V,INF);
    vi parent(V,0);
    bool_v inMST(V,false);

    pq.push(mp(0,source));
    key[source]=0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        inMST[u]=true;

        for(auto x: adj[u])
        {   int v=x.first;
            int weight=x.second;

            if(inMST[v]==false && key[v]>weight)
            {
                key[v]=weight;
                pq.push(mp(key[v],v));
                parent[v]=u;
            }

        }

    }

cout<<" MST edges are ";space;
    for (int i = 1; i < V; ++i)
       cout<< parent[i]<<" ---"<<i<<endl;
space;
 int min_weight=0;
       fo(i,key.size())
            min_weight+=key[i];


       cout<< " minimum weight is equal to -->> " <<min_weight;
}
int main()
{

int V = 9;
    vpii adj[V];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

Prims_MST(adj,V);

    return 0;
}
