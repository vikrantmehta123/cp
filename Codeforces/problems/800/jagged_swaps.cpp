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
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }
        if(a[0] != *min_element(a.begin(), a.end())){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    };   

    return 0;
}