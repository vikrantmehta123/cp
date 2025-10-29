#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long int n, targetSum;
    cin >> n >> targetSum;

    vector<int> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<long int> dp(targetSum + 1, -1);

    // init dp start states.
    for(long int i = 0; i < n; i++){
        if(coins[i] <= targetSum){
            dp[coins[i]] = 1;
        }
    }

    for(long int i = 1; i <= targetSum; i++){
        for(auto coin: coins){
            if (i - coin > 0){

                if(dp[i - coin] == -1){
                    dp[i] = dp[i];
                }
                else if (dp[i] == -1){
                    dp[i] = 1 + dp[i -coin];
                }
                else{
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
    }
    
    cout << dp[targetSum];

    return 0; 
}