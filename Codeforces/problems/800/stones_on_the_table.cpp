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

    string s;
    cin >> s;

    char lastChar;
    int count = 0;
    for(int i=0; i < s.size(); i++){
        if ( i == 0 ){
            lastChar = s[i];
        }
        else{
            if(lastChar == s[i]){
                count++;
            }else{
                lastChar = s[i];
            }
        }
    }

    cout << count << endl;
    

    return 0;
}