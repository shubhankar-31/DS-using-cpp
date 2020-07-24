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
#define pb(x) push_back(x)
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


void add_Edge(lli adj[],int u,int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);

}
void print_graph(lli adj[],int v)
{
    fo(i,v)
    {
        cout<<"Adjacency list of vertex "<<i ;

        for(auto x: adj[i])
            cout<<" -->" <<  x;

        space;
    }
}

int main()
{
    int V=5;
   lli *adj=new lli[V];


    add_Edge(adj,0,1);
    add_Edge(adj,0,4);
    add_Edge(adj,1,2);
    add_Edge(adj,1,3);
    add_Edge(adj,1,4);
    add_Edge(adj,2,3);
    add_Edge(adj,3,4);

    print_graph(adj,V);

return 0;
}
