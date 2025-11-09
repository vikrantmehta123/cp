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

    int x;
    cin >> x;

    int res;
    if (x % 5 == 0){
        res = x / 5;
    }
    else{
        res = (x / 5) + 1;
    }
    cout << res << endl;


    return 0;
}