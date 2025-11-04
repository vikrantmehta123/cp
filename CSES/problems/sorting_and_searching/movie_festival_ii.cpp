#include <bits/stdc++.h>
using namespace std;

struct Movie{
    int begin_time;
    int end_time;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Movie> arr(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        Movie m;
        m.begin_time = a;
        m.end_time = b;
        m.idx = i;
        arr[i] = m ;
    }

    sort(arr.begin(), arr.end(), [](const Movie& a, Movie&b){
        return a.end_time < b.end_time;
    });

    multiset<int> freeTimes;

    for(int i = 0; i < k; i++){
        freeTimes.insert(0);
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        int startTime = arr[i].begin_time;

        auto it = freeTimes.upper_bound(startTime);
        
        if (it == freeTimes.begin()){continue;}
        else{
            it--;
            freeTimes.erase(it);
            freeTimes.insert(arr[i].end_time);
            count++;
        }
    }

    cout << count << endl;

}