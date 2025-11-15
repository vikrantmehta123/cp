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
        ll n, k, x;
        cin >> n >> k >> x;

        ll lowerBound = (k*(k+1) / 2);
        ll upperBound = k * n - (k * (k - 1)) / 2;

        if (x >= lowerBound && x <= upperBound){

            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    };

    return 0;
}