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

    int n;
    cin >> n;
    
    vector<ll> a(n);
    ll total = 0LL;
    for(int i=0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    long long min_diff = LLONG_MAX;
    
    // Iterate through all 2^n subsets
    for (int mask = 0; mask < (1 << n); mask++) {
        long long part1_sum = 0;
        
        // Check each bit
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                part1_sum += a[i];
            }
        }
        
        long long part2_sum = total - part1_sum;
        min_diff = min(min_diff, abs(part1_sum - part2_sum));
    }

    cout << min_diff << endl;


    return 0;
}