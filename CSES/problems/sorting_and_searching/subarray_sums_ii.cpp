#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long prefix = 0, ans = 0;
    map<long long, int> count;
    count[0] = 1;

    for (auto v : a) {
        prefix += v;
        if (count.find(prefix - x) != count.end())
            ans += count[prefix - x];
        count[prefix]++;
    }

    cout << ans << endl;
}
