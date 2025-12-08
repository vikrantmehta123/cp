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

    // Union Find
    map<ll, ll> numToCount;
    map<ll, set<ll>> countToNum;

    for (int i = 0; i < k; i++){
        if(numToCount.find(a[i]) == numToCount.end()){
            numToCount[a[i]] = 0;
        }
        numToCount[a[i]] += 1;

        int count = numToCount[a[i]];

        countToNum[count].insert(a[i]);
    }


    int left = 0;
    int right = k;
    while (right < n){
        int mode = *(countToNum.rbegin()->second.begin());
        out[left] = *(countToNum.rbegin()->second.begin());

        int oldCount = numToCount[a[left]];
        countToNum[oldCount].erase(a[left]);
        if (countToNum[oldCount].size() == 0){
            countToNum.erase(oldCount);
        }


        numToCount[a[left]] -= 1;
        if (numToCount[a[left]] == 0){
            numToCount.erase(a[left]);
        }
        else{
            int newCount = numToCount[a[left]];
            countToNum[newCount].insert(a[left]);
        }
        left++;

        if(numToCount.find(a[right]) == numToCount.end()){
            numToCount[a[right]] = 0;
        }
        numToCount[a[right]] += 1;
        int count = numToCount[a[right]];
        countToNum[count].insert(a[right]);
        right++;
    }

    out[n-k] = *(countToNum.rbegin()->second.begin());

    for(auto& x:out){
        cout << x << " ";
    }


    return 0;
}