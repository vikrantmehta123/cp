#include <bits/stdc++.h>
using namespace std;

static const long long INF = 4e18;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
    }

    vector<int> indegree(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(int neigh: adj[i]){
            indegree[neigh]++;
        }
    }

    queue<int> q;
    for(int i = 1; i <=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> order;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        order.push_back(u);

        for(int v: adj[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
        }
    }


    if(order.empty() || order.size() != n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        for(auto& x: order){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
