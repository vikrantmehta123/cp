#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    vector<int> pos(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    // compute initial round count
    int count = 1;
    for (int i = 2; i <= n; ++i) {
        if (pos[i - 1] > pos[i]) count++;
    }

    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < m; ++i) {
        int pa = a[i] - 1, pb = b[i] - 1;
        if (pa == pb) {
            cout << count << "\n";
            continue;
        }

        int va = arr[pa], vb = arr[pb];

        // collect affected numbers
        vector<int> affected;
        for (int v : {va, va + 1, vb, vb + 1}) {
            if (v >= 1 && v <= n) {
                if (find(affected.begin(), affected.end(), v) == affected.end())
                    affected.push_back(v);
            }
        }

        // subtract old contributions
        for (int v : affected) {
            if (v > 1 && pos[v - 1] > pos[v]) count--;
        }

        // swap in arr and pos
        swap(arr[pa], arr[pb]);
        swap(pos[va], pos[vb]);

        // add new contributions
        for (int v : affected) {
            if (v > 1 && pos[v - 1] > pos[v]) count++;
        }

        cout << count << "\n";
    }

    return 0;
}
