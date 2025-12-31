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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<int> indegrees(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegrees[b]++;
    }

    queue<int> q;
    
    for(int i = 1; i <= n; i++){
        if (indegrees[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for(int neighbor: graph[node]){
            indegrees[neighbor]--;

            if(indegrees[neighbor] == 0){
                q.push(neighbor);
            }
        }
    }

    const int NEG = -1e9;
    vector<int> dist(n+1, NEG);
    vector<int> parent(n+1, -1);

    dist[1] = 1;

    for(auto& u: topo){
        if(dist[u] < 0){continue;}

        for(auto& v: graph[u]){
            if(dist[u] + 1 > dist[v]){
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dist[n] < 0){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path;
        int curr = n;
        while(curr != -1){
            path.push_back(curr);
            curr = parent[curr];
        }
        
        cout << path.size() << endl;

        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << (i == 0 ? "" : " ");
        }

        cout << endl;
    }

    return 0;
}