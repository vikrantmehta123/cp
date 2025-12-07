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
        string s;
        cin >> s;

        int moveCount = 0;
        while (s.size() >= 2) 
        {
            bool flag = true;
            for(int i = 1; i < s.size(); i++){
                if (s[i-1] != s[i]){
                    flag = false;
                    moveCount++;
                    s.erase(i-1, 1);
                    s.erase(i-1, 1);
                    break;
                }
            }

            if (flag){
                break;
            }
        }
        
        if (moveCount % 2 != 0){
            cout << "DA" << endl;
        }
        else{
            cout << "NET" <<endl;
        }
    };

    return 0;
}