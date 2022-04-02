# include <bits/stdc++.h>
# define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
# define pb push_back
using namespace std;
using ll = long long int;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1000000009;
const long long INFLL = (ll)INF * (ll)INF;

const int MX = 100'005;
const int LOG = 17;
int m[MX][LOG]; // m[i][j] representa o mínimo no intervalo [i, i+2^j-1] 

int query(int l, int r) {
	int len = r - l + 1;
	int log_len = floor(log2(len));
	return min(m[l][log_len], m[r - (1<<log_len) + 1][log_len]); // Dividir em dois overlapping intervals
}

int main() 
{
	IOS;

	// 1) Ler input 
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i][0]; // Intervalos de comprimento 2^0 = 1
	}

	// 2) Pré processamento em O(N*log(N))
	for (int k = 1; k < LOG; k++) { // Ir por cada potência de base 2
		for (int i = 0; i + (1<<k) - 1 < n; i++) { // (1 << k) é igual a 2^k
			m[i][k] = min(m[i][k-1], m[i + (1<<(k-1))][k-1]); // Dividir o intervalo em duas partes; encontrar o mínimo		
		}
	}

	// 3) Responder a queries
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << query(l, r) << "\n";
	}
	return 0;
}