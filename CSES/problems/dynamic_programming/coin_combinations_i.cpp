#include <bits/stdc++.h>
using namespace std;

const long int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, targetSum;
    cin >> n >> targetSum;

    vector<int> coins(n);
    vector<int> dp(targetSum + 1, 0);

    for (int i = 0; i < n; i++){
        cin >> coins[i];

    }

    // dp[x]: dp[x - coin1] + dp[x - coin2] + dp[x - coin3] ...
    // Base Cases: All coins have 1    

    dp[0] = 1;
    // Complexity is n*targetSum.
    for (int i=1; i <= targetSum; i++){
        for(auto& coin: coins){
            if (i - coin >= 0){
                dp[i] = (dp[i] + dp[i - coin] ) % MOD;
            }
        }
    }
    
    cout << dp[targetSum] << endl;
}