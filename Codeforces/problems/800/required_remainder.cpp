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
    for (int i = 0; i < t; i++)
    {
        int x, y, n;
        cin >> x >> y >> n;

        int quotient = n / x;
        int remainder = n % x;

        if (remainder < y)
        {
            quotient--;
            cout << x*quotient + y << endl;
        }
        else if( remainder > y){
            cout << x*quotient + y << endl;
        }
        else{
            cout << n << endl;
        }
    }
    
    

    return 0;
}