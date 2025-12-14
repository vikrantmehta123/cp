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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a == b && b == c && c == d){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;       
        }
    };   

    return 0;
}