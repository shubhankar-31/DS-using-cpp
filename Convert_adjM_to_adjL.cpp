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

vector<vi> convert( vector<vi> a)
{
    vector<vi> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}
int main()
{
    vector<vi> a;
    vi p={{0, 0, 1}};
    vi q={{0, 0, 1}};
    vi r={{1, 1, 0}}; // adjacency matrix
    a.push_back(p);
    a.push_back(q);
    a.push_back(r);

    vector<vi> AdjList = convert(a);

    cout<<"Adjacency List:"<<endl;
    // print the adjacency list

    fo(i,AdjList.size())
    {
        cout<< i<<" ->> ";
        for ( auto x: AdjList[i])
            cout<< x <<"    ";

        space;
    }



    #if 0
    for (int i = 0; i < AdjList.size(); i++)
    {
        cout << i;
        for(int j = 0; j < AdjList[i].size(); j++)
        { if(j == AdjList[i].size() - 1)
            { cout << " -> " << AdjList[i][j] << endl;
                break;
            }
            else
                cout << " -> " << AdjList[i][j];
        }
    }

    #endif
    return 0;
}
