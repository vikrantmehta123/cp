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

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> out(n -k + 1);

    map<ll, ll> uniques;

    for (int i = 0; i < k; i++){
        if(uniques.find(a[i]) == uniques.end()){
            uniques[a[i]] = 1;
        }
        else{
            uniques[a[i]] += 1;
        }
    }

    int left = 0;
    int right = k;
    while (right < n){
        out[left] = uniques.size();
        uniques[a[left]] -= 1;
        if (uniques[a[left]] == 0){
            uniques.erase(a[left]);
        }
        left++;

        if(uniques.find(a[right]) == uniques.end()){
            uniques[a[right]] = 0;
        }
        uniques[a[right]] += 1;
        right++;
    }

    out[n-k] = uniques.size();

    for(auto& x:out){
        cout << x << " ";
    }

    return 0;
}