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

        // Use Diophantine Equation Property to solve
        double lower_bound = (double)n / 2021.0;
        double upper_bound = (double)n / 2020.0;

        int tmin = (int)ceil(lower_bound);
        int tmax = (int)floor(upper_bound);
        
        if (tmin <= tmax){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }   

    return 0;
}