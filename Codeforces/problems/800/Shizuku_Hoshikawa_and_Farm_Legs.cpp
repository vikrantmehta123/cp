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

        int maxchicks = n / 2;
        int count = 0;
        for(int i = 0; i <= maxchicks; i++){
            int chicklegs = 2*i;
            int cowlegs = n - chicklegs;
            if(cowlegs % 4 !=0){continue;}

            int cows = cowlegs / 4;
            count++;
        }

        cout << count << endl;
    };
    

    return 0;
}