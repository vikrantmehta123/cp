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
        ll max_val, init_val, n;
        cin >> max_val >> init_val >> n;

        vector<ll> arr(n);
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll ans = 0LL;
        
        ll currVal = init_val;
        int i = 0;
        while (i < n && currVal <= max_val){
            if (currVal + arr[i] <= max_val){
                currVal += arr[i];
            }
            else{
                ans += (currVal - 1LL);
                currVal = min(1LL + arr[i], max_val);
            }
            i++;
        }
        
        ans+= currVal;
        cout << ans << endl;
        
    };

    return 0;
}

