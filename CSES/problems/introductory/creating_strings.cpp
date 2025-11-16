#include <bits/stdc++.h>
using namespace std;

string s;
vector<bool> used;
set<string> substrs;
int countPerm = 0;

void dfs(string &path) {
    if (path.size() == s.size()) {
        substrs.insert(path);
        return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        path.push_back(s[i]);

        dfs(path);

        path.pop_back();
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    used.assign(s.size(), false);

    string path = "";
    dfs(path);

    cout << substrs.size() << "\n";
    for (auto &p : substrs) cout << p << "\n";
}
