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

        int newN = n;
        int count3 = 0;
        while(newN % 3 == 0){
            newN /= 3;
            count3++;
        }
        int count2 = 0;
        while(newN % 2 == 0){
            count2++;
            newN /= 2;
        }

        if (newN != 1){
            cout << -1 << endl;
        }else if(count2 > count3){
            cout << -1 << endl;
        }
        else{
            cout << count3 - count2 + count3 << endl;
        }
    }

    return 0;
}