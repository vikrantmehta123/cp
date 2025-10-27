#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long int count = 0;
    map<int, int> numToIdx;
    int start = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
    
        if (auto it = numToIdx.find(num); it != numToIdx.end() && it->second >= start) {
            // Num is present and it's part of the current subarray
            start = numToIdx[num] + 1;
            int numToAdd = i - start + 1;
            count += numToAdd;
        }
        else{
            // num is not present
            int numToAdd = i - start + 1;
            count += numToAdd;
        }
        numToIdx[num] = i;
    }
    cout << count << "\n";
}