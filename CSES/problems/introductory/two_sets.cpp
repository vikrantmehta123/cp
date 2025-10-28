#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;

    long long int totalSum = n*(n + 1) / 2;

    if (totalSum % 2 != 0){
        cout << "NO" ;
    } 
    else{
        long long int targetSum = totalSum / 2;

        vector<long long int> set1;
        vector<long long int> set2;
        long long int sum1 = 0, sum2 = 0;

        for (long long int i = n; i >= 1; i--){
            if (i + sum1 <= targetSum){
                sum1 += i;
                set1.push_back(i);
            }

            else if (i + sum2 <= targetSum){
                sum2 += i;
                set2.push_back(i);
            }
        }
        cout << "YES\n";
        cout << set1.size() << "\n";
        for (auto x: set1){
            cout << x << " ";
        }

        cout << "\n";

        cout << set2.size() << "\n";
        for(auto x: set2){
            cout << x << " ";
        }

        cout << "\n";

    }
}