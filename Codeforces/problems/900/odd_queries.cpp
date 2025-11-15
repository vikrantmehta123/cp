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

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;

        vector<ll> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        vector<ll> pref(n+1, 0LL);
        for(int i=0; i < n; i++){
            if(i==0){
                pref[i+1] = a[i];
            }
            else{
                pref[i+1] = a[i] + pref[i];
            }
        }

        for(int i=0; i < q; i++){
            ll l, r, k;
            cin >> l >> r >> k;

            ll arrsum = k*(r-l+1) + pref[l-1] + pref[n]-pref[r];
            if(arrsum % 2LL == 0){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    };    

    return 0;
}