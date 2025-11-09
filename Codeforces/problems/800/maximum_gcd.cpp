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
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        int low = 1, high = n;
        int mid;
        int ans = 1;

        while(low <= high){
            mid = (low + high) / 2;
            

            if (mid <= n && mid * 2 <= n){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}