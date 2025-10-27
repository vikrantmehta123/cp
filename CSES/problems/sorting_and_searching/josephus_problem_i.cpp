#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<bool> seen(n);
    int count = 0;
    int idx = 0;

    bool isSecond = false;
    while (true)
    {
        if ( count == n){
            break;
        }
        for(int i = idx; i < n; i++){
            if(seen[i]){
                continue;
            }
            else{
                if (isSecond){
                    cout << i + 1 << " ";
                    count += 1;
                    seen[i] = true;
                    isSecond = false;
                }
                else{
                    isSecond = true;
                }
            }
        }
    }   
}