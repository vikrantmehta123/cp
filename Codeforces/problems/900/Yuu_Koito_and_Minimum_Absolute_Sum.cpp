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
        for(int i=0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 1; i < n - 1; i++){
            if(a[i] == -1){
                a[i] = 0;
            }
        }

        if(a[0] == -1 and a[n-1] == -1){
            a[0] = 0;
            a[n-1] = 0;
        }
        else if(a[0] == -1){
            a[0] = a[n-1];
        }
        else if(a[n-1] == -1){
            a[n-1] = a[0];
        }

        int diff = 0;
        for(int i = 1; i < n; i++){
            diff += a[i] - a[i-1];
        }

        cout << abs(diff) << endl;
        for(int i = 0; i < n; i++){
            if(i < n - 1){
                cout << a[i] << " ";
            }
            else{
                cout << a[i] << endl;
            }
        }
    };    

    return 0;
}