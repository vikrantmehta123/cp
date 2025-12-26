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

    vector<int> a(n);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    // Dynamic Programming Based solution: O(n^2)
    // vector<int> lis(n, 1);    
    // for(int i = n - 2; i >= 0; i--){
    //     for (int j = i + 1; j < n; j++){
    //         if(a[j] > a[i]){
    //             lis[i] = max(lis[i], 1 + lis[j]);
    //         }
    //     }
    // }
    // int maxElem = *max_element(lis.begin(), lis.end());
    // cout << maxElem << endl;

    // Using Patience Sorting O(nlogn):

    vector<int> tops;
    tops.push_back(a[0]);

    for(int i = 1; i < n; i++){

        int left  = 0;
        int right = tops.size() - 1;

        int ans = -1;

        while(left <= right){
            int mid = (left + right) / 2;

            if (a[i] <= tops[mid]){
                right = mid - 1;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }

        if(ans == -1){
            tops.push_back(a[i]);
        }
        else{
            tops[ans] = a[i];
        }
        
    }

    cout << tops.size() << endl;


    return 0;
}