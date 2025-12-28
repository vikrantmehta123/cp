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
    vector<ll> b(n);
    vector<ll> c(n);
    
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    for(int i=0; i < n; i++){
        cin >> b[i];
    }
    for(int i=0; i < n; i++){
        cin >> c[i];
    }

    vector<ll> prefA(n+1, 0), prefB(n+1, 0), prefC(n+1, 0);
    for(int i = 0; i < n; i++){
        prefA[i+1] = prefA[i] + a[i];
        prefB[i+1] = prefB[i] + b[i];
        prefC[i+1] = prefC[i] + c[i];
    }

    ll max_diff = -INF;
    ll ans = -INF;
    for(int j = 2; j < n; j++){
        max_diff = max(max_diff, prefA[j-1] - prefB[j-1]);
        ll total = prefC[n] + max_diff + (prefB[j] - prefC[j]);
        ans = max(total, ans);
    }

    cout << ans << endl;

    return 0;
}