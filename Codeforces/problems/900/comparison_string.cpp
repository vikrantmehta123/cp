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

        string s;
        cin >> s;

        int maxCount = 0;
        int lessCount = 0;
        int greatCount = 0;
        for(int i=0; i < n; i++){

            if (s[i] == '<'){
                lessCount++;                
                maxCount = max({lessCount, maxCount, greatCount});
                greatCount = 0;
            }
            else{
                greatCount++;
                maxCount = max({lessCount, maxCount, greatCount});
                lessCount = 0;
            }
        }

        cout << maxCount + 1 << endl;
    };

    return 0;
}