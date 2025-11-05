#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<long long int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i=1; i < n; i++){
        if (a[i] != 0 && a[i -1] != 0 && abs(a[i] - a[i-1] > 1)){
            cout << 0 << endl;
            return 0;
        }
    }
    
    vector<ll> mins(n), maxs(n);

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            mins[i] = maxs[i] = a[i];
        } else {
            if (i == 0) {
                mins[i] = 1;
                maxs[i] = m;
            } else {
                mins[i] = max(1LL, mins[i-1] - 1);
                maxs[i] = min(m, maxs[i-1] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == 0) {
            mins[i] = max(mins[i], mins[i+1] - 1);
            maxs[i] = min(maxs[i], maxs[i+1] + 1);
            mins[i] = max(mins[i], 1LL);
            maxs[i] = min(maxs[i], m);
        }
    }

    vector<long long int> branches(m + 1, 0);

    for (int i = 0; i < n; i++) {
        long long int num = a[i];
        if(num != 0){
            if(i == 0){
                branches[num]=1;
            }
            else{
                long long num = a[i];
                long long total = 0;
                // transitions from num-1, num, num+1
                for (int d = -1; d <= 1; d++) {
                    int prev = num + d;
                    if (prev >= 1 && prev <= m)
                        total = (total + branches[prev]) % MOD;
                }
                branches.assign(m + 1, 0);
                branches[num] = total;
            }
        }
        else{
            if(i == 0){
                for (int k=0; k < branches.size(); k++){
                    for(ll j=mins[i]; j <= maxs[i]; j++){
                        branches[j] = 1;
                    }
                }

            }
            else{
                vector<ll> newbranches(m+1, 0);
                for (int j = 1; j <= m; j++) {
                    long long val = branches[j];
                    if (val == 0) continue;
                    for (int d = -1; d <= 1; d++) {
                        int nxt = j + d;
                        if (nxt >= 1 && nxt <= m)
                            newbranches[nxt] = (newbranches[nxt] + val) % MOD;
                    }
                }

                for(int k=0; k < newbranches.size(); k++){
                    branches[k] = newbranches[k];
                }
            }
        }
    }

    ll sum = 0LL;
    for (auto& x: branches){
        sum = (sum + x) % MOD;
    }
    cout << sum << endl;
}