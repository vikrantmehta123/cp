#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack<pair<long long int, int>> s;

    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push({a[i], i});
            cout << 0 << " ";
        }
        else{
            while(!s.empty() && a[i] <= s.top().first){
                s.pop();
            }
            if(s.empty()){
                cout << 0 << " ";
            }
            else{
                cout << s.top().second + 1 << " ";
            }
            s.push({a[i], i});
        }
    }
}
