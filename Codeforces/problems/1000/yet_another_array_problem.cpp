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
        int n;
        cin >> n;

        vector<ll> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        long long g = a[0];
        for (int i = 1; i < a.size(); i++) {
            g = std::gcd(g, a[i]);
        }

        long long x = 2;
        while (std::gcd(x, g) != 1){
            x++;
        }

        cout << x << endl;
                
    };   

    return 0;
}