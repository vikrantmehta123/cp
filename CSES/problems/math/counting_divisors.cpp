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

        int ans = 0;

        int int_result = sqrt(n);

        for(int i = 1; i <= int_result; i++){
            if(n % i == 0){
                if (n / i != i)
                    ans += 2; // i and n/i
                else
                    ans++; // perfect square root
            }
        }

        cout << ans << endl;

    };

    return 0;
}   