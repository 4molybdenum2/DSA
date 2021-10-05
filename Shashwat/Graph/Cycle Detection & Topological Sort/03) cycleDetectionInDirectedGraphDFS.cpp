// "DIRECTED GRAPH"

// 1 →  2 →  3 → 4 
// 	 ↑    ↓   ↓    
//      7    6 → 5      
//    ↙  ↖
//   8  →  9

// Adjacency List
// 1 → 2
// 2 → 3
// 3 → 4, 6
// 4 → 5
// 5 →
// 6 → 5
// 7 → 2 8
// 8 → 9
// 9 → 7

// In directed we use 2 arrays to keep track of visited nodes
vis[]
dfsVis[]

class Solution{
private:
	bool checkCycle(int node, vector<int>adj[], int vis[], int dfsVis[]){
		vis[node] = 1;                                               // on visiting we mark that node as 1 in vis array
		dfsVis[node] = 1;                                            // also we mark it as 1 in dfsVis array
		for(auto it : adj[node]){                                    // then we look for the adjacent node
			if(!vis[it]){                                            // if that adjacent node has not been visited
				if(checkCycle(it, adj, vis, dfsVis)) return true;    // recursive dfs calls, return true if inner dfs call is true
			}
			else if(dfsVis[it]){                                     // adjacent node has been visited & dfsVis node is also visited then it is a cycle
				return true;
			}
		}
		dfsVis[node] = 0;                                            // any adjacent node didnt return true ie there is no cycle for this recursive call, and we mark dfsVis as 0
		return false;												 // and return false
	}

public:
	bool isCyclic(int N, vector<int>adj[]){           // taking no of nodes and adjacency list
		int vis[N], dfsVis[N];                        // declaring two arrays              
		memset(vis, 0, sizeof(vis));                  // assign 0's to both of the arrays
		memset(dfsVis, 0, sizeof(dfsVis));

		for(int i = 0; i < N; i++){                   // iterating for every node
			if(!vis[i]){                              // if it has not been visited

				if(checkCycle(i, adj, vis, dfsVis)){  // we call the check cycle func, if in any call it returns true then it is cyclic
					return true;
				}
			}
		}
		return false;
	}
};


