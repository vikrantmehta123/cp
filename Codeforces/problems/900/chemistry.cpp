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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;


        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        int evenCount = 0;
        int oddCount = 0;

        for (auto &p : freq) {
            if (p.second % 2 == 0){
                evenCount += p.second;
            }
            else{
                int t = p.second / 2;
                evenCount += (2 * t);
                oddCount++;
            }
        }

        if (oddCount <= 1 && k == 0){
            cout << "YES" << endl;
        }
        else{
            if (k >= oddCount - 1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }

        

        
    };

    return 0;
}