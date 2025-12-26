#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

const ll INF  = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#endif

static void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


void dfs(int u, vector<bool>& canReachN, vector<vector<ll>>& rev_adj) {
    canReachN[u] = true;
    for (ll v : rev_adj[u]) {
        if (!canReachN[v])
            dfs(v, canReachN, rev_adj);
    }
}

int main(){
    fastio();

    int n, m;
    cin >> n >> m;

    map<ll, vector<pair<ll, ll>>> adj;
    vector<vector<ll>> rev_adj(n+1);

    for (ll i = 0; i < m; i++){
        ll a, b, x;
        cin >> a >> b >> x;

        adj[a].push_back({b, -x});
        rev_adj[b].push_back(a);

    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0LL;
    // Bellman-Ford
    for (ll i = 1; i <= n - 1; i++) {
        for (auto &entry : adj) {
            ll u = entry.first;
            if (dist[u] == INF) continue;

            for (auto &edge : entry.second) {
                ll v = edge.first;
                ll w = edge.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }


    // Detect if there is any negative cycle in the path between 1 to N
    vector<bool> canReachN(n+1, false);
    dfs(n, canReachN, rev_adj);
    bool bad = false;
    for (int u = 1; u <= n; u++) {
        if (dist[u] == INF || !canReachN[u]) continue;
        for (auto &e : adj[u]) {
            if (canReachN[e.first] && dist[e.first] > dist[u] + e.second) {
                bad = true;
            }
        }
    }


    if (bad){
        cout << -1 << endl;
    }
    else{
        cout << -dist[n] << endl;
    }



    return 0;
}