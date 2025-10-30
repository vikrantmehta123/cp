#include <bits/stdc++.h>
using namespace std;

void makeHeap(priority_queue<int>& maxHeap, int num){
    while(num > 0){
        int digit = num % 10;
        num /= 10;
        maxHeap.push(digit);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0 ;
    while(n > 0){
        priority_queue<int> maxHeap; 
        makeHeap(maxHeap, n);
        n -= maxHeap.top();
        ans += 1;
    }

    cout << ans << endl;
}