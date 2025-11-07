#include <bits/stdc++.h>
using namespace std;

static const long long INF = 4e18;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // Create n x n distance matrix
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));

    // Distance to itself is zero
    for(int i = 1; i <= n; i++){
        dist[i][i] = 0;
    }

    // Read edges (undirected)
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // If there are multiple edges between (a, b), FW requires the best edge. Hence, the minimum
        dist[b][a] = min(dist[b][a], c);
    }

    // Floyd–Warshall: O(n^3)
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(dist[i][k] == INF) continue;
            for(int j = 1; j <= n; j++){
                if(dist[k][j] == INF) continue;
                ll through = dist[i][k] + dist[k][j];
                if(through < dist[i][j]){
                    dist[i][j] = through;
                }
            }
        }
    }

    // Answer queries in O(1)
    while (q--) {
        int a, b;
        cin >> a >> b;
        ll ans = dist[a][b];
        if (ans == INF) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
