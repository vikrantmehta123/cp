#include <bits/stdc++.h>
using namespace std;

static void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastio();

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pair<int, int> start;
    vector<pair<int, int>> monsters;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') monsters.push_back({i, j});
            if (grid[i][j] == 'A') start = {i, j};
        }
    }

    const int INF = 1e9;
    vector<vector<int>> monster_dist(n, vector<int>(m, INF));
    queue<pair<int, int>> q;

    for (auto& pos : monsters) {
        monster_dist[pos.first][pos.second] = 0;
        q.push(pos);
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    char dir_chars[] = {'U', 'D', 'L', 'R'};

    // Monster BFS
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dr[i], nc = curr.second + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && monster_dist[nr][nc] == INF) {
                monster_dist[nr][nc] = monster_dist[curr.first][curr.second] + 1;
                q.push({nr, nc});
            }
        }
    }

    // Player BFS
    vector<vector<int>> player_dist(n, vector<int>(m, INF));
    vector<vector<char>> parent_dir(n, vector<char>(m, 0));
    player_dist[start.first][start.second] = 0;
    q.push(start);

    pair<int, int> target = {-1, -1};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        // Check if current node is an exit
        if (curr.first == 0 || curr.first == n - 1 || curr.second == 0 || curr.second == m - 1) {
            target = curr;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dr[i], nc = curr.second + dc[i];
            int next_t = player_dist[curr.first][curr.second] + 1;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '.') {
                if (player_dist[nr][nc] == INF && next_t < monster_dist[nr][nc]) {
                    player_dist[nr][nc] = next_t;
                    parent_dir[nr][nc] = dir_chars[i];
                    q.push({nr, nc});
                }
            }
        }
    }

    if (target.first != -1) {
        cout << "YES" << endl;
        string path = "";
        while (target != start) {
            char d = parent_dir[target.first][target.second];
            path += d;
            if (d == 'U') target.first++;
            else if (d == 'D') target.first--;
            else if (d == 'L') target.second++;
            else if (d == 'R') target.second--;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << "\n" << path << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}