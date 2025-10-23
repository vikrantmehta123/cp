#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    vector<int> max_prices(m);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        prices.insert(num);
    }

    for(int i=0; i < m; ++i){
        cin >> max_prices[i];
        auto it = prices.upper_bound(max_prices[i]);
        if (it == prices.begin()) {
            cout << -1 << "\n";
        } else {
            --it;
            cout << *it << "\n";
            prices.erase(it);
        }
    }
}