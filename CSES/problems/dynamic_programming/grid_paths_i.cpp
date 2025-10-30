#include <bits/stdc++.h>
using namespace std;

const long int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> grid(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i]; 
    }

    // Base cases

    // 1st Column
    for(int i = 0; i < n; i++){
        if (grid[i][0] == '*'){
            dp[i][0] = 0;
        }
        else{
            if (i > 0){
                dp[i][0] = dp[i - 1][0];
            }
            else{
                dp[i][0] = 1;
            }
        }
    }

    // 1st row
    for(int i=0; i < n; i++){
        if (grid[0][i] == '*'){
            dp[0][i] = 0;
        }
        else{
            if (i > 0){
                dp[0][i] = dp[0][i - 1];
            }
            else{
                dp[0][i] = 1;
            }
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            char ch = grid[i][j];
            if (ch == '*'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i-1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n-1][n-1];

}