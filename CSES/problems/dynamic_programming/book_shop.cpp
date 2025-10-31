#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++){
        cin >> prices[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    vector<int> dp(x + 1, 0);

    for (int j = 0; j < n; j++) {
        for (int i = x; i >= prices[j]; i--) {
            dp[i] = max(dp[i], dp[i - prices[j]] + pages[j]);
        }
    }
    cout << dp[x] << endl;
}