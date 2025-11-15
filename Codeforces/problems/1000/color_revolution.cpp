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
        int n, k;
        cin >> n >> k;

        int denominator = (1 + k + pow(k, 2) + pow(k, 3));
        int n1 = (n / denominator);

        int n2 = k*n1;
        int n3 = k*n2;
        int n4 = k*n3;

        cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
    };    

    return 0;
}