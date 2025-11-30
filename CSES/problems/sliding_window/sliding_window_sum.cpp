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

    ll n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++){
        arr[i] = (a * arr[i-1] + b) % c;
    }

    int left = 0, right = 0;

    ll answer = 0LL;
    ll currsum = 0LL;
    while(right < k){
        currsum += arr[right];
        answer += arr[right];
        right++;
    }

    while (right < n){
        currsum -= arr[left];
        left++;

        currsum += arr[right];
        right++;

        answer = answer ^ currsum;
    }
    cout << answer << endl;
    return 0;    
}