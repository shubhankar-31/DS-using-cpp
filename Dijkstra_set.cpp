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


void Dijkstras(vpii adj[],int V,int source)
{
    set<pii> setds;

     vi distance(V,INF);

    setds.insert(mp(0,source));
    distance[source]=0;

    while(!setds.empty())
    { //copying the pair from the set that would be the first element
        pii temp_pair = *(setds.begin());
       //using the copied pair's second element
        int u=temp_pair.second;
        setds.erase(setds.begin());


        for(auto x: adj[u])
        {   int v=x.first;
            int weight=x.second;


             if(distance[v]> distance[u] + weight)
             {//If distance of v is not INF then it must be in
                    //our set, so removing it and inserting again
                    //with updated less distance.
                 if(distance[v]!=INF)
                 {auto y=setds.find(mp(distance[v],v));
                  setds.erase(*y);}

               //updating the weight for the vertex v
               distance[v]=distance[u]+weight;
               setds.insert(mp(weight,v));
             }
        }

          }

cout<<"Vertex \t Distances from the source  "<< source <<endl;
    for (int i = 0; i < V; ++i)
       cout<< i<<"\t\t"<<distance[i]<<endl;
space;

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


    Dijkstras(adj,V,0);
    //shortest path from all vertices to the other vertices in the graph
    #if 0
    fo(i,V)
   {Dijkstras(adj,V,i);
   space;}
#endif
    return 0;
}
