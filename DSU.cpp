# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

vector<int> parent;
vector<int> set_size;

void make_set(int a) {
	parent[a] = a;
	set_size[a] = 1;
}

int get_parent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = get_parent(parent[a]); // Path compression
}

void set_union(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) return; // Be very careful with this!

	if (set_size[a] < set_size[b]) swap(a, b);
	set_size[a] += set_size[b];
	parent[b] = a;
}

int main() 
{
	IOS;
	int n, m; cin >> n >> m;

	parent.resize(n); set_size.resize(n);
	for (int i = 0; i < n; i++) make_set(n);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		set_union(a, b);
	}
	return 0;
}