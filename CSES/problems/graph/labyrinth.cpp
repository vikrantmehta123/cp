#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m, 0));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char dirChar[4] = {'D', 'U', 'R', 'L'};

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    pair<int, int> start, end;

    // find start and end
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (is_valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                moveDir[nx][ny] = dirChar[dir];
                q.push({nx, ny});
                if (grid[nx][ny] == 'B') {
                    found = true;
                    break;
                }
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    // reconstruct path
    string path = "";
    pair<int,int> cur = end;
    while (cur != start) {
        path.push_back(moveDir[cur.first][cur.second]);
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}
