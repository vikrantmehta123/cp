#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bool> visited(n,false);
    vector<vector<int>> adjList(n);
    vector<int> parent(n, -1); // To record paths

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }


    // Run BFS
    int start = 0;
    bool found = false;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (auto& x: adjList[v]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = v;
            }

            if(x == n-1){
                found=true;
                break;
            }
        }

        if(found) break;
    }

    // Extract path using parent dictionary
    if (parent[n - 1] == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int> path;
        path.push_back(n);

        int s = n - 1;
        while(s != 0){
            s = parent[s];
            path.push_back(s + 1);
        }

        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for(auto& x: path){
            cout << x << " ";
        }
        cout << endl;
    }
}