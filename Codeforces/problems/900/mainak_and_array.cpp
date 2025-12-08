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

        int initDiff = a[n-1] - a[0];

		for (int i = 1; i < n; i++)
			initDiff = max(initDiff, a[i] - a[0]);

		// Check the maximum difference between the last element and any other element
		for (int i = 0; i < n - 1; i++)
			initDiff = max(initDiff, a[n - 1] - a[i]);

		// Check the maximum difference between consecutive elements
		for (int i = 0; i < n - 1; i++)
			initDiff = max(initDiff, a[i] - a[i + 1]);

        cout << initDiff << endl;
    };

    return 0;
}