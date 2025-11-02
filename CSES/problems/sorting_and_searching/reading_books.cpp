#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long int> arr(n);
    for (int i = 0 ; i < n; i++){
        cin >> arr[i];
    }

    if (n == 1){
        cout << arr[0] * 2 << endl;
    }
    else{
        // Sort in descending order
        sort(arr.begin(), arr.end(), std::greater<long long int>());


        long long int subtotal = accumulate(arr.begin() + 1, arr.end(), 0LL);
        long long int firstElem = arr[0];

        if (subtotal > firstElem){
            long long int ans = accumulate(arr.begin(), arr.end(), 0LL);
            cout << ans << endl;
        }
        else{
            long long int ans = arr[0] * 2;
            cout << ans << endl;
        }
    }
}