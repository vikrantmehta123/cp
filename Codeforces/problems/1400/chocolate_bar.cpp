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
        
        int n, m, p;
        cin >> n >> m >> p;

        bool flag = false;
        for(int i = 0; i < n+1; i++){
            for (int j = 0; j < m+1; j++){
                if (i*j == p){
                    cout << "Yes" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag){
                break;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }
    };
    

    return 0;
}