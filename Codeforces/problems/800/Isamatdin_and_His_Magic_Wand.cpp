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

        vector<int> a(n);
        int oddCount = 0;
        int evenCount = 0;
        for(int i=0; i < n; i++){
            cin >> a[i];
            if (a[i] % 2 == 0){
                evenCount++;
            }
            else{
                oddCount++;
            }
        }

        if (oddCount > 0 && evenCount > 0){
            sort(a.begin(), a.end());
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";            
        }
        cout << endl;

    };

    return 0;
}