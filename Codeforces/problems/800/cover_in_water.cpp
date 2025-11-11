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

        string s;
        cin >> s;

        int count = 0;
        int currCount = 0;
        bool flag = false;
        for(int i=0; i < n; i++){
            if (s[i] == '.'){
                count++;
                currCount++;
            }
            else{
                if(currCount>=3){
                    flag = true;
                }
                currCount = 0;
            }
        }

        if(currCount>=3){
            flag = true;
        }

        if (flag){
            cout << 2 << endl;
        }
        else{
            cout << count << endl;
        }

    };

    return 0;
}