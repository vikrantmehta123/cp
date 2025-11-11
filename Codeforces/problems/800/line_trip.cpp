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
        int n, x;
        cin >> n >> x;

        int ai = -1, ai_1 = -1;
        int maxDiff = 0;
        for(int i=0; i < n; i++){
            if(ai == -1){
                cin >> ai;
                maxDiff = ai - 0;
            }
            else{
                ai_1 = ai;
                cin >> ai;

                int diff = ai - ai_1;
                maxDiff = max(diff, maxDiff);
            }
        }

        int lastDiff = abs(ai-x) * 2;
        maxDiff = max(lastDiff, maxDiff);
        cout << maxDiff << endl;
    }

    return 0;
}