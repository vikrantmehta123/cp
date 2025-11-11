#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<long long,long long>;

const ll INF  = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#endif

static void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main(){
    fastio();

    int t;
    cin >> t;
    while(t--){
        vector<string> grid(10);
        for(int i=0; i < 10; i++){
            cin >> grid[i];
        }

        int left = 0, top = 0, right = 9, bottom = 9;
        int score = 0;
        int targetLevel = 1;
        while (left <= right && top <= bottom){
            for(int i=left; i<=right;i++){
                if(grid[top][i] == 'X'){
                    score += targetLevel;
                }
            }
            top += 1;

            for(int i=top; i <= bottom; i++){
                if (grid[i][right] == 'X') {
                    score += targetLevel;
                }
            }
            right -= 1;

            for(int i=right; i >= left; i--){
                if (grid[bottom][i] == 'X'){
                    score+= targetLevel;
                }
            } 
            bottom -= 1;


            for(int i=bottom; i >= top; i--){
                if(grid[i][left] == 'X'){
                    score += targetLevel;
                }
            }   
            left += 1;

            targetLevel++;
        }

        cout << score << endl;
    };   

    return 0;
}