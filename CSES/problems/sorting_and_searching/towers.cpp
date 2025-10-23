#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    multiset<int> bases;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];

        auto it = bases.upper_bound(arr[i]);
        if (it == bases.end()) {
            bases.insert(arr[i]);
        }
        else{
            bases.erase(it);
            bases.insert(arr[i]);
        }
    }

    cout << bases.size() << "\n";
}