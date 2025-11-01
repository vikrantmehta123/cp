#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;

    long int zeroCount = 0;
    
    long long int fives = 5;

    while( fives <= n){
        zeroCount += n / fives;
        fives *= 5;
    }

    cout << zeroCount;
}
