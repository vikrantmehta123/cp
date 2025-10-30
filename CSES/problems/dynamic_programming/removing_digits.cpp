#include <bits/stdc++.h>
using namespace std;

int maxDigit(int n) {
    int mx = 0;
    while (n) {
        mx = max(mx, n % 10);
        n /= 10;
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0 ;
    while(n > 0){
        n -= maxDigit(n);
        ans += 1;
    }

    cout << ans << endl;
}