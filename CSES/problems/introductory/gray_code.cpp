#include <bits/stdc++.h>
using namespace std;

void solve(string str, int n, bool reverse_order) {
    // Base Case: If the string is the target length, print it and stop.
    if (str.size() == n) {
        cout << str << "\n";
        return;
    }

    // Determine the order of the two recursive calls (0-branch and 1-branch)
    if (!reverse_order) {
        // Normal Order: Generates the first half (0 + G_k-1)
        solve(str + "0", n, false);
        
        // Generates the second half (1 + G_k-1^R)
        solve(str + "1", n, true);
    } else {
        // Reversed Order: Generates the second half (1 + G_k-1^R)
        // Note: The call order for the children is swapped from the Normal Order case
        solve(str + "1", n, false);
        
        // Generates the first half (0 + G_k-1)
        solve(str + "0", n, true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str = "";

    solve(str, n, false);

    return 0;
}