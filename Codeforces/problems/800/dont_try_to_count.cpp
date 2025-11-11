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
        int n, m;
        cin >> n >> m;

        string x, s;
        cin >> x >> s;
        if (s.size() > x.size()){
            cout << -1 << endl;
        }
        else{
            bool flag = false;
            for(int i = 0; i <= 5; i++){
                if (x.find(s) != x.npos){
                    flag = true;
                    cout << i << endl;
                    break;
                }
                else{
                    x = x+x;
                }
            }
            if (!flag){
                cout << -1 << endl;
            }
        }
    };

    return 0;
}