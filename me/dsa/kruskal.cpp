#include <bits/stdc++.h>
using namespace std;

/* kruskal's algorithm for MST implementation (Using DS-data structure)
	Steps:
	1. Sort all the edges according to their weight
	2. traverse the edges and if they are not in the same set then add them to the MST
*/

struct node {
	int u;
	int v;
	int wt;
	node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
	if(a.wt < b.wt) {
		return true;
	}
	return false;
}

int findParent(int x, vector<int>& parent) {
	if(x == parent[x]) return x;
	return parent[x] = findParent(parent[x], parent);
}

// join two trees acc to the rank values of their parent
void union_(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}

int main() {
	// input all the edges
	int n,m;
	cin >> n >> m;
	vector<node> edge;
	for(int i=0; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edge.push_back(node(u,v,w));
	}
	sort(edge.begin(), edge.end(), comp);
	
	// creating the parent and rank arrays
	vector<int> parent(m);
	vector<int> rank(m);
	for(int i=0; i<m; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	
	vector<pair<int,int>> mst;
	int cost = 0;
	for(auto it: edge) {
		if(findParent(it.u, parent) != findParent(it.v, parent)) {
			cost += it.wt;
			mst.push_back({it.v, it.u});
			union_(it.u, it.v, parent, rank);
		}
	}
	
	cout << cost << endl;
	for(auto it : mst) cout << it.first << " - " << it.second << endl; 
	return 0;
}