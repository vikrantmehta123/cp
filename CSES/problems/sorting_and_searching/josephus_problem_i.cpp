#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> nums;

    for(int i = 1; i <= n; i++){
        nums.insert(i);
    }
    
    bool skip = false;

    while (!nums.empty())
    {
        vector<int> to_remove; 

        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (skip) {
                cout << *it << " ";
                to_remove.push_back(*it);
            }
            skip = !skip;
        }

        for (int x : to_remove)
            nums.erase(x);
    }
}