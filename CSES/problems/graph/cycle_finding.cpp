#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge{
	ll a;
	ll b;
	ll weight;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	vector<Edge> edges;

	for(int i = 0; i < m; i++){
		ll a, b, c;
		cin >> a >> b >> c;
		Edge e;
		e.a = a;
		e.b = b;
		e.weight = c;
		edges.push_back(e);
	}


	// Insert a dummy node connected with every node so that we handle the case of the graph not being connected
	// Another way to detect negative cycles is to initialize the dist = 0 for each vertex. Then we don't need this dummy node.
	for (ll i = 1; i <= n; i++){
		Edge e;

		e.a = 0LL;
		e.b = i;
		e.weight = 0LL;

		edges.push_back(e);
	}

	bool cyclePresent = false;
	vector<ll> dist(n+1, INF);
	vector<ll> parent(n+1, -1LL);

	dist[0LL] = 0LL;

	// Bellman-ford
	for(int i = 0; i < n; i++){
		for(auto& edge: edges){
			ll u = edge.a, v=edge.b, weight = edge.weight;

			if(dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				parent[v] = u;
			}
		}
	}

	// Check for cycles
	ll cycleNode = -1LL;
	for(auto& edge: edges){
		ll u = edge.a, v=edge.b, weight = edge.weight;
		
		// Cycle found
		if(dist[u] + weight < dist[v]){
			cycleNode = v;
			cyclePresent = true;
			parent[v] = u;
		}
	}

	// Recover Cycle
	if (cyclePresent){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cycleNode = parent[cycleNode];
		}

		// Now trace the cycle
		vector<ll> cycle;
		ll current = cycleNode;
		do {
			cycle.push_back(current);
			current = parent[current];
		} while(current != cycleNode);

		cycle.push_back(cycleNode);

		// Print the cycle in reverse order to show the path
		reverse(cycle.begin(), cycle.end());
		for(ll node : cycle){
			cout << node << " ";
		}
		cout << endl;
	}
	
	if(!cyclePresent){
		cout << "NO" << endl;
	}

}
