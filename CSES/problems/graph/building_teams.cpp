#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }

    queue<int> q;

    vector<int> level;
    vector<int> visited;
    level.assign(n, -1);
    visited.assign(n, 0);

    for(int i=0; i < n; i++){
        if (visited[i]) continue;

        int start = i;
        q.push(start);
        visited[start] = 1;
        level[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if(visited[v] && level[v] == level[u]){
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
                if (!visited[v]) {
                    visited[v] = 1;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }

    }


    map<int, vector<int>> nodesAtLevel;
    for (int i = 0; i < n; i++) {
        if (level[i] != -1)
            nodesAtLevel[level[i]].push_back(i);
    }

    vector<int> res(n, 0);
    for (auto &p : nodesAtLevel) {
        int group;
        if(p.first % 2 == 0){
            group = 2;
        }
        else{
            group = 1;
        }
        for (int x : p.second) {
            res[x] = group;
        }
    }

    for(auto& x: res){
        cout << x << " ";
    }


}