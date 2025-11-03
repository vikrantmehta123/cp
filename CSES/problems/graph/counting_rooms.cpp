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
    int components = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    auto is_valid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                components++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (is_valid(nx, ny) && grid[nx][ny] == '.' && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << components << "\n";
}
