#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<long int, long int>> arr(n);
    map<pair<long int, long int>, int> pairToIdx;


    for (int i = 0; i < n; i++){
        pair<long int, long int> p;
        cin >> p.first >> p.second;
        arr[i] = p;
        pairToIdx[p] = i;
    }

    vector<bool> contains(n, false);
    vector<bool> contained(n, false);

    sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.first == b.first)
            return a.second > b.second; // descending order for second
        return a.first < b.first;       // ascending order for first
    });

    long int currMax = -1;
    for (int i = 0; i < n; i++){
        pair<long int, long int> p = arr[i];

        if (currMax == -1) {
            currMax = p.second; continue;
        }

        if (p.second <= currMax){
            contained[pairToIdx[p]] = true;
        }

        if (p.second > currMax){
            currMax = p.second;
        }
    }

    long int currMin = -1;
    for (int i = n - 1; i >= 0; i--){
        pair<long int, long int> p = arr[i];

        if (currMin == -1) {
            currMin = p.second; 
            continue;
        }

        if (p.second >= currMin){
            contains[pairToIdx[p]] = true;
        }

        if (p.second < currMin){
            currMin = p.second;
        }
    }

    for (auto x: contains){
        cout << int(x) << " ";
    }

    cout << "\n";

    for (auto x: contained){
        cout << int(x) << " ";
    }

}