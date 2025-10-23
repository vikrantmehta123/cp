#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    int start = 0, end = x;

    vector<int> arr(n);

    multiset<int> signals;
    signals.insert(start);
    signals.insert(end);

    multiset<int> diffs;
    diffs.insert(end-start);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        auto upper_it = signals.upper_bound(arr[i]);
        auto lower_it = prev(upper_it);

        int diff = *upper_it - *lower_it;

        signals.insert(arr[i]);

        auto it = diffs.find(diff);
        diffs.erase(it);

        diffs.insert(arr[i] - *lower_it);
        diffs.insert(*upper_it - arr[i]);

        auto it1 = diffs.rbegin();
        if (it1 != diffs.rend())
            cout << *it1 << " ";
    }
}