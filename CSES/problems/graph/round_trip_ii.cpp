#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, m;
vector<vector<int>> adjList;

vector<int> color;    // 0 = unvisited, 1 = inStack, 2 = done
vector<int> parent;
bool found = false;

void dfs_iter(int start) {
    struct Item { int u, idx; };
    stack<Item> st;

    st.push({start, 0});
    color[start] = 1;

    while (!st.empty()) {
        auto &t = st.top();
        int u = t.u;

        // If fully processed all children
        if (t.idx == (int)adjList[u].size()) {
            color[u] = 2;
            st.pop();
            continue;
        }

        int v = adjList[u][t.idx++];
        
        if (color[v] == 0) {
            parent[v] = u;
            color[v] = 1;
            st.push({v, 0});
        }
        else if (color[v] == 1) {
            // Found cycle
            vector<int> cycle;
            cycle.push_back(v);

            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);

            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << "\n";
            for (int x : cycle) cout << x + 1 << " ";
            cout << "\n";

            found = true;
            return;
        }
        // color[v] == 2 → nothing to do
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    adjList.resize(n);
    color.assign(n, 0);
    parent.assign(n, -1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adjList[a-1].push_back(b-1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs_iter(i);
            if (found) break;
        }
    }

    if (!found){
        cout << "IMPOSSIBLE" << endl;
    }
}