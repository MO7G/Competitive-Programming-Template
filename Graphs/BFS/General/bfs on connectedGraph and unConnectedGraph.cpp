#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long


const ll inf = 1e15;
const int limit = 1e5 + 5;

int vis[limit];
vector<int>adj[limit];
vector<int>path;
ll n, m;

void ConnectedDfs(int src) {
	vis[src] = true;
	path.pb(src);
	for (int next : adj[src])
		if (!vis[next])
			ConnectedDfs(next);
}

void unConnectedDfs(int src) {
	ConnectedDfs(src);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			path.pb(-1), ConnectedDfs(i);
}

void solve() {
	freopen("test.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		// comment the bellow code incase of directed graph !!!
		adj[y].pb(x);
	}
	int src = 1;
	// If the Graph is not connected
	unConnectedDfs(src);

	// If the Graph is connected
	//ConnectedDfs(src)


	for (auto it : path)
		if (it == -1)
			cout << endl;
		else
			cout << it << " ";
	cout << endl;
}


int main() {
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
}