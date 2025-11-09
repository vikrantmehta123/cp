#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

const ll INF  = 1e18;

static void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(){
    fastio();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        if (s.size() > 10){
            cout << s[0] << s.size() - 1 - 1 << s[s.size() -1] << endl;
        }
        else{
            cout << s << endl;
        }
    }

    return 0;
}