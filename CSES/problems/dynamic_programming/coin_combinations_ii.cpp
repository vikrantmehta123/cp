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

const ll MOD = 1e9 + 7;

int main(){
    fastio();

    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> dp(x+1, 0);
    dp[0] = 1;

    for(auto& coin: a){
        for(int i=0; i <= x; i++){
            if(i-coin>=0){
                dp[i] = ((dp[i] % MOD) + (dp[i-coin] % MOD)) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}