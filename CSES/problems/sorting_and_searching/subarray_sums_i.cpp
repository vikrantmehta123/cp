#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;


    vector<long long int> a(n, 0LL);
    for(int i=0; i < n; i++){
        cin >> a[i];
    }

    long long int currSum = 0LL;
    int count = 0;
    int right = 0;

    for(int i = 0; i < n; i++){

        while( currSum < x){
            if (right >= n){
                break;
            }
            currSum += a[right];
            right++;
        }
        
        if(currSum == x){
            count++;
            if(right < n){
                currSum += a[right];
                right++;
            }
            else{
                break;
            }
        }

        currSum -= a[i];

    }

    cout << count << endl;
}
