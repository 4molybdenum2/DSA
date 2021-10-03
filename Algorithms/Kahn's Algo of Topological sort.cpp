#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef int64_t ll;
#define pii pair<ll, ll>
#define pb push_back
 /*
 A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0. 
 Time Complexity: O(V+E). 
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
Auxiliary Space: O(V). 
The queue needs to store all the vertices of the graph. So the space required is O(V)
 */




const ll M = 1e9 + 7;
const ll INF = 1e6 + 10;

vector<ll> graph[INF];
ll parent[INF];
// Create a vector to store
    // indegrees of all
    // vertices. Initialize all
    // indegrees as 0
int indegree[INF];

void solve()
{
  int vertices, edges;
  cin>>vertices>>edges;
  for(int i=0;i<edges;i++)
  {
      int u,v;
      cin>>u>>v;
      graph[u].pb(v); // constructing graph
      indegree[v]++; //  counts the incomming edge from vertex u to vertex v
  }
  queue<int>q; // queue to push all nodes with indegree 0
  for(int node=1;node<=vertices; node++)
  {
      if(indegree[node]==0)
      {
             q.push(node);
      }
  }
 vector<int>TOPO_SORT;
while(!q.empty())
{
    int node =q.front();
    q.pop();
    TOPO_SORT.push_back(node); // adding node as to expect that topological sort exists
    for(auto child : graph[node])
    {
          indegree[child]--;
          if(indegree[child]==0) // this implies that all incoming edges from other nodes are over
                                 // this vertex has now 0 dependencies
          q.push(child);
    }

}

if(TOPO_SORT.size()<vertices) // if number of edges in toposort are less than total vertices which means that the graph has a cycle
{
    cout<<"IMPOSSIBLE"<<endl;
    return;
}
for(auto node: TOPO_SORT)
{
    cout<<node<<" ";
}
cout<<endl;return;
}
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
 
 solve();
    return 0;
}