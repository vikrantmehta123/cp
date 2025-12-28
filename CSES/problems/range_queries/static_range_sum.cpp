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

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> pref(n+1, 0LL);
    for(int i = 0; i <= n; i++){
        pref[i+1] = a[i] + pref[i];
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        
        cout << pref[b] - pref[a-1] << endl;
    }

    return 0;
}