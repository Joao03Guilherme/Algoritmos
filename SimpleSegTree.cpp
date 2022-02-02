#include <bits/stdc++.h>
using namespace std;

vector<int> segTree;
int n;

int query(int node, int node_low, int node_high, int query_low, int query_high) {
	if (node_low >= query_low && node_high <= query_high) return segTree[node];
	if (node_low > query_high) return 0;
	if (node_high < query_low) return 0;
	
	int mid = (node_low + node_high) / 2;
	return query(node*2, node_low, mid, query_low, query_high) + 
			query(node*2 + 1, mid + 1, node_high, query_low, query_high);
}

void update(int node, int val) {
	node += n; // Index in segment tree
	segTree[node] = val;
	for (int i = node/2; i >= 1; i /= 2) {
		segTree[i] = segTree[i*2] + segTree[i*2 + 1];
	}
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5}; // Example vector

	int n = v.size();
	while (__builtin_popcount(n) != 1) { 
		n++; v.push_back(0);
	}

	segTree.resize(2*n);
	for (int i = 0; i < n; i++) {
		segTree[n+i] = v[i];
	}

	for (int i = n-1; i > 0; i--) {
		segTree[i] = segTree[i*2] + segTree[i*2 + 1];
	}

	// Driver code
	cout << query(1, 0, n, 0, 3) << "\n";
}
