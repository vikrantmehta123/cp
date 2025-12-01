#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

static void fastio(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main(){
	fastio();
	int n, k;
	cin >> n >> k;

	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	vector<ll> arr(n);
	arr[0] = x;
	for(int i = 1; i < n; i++){
		arr[i] = ( a * arr[i-1] + b ) % c;
	}

	ll curxor = 0LL;
	ll answer = 0LL;

	int left = 0, right = 0;
	while (right < k){
		curxor = curxor ^ arr[right];
		right++;
	}

	answer = curxor;

	while (right < n){
		curxor = curxor ^ arr[left];
		left++;

		curxor = curxor ^ arr[right];
		right++;

		answer = answer ^ curxor;
	}

	cout << answer << endl;

	return 0;
}
