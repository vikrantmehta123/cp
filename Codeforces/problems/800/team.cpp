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

    int count = 0;

    for(int i = 0; i < n; i++){
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;

        if (num1 + num2 + num3 >= 2){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}