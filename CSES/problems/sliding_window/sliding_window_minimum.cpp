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

int main(){
    fastio();

        ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++){
        arr[i] = (a * arr[i-1] + b) % c;
    }

    ll answer = 0LL;
    deque<int> dq;  // stores indices

    for (int i = 0; i < n; i++) {
        // Step 1: Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Step 2: Remove indices whose values are >= arr[i]
        // (they can never be minimum while arr[i] is in window)
        while (!dq.empty() && arr[dq.back()] >= arr[i]) {
            dq.pop_back();
        }
        
        // Step 3: Add current index
        dq.push_back(i);
        
        // Step 4: The front has the minimum (once we have k elements)
        if (i >= k - 1) {
            answer ^= arr[dq.front()];
        }
}
    cout << answer << endl;

    return 0;
}