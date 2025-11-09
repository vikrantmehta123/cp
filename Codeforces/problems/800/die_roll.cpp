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

    int y, w;
    cin >> y >> w;
    
    int maxNum = 6 - (max(y, w) - 1);
    
    if (maxNum == 1){
        cout << 1 << "/" << 6;
    } else if (maxNum == 2){
        cout << 1 << "/" << 3;
    } else if (maxNum == 3){
        cout << 1 << "/" << 2;
    } else if (maxNum == 4){
        cout << 2 << "/" << 3;
    } else if (maxNum == 5){
        cout << 5 << "/" << 6;
    } else if (maxNum == 6){
        cout << 1 << "/" << 1;
    }

    return 0;
}