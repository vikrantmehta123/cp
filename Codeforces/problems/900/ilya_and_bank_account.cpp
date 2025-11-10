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

    int n;
    cin >> n;

    if ( n >= 0 ){
        cout << n << endl;
    }
    else{
        int lastRemoved = n / 10;
        
        int digitCount = 0;
        int power = 0;
        int temp = 0;
        n = abs(n);
        while(n > 0){
            int lastDigit = n % 10;
            n /= 10;
            digitCount++;
            if (digitCount != 2){
                temp += pow(10, power)* lastDigit;
                power++;
            }
        }

        cout << max(-temp, lastRemoved) << endl;

    }

    return 0;
}