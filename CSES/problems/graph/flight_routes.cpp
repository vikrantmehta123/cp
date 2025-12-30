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

int main(){
    fastio();

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> graph(n+1);

    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    vector<int> counts(n+1, 0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<vector<ll>> dist(n+1);

    pq.push({0LL, 1});

    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if (counts[u] >= k) {continue;}
        
        counts[u]++;
        dist[u].push_back(d);

        for(auto& x: graph[u]){
            int v = x.first;
            ll weight = x.second;

            if(counts[v] >= k) {continue;}

            pq.push({d + weight, v});
        }
    }

    for(int i = 0; i < k; i++){
        cout << dist[n][i] << (i == k-1 ? "": " ");
    }

    cout << endl;

    return 0;
}