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

    int m, n;
    cin >> m >> n;

    int totalSquares = m * n ;
    cout << floor(totalSquares /2 ) << endl;


    return 0;
}