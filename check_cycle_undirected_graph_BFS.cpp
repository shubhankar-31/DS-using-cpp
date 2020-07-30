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

#define bool_v vector<bool>
using namespace std;
void addEdge(lli adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicConntected(lli adj[],int source,bool_v &visited, int V )
{
vi parent(V,-1);

queue<int> q;

visited[source]=true;
q.push(source);

while(!q.empty())
{
    int temp=q.front();
    q.pop();

    for(auto x :adj[temp])
    {
          if(!visited[x])
            { visited[x]=true;
              q.push(x);
              parent[x]=temp;
            }
           else if (parent[temp]!=x)
                 return true;
    }
}

return false;
}
  bool isCyclicDisconntected(lli adj[], int V)
  {
      bool_v visited(V,false);

      fo(i,V)
      {
          if(!visited[i])
          {
              if(isCyclicConntected(adj,i,visited,V))
                return true;
          }
      }
      return false;
  }

int main()
{
    int V=4;
     lli adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    if (isCyclicDisconntected(adj, V))
        cout << "Yes";
    else
        cout << "No";

return 0;
}
