#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

struct Edge{
    ll a;
    ll b;
    ll weight;
};

void dijkstra(
    int src,
    const vector<vector<pair<ll, ll>>> &adj,
    vector<ll> &dist
) {
    int n = adj.size();
    dist.assign(n, INF);

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (d > dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<vector<pair<ll, ll>>> revAdj(n+1);

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        adj[a].push_back({b, c});
        revAdj[b].push_back({a, c});

        Edge e;
        e.a = a;
        e.b = b;
        e.weight = c;
        edges[i] = e;
    }


    vector<ll> ogDist(n+1);
    vector<ll> revDist(n+1);

    dijkstra(n, revAdj, revDist);
    dijkstra(1, adj, ogDist);
    
    ll minDist = INF;
    for(Edge e: edges){
        if (ogDist[e.a] + revDist[e.b] + (e.weight / 2) < minDist){
            minDist = ogDist[e.a] + revDist[e.b] + floor(e.weight / 2);
        }
    }

    cout << minDist << endl;

    return 0;
}
