#include <bits/stdc++.h>
using namespace std;


long long binsearch(vector<long long>& times, long long start, long long end, long long t) {

    long long int ans = -1;    // to store the smallest valid mid
    long long int n = times.size();


    // Binary search that finds the timestamp for which count is the smallest number greater than or 
    // equal to t
    while (start <= end) {
        long long mid = (start + end) / 2;

        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += mid / times[i];
            if (count > t) break;  
        }

        if (count >= t) {
            ans = mid;   
            end = mid - 1;  
        } else {
            start = mid + 1; 
        }
    }

    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<long long> times(n);
    for (int i = 0 ; i < n; i++){
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    // We don't know the end timestamp. So find the end timestamp
    long long int start = 0;
    long long int end = *max_element(times.begin(), times.end());

    while (true){
        long long int count = 0;


        for(int i=0; i<n; i++){
            count += end / times[i];
        }

        if (count < t){
            start = end + 1;
            end *= 2;
        }
        else{
            break;
        }
    }

    cout << binsearch(times, start, end, t) << endl;    
}