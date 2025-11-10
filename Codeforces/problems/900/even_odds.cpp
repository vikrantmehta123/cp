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
    
    ll evenCounts, oddCounts;

    if (n % 2LL == 0LL){
        evenCounts = n / 2;
        oddCounts = n / 2;
    }
    else{
        evenCounts = n / 2;
        oddCounts = ( n / 2 ) + 1LL;
    }

    if (k <= oddCounts){
        cout << 2*k - 1 << endl;
    }
    else{
        k = k - oddCounts;
        cout << 2*k  << endl;
    }

    return 0;
}