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
        vector<int> a(n);
        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        int count = 0;
        for(int i = n - 1; i > 0; i--){
            while(a[i-1] >= a[i] && a[i-1] > 0 ){
                a[i-1] /= 2;
                count++;
            }
        }

        bool flag = false;
        for(int i = 1; i < n; i++){
            if (a[i-1] >= a[i]){
                cout << -1 << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << count << endl;
        }
    };


    return 0;
}