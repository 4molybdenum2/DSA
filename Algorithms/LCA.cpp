#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef int64_t ll;
#define pii pair<ll, ll>
#define pb push_back
const int INF = 2e5 + 1;
// macros
/*

Time Complexity: The time taken in pre-processing is O(NlogN) and every query takes O(logN) time. 
So the overall time complexity of the solution is O(NlogN).
Auxiliary Space: O(NlogN) 

*/

vector<ll> graph[INF]; // simple adjacency list
ll level[INF];         // Array to store level of each node from root
int jump[21][INF];     // storing 2 to power i th parent in 2d matrix to make jumps

// trivial depth first search algo to store level of the nodes

void dfs(int node, int parent, int l)
{
    jump[0][node] = parent; //  storing the first parent that is 2 ^0 th parent

    level[node] = l; // storing level of the node
    for (auto it : graph[node])
    {
        if (it != parent)
            dfs(it, node, l + 1);
    }
}

// By using Dynamic programming we can store 2^i th parent of a node

void finding_exponential_parent(int n)
{
    dfs(1, -1, 0);

    for (int ith_parent = 1; 1 << ith_parent <= n; ith_parent++)
    {
        for (int node = 0; node <= n; node++)
        {
            jump[ith_parent][node] = jump[ith_parent - 1][jump[ith_parent - 1][node]];
        }
    }
}

//Here we will perform binary lifiting using the above computed parent matrix
// Binary lifting is a technique to bring two nodes on the same level and then computing the
// Least common ancestor
int LCA(int p, int q)
{
    if (level[p] < level[q])
        swap(p, q);                 // we make sure that node p is always at lower depth
    int diff = level[p] - level[q]; //  we calculate how much difference is to  be jumped to push them both at the same level

    // any number can be represented in binary which always indicates sum of powers of two
    // here diff can be represent as sum of powers of two
    // for example let diff= 13 = 1101 which means we need a jump of 8 ,4, 1

    for (int i = 0; i <= 20; i++)
    {
        if (diff & (1 << i)) // If the i th bit is set in diff we make a jump of 2^i
        {
            p = jump[i][p];
        }
    }
    if (q == p) // this is  a critical if the LCA of the nodes is of the node itself
    {
        return p;
    }

    for (int i = 20; i >= 0; i--) //The main idea here is to try a huge jump at first. If doing a huge jump on both pointers leads them to the same node, then we have arrived at a common ancestor. However, we may have jumped too far.
    {
        if (jump[i][p] != jump[i][q])
        {
            p = jump[i][p];
            q = jump[i][q];
        }

        /*
   There could be some deeper common ancestor. So we can’t do this jump, we will try something smaller.
If the current jump leads them to different nodes, then we should do this jump and update the pointers. 
This basically means that we made the largest possible jump that doesn’t reach any common ancestor yet. 
Therefore, the parent of both pointers will be the deepest common ancestor, which is the LCA. During this step, we also consider log(n) different jumps, so the complexity is also O(log(n)).
   */
    }
    return jump[0][p];
}

void solve()
{
    int n,q; // n-> Vertices q-> queries
    cin >> n>>q;
    //making
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a); // making a graph
    }
    finding_exponential_parent(n);
   while(q--) {
	int u, v;
    cin >> u >> v;
    cout << LCA(u,v)<< endl;
	}
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