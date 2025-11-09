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
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        vector<int> arr(n);
        int evenParity = 0;
        int oddParity = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];

            if (i % 2 != arr[i] % 2){
                if (i%2==0){
                    evenParity++;
                }else{
                    oddParity++;
                }
            }
        }

        if(evenParity == oddParity){
            cout << evenParity << endl;
        } else{
            cout << -1 << endl;
        }


    }    

    return 0;
}