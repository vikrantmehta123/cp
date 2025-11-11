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

vector<vector<int>> adj;
vector<int> counts;
vector<bool> visited;

int main() {
    fastio();

    int n;
    cin >> n;

    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int boss;
        cin >> boss;
        adj[boss - 1].push_back(i);
    }

    counts.assign(n, 0);
    visited.assign(n, false);

    int start = 0;

    // iterative DFS stack: (node, processed)
    vector<int> stack;
    vector<int> order;
    stack.push_back(start);

    // first pass: simple DFS to get visited order
    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();
        order.push_back(node);

        for (int child : adj[node]) {
            stack.push_back(child);
        }
    }

    // second pass: process in reverse order (post-order)
    for (int i = order.size() - 1; i >= 0; i--) {
        int node = order[i];

        int cnt = 0;
        for (int child : adj[node]) {
            cnt += counts[child] + 1;   // child subtree size
        }
        counts[node] = cnt;
    }

    for (int x : counts) cout << x << " ";
    cout << "\n";

    return 0;
}
