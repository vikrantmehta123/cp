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
        
        vector<int> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        // cout << "K is: " << k << endl;
        // for(auto& x:a){
        //     cout << x << " ";
        // }
        // cout << endl;

        int ans = 0;
        int curr = 0;
        for(int i=1; i < n; i++){
            if(a[i] - a[i-1] <= k){
                curr++;
                ans = max(curr, ans);

            }
            else{
                ans = max(curr, ans);
                curr = 0;
            }
        }
        cout << n-ans-1 << endl;
    };
        

    return 0;
}