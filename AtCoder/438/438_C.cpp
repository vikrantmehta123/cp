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

    vector<int> a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        if(!s.empty() && a[i] == s.top().first){
            s.push({a[i], s.top().second + 1});

            if(s.top().second == 4){
                for (int i=0; i < 4; i++){
                    s.pop();
                }
            }
        }
        else{
            s.push({a[i], 1});
        }
        
    }

    cout << s.size() << endl;

    return 0;
}