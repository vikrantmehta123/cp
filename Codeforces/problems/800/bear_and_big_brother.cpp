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

    int a, b;
    cin >> a >> b;

    int count = 0;
    while(a <= b){
        a = 3*a;
        b = 2*b;
        count++;
    }

    cout << count << endl;
    

    return 0;
}