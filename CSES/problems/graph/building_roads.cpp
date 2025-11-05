#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }
    vector<bool> visited(n, false);
    vector<pair<int, int>> compStarts;

    int components = 0;

    // Traverse all components
    for(int start = 0; start < n; start++){
        if(visited[start]) continue;

        queue<int> q;
        q.push(start);
        components++;
        compStarts.push_back({components, start});
        visited[start] = true;

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto& x : adjList[v]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }

    cout << components - 1 << endl;

    for(int i = 1; i < (int)compStarts.size(); i++){
        cout << compStarts[i - 1].second + 1 << " " << compStarts[i].second + 1 << "\n";
    }

}