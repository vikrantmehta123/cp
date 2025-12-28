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

	int n, q;   
	cin >> n >> q;

	vector<ll> a(n);
	for(int i=0 ; i < n; i++){
		cin >> a[i];
	}

	// We can solve this problem using sparse tables.
	// The key insight here is that the range [a, b] can be split into 
	// two OVERLAPPING parts, where each part has a length that's a
	// power of 2. For example, minimum of a range with 13 elems, can
	// be split into two parts of 8 elems that are overlapping and then
	// we can take minimum of those two minimums.
	//
	// sparse[i][j] represents the minimum value in the range starting
	// at index 'i' with length 2^j.
	//
	// At max, there will be logn powers of 2.
	//
	// Let's build the sparse table now.
	//
	
	// maxLog == the maximum power of 2 we need
	int maxLog = 0;
	while((1<< maxLog) <= n){
		maxLog++;
	}
	vector<vector<int>> sparse(n, vector<int>(maxLog));

	// Base Case: 2^0 = 1. Ranges of length 1
	for (int i = 0; i < n; i++){
		sparse[i][0] = a[i];
	}

	// j represents the power 2^j
	for (int j = 1; j < maxLog; j++){
		// i + (1 << j) is a fast way of computing 2^j
		for (int i = 0; i + (1 << j) <= n; i++){
			// Recursively build the sparse tables like segment trees using 2^(j-1) size
			sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
		}
	}

	// To query this, we will need to find the largest power of two that fits within the range [a,b]
	// We want the first part to "start" at 'a', and the second part to "end" at b.
	// For example, let [a, b] = [2, 8]. Then the overlapping parts are: [2, 5] and [5, 8]
	// Largest power of two that fits within the range== log(range). We can precompute this also.
		
	vector<int> lg(n+1);
	lg[1] = 0;
	
	for(int i = 2; i <= n; i++){
		lg[i] = lg[i/2] + 1;
	}

	for(int i=0; i < q; i++){
		int a, b;
		cin >> a >> b;

		// a and b are 1-indexed. Convert them to 0-indexed
		a--;
		b--;
		
		int len = b - a + 1;
		int k = lg[len];

		int result = min(sparse[a][k], sparse[b - (1<<k) + 1][k]);

		cout << result << endl;
	}

    return 0;
}
