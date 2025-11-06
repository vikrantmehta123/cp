#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, m;
vector<int> parent;
vector<bool> visited;
vector<vector<int>> adjList;
bool found = false;

void dfs(int u) {
    visited[u] = true;
    if (found) return;

    for (int v : adjList[u]) {

        if(found) return;
        
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);

        } else if (v != parent[u]) {

            vector<int> cycle;
            cycle.push_back(v);

            int curr = u;

            while(curr != v){
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            
            if (cycle.size() >= 4){
                cout << cycle.size() << "\n";
                for(auto& x: cycle){
                    cout << x + 1 << " ";
                }

                cout << endl;
                found = true;  
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adjList.resize(n);
    parent.assign(n, -1);
    visited.assign(n, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }

    for(int start = 0; start < n; start++) {
        if (visited[start]) continue;

        dfs(start);
    }

    if (!found){
        cout << "IMPOSSIBLE" << endl;
    }
}