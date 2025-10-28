#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;

    // (A * B) mod C = (A mod C * B mod C) mod C
    // A^B mod C = ( (A mod C)^B ) mod C

    long long int ans = 1;

    for (int i = 0; i < n; i++){
        ans = (ans % MOD * 2) % MOD;
    }

    cout << ans << endl;
}