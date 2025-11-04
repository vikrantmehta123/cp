#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long int> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vector<long long int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i-1];
    }

    vector<long long int> remainderCounts(n, 0);
    for(int i = 0; i <= n; i++){
        int remainder = ((prefixSum[i] % n) + n) % n;
        remainderCounts[remainder] += 1;
    }

    long long int ans = 0LL;
    for(int i=0; i < n; i++){
        ans += remainderCounts[i] * (remainderCounts[i] - 1) / 2;
    }

    cout << ans << endl;
}
