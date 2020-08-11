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
#define mp(x,y) make_pair(x,y)
#define INF 0x3f3f3f3f
#define bool_v vector<bool>
using namespace std;

#define V 4


void display(int final_matrix[V][V])
{
cout<<" Following matrix shows the shortest distance from each vertex";space;
     for(int i=0;i<V;i++)
       {
         for(int j=0;j<V;j++)
          {
              if(final_matrix[i][j]==INF)
                cout<<"INFINITY"<<"  ";
                else
                 cout<< final_matrix[i][j]<<"  ";
          }
          cout<< endl;
       }
}
void Floyd_Warshall(int matrix[V][V])
{
    int final_matrix[V][V];

//simply copies the content from the original matrix
    for(int i=0;i<V;i++)
       for(int j=0;j<V;j++)
         final_matrix[i][j]=matrix[i][j];


for(int k=0;k<V;k++)
{
   for(int i=0;i<V;i++)
    {
      for(int j=0;j<V;j++)
        {
            if(final_matrix[i][j]>final_matrix[i][k]+final_matrix[k][j])
                final_matrix[i][j]=final_matrix[i][k]+final_matrix[k][j];
        }

    }


}

 display(final_matrix);
}


int main()
{
    int matrix[V][V]={ {0,3,INF,7},
                       {8,0,2,INF},
                       {5,INF,0,1},
                       {2,INF,INF,0}};


Floyd_Warshall(matrix);

   return 0;

}

