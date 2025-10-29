#include <bits/stdc++.h>
using namespace std;


const long int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1, 0);
    arr[1] = 1;

    if (n == 1) {
        cout << 1 ;
    }
    else{
        for (int i = 2; i < arr.size(); i++){

            if ( i <= 6){
                arr[i] += 1;

                for (int j = 1; j < i; j++){
                    arr[i] += arr[i - j];
                }
            }
            else{
                for (int j = 1; j <= 6; j++){
                    arr[i] = (arr[i] % MOD + arr[i - j] % MOD ) % MOD;
                }
            }
        }
        cout << arr[arr.size()- 1];
    }
}