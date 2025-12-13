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
        ll n;
        cin >> n;

        if (n % 2LL != 0LL || n < 4LL){
            cout << -1 << endl;
            continue;
        }

        
        ll min_count;
        if(n % 6LL == 0LL){
            min_count = n / 6LL;
        }
        else{
            min_count = n / 6LL + 1LL;
        }
        ll max_count = n / 4LL;

        cout << min_count << " " << max_count << endl;
    };

    return 0;
}