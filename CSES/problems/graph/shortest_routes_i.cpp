#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // adjacency list: graph[a] contains pairs (b, c)
    vector<vector<pair<int,int>>> graph(n + 1);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }


    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<long long,int>, 
                   vector<pair<long long,int>>, 
                   greater<pair<long long,int>>> pq;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;  // stale entry

        for (auto &[v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i = 1; i < dist.size(); i++){
        cout << dist[i] << " ";
    }
    cout << endl;

}