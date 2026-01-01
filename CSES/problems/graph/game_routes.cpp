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

    int MOD = 1e9 + 7;
    int n, m;

    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> indegrees(n+1, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegrees[b]++;
    }

    vector<bool> visited(n+1, false);
    

    vector<ll> cnts(n+1, 0LL);
    queue<int> q;
    
    for(int i = 1; i <= n; i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(auto& v: graph[u]){
            indegrees[v]--;
            if(indegrees[v] == 0){
                q.push(v);
            }
        }
    }

    vector<ll> dp(n+1, 0LL);
    dp[1] = 1LL;
    for(auto& u: topo){
        for(auto& v: graph[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
