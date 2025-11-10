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

    vector<int> ans;
    if(n % 2 == 0){
        while(n > 0){
            ans.push_back(2);
            n -= 2;
        }
    }
    else{
        while(n != 3){
            ans.push_back(2);
            n -= 2;
        }
        ans.push_back(3);
    }

    cout << ans.size() << endl;
    for(auto& x: ans){
        cout << x << " ";
    }

    return 0;
}