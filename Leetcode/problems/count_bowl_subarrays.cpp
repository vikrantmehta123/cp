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

class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
		fastio();

		int n = nums.size();
		vector<ll> rightres(n, -1LL);
		vector<ll> leftres(n, -1LL);

		stack<ll> r_st;
		for(int i = n-1; i >= 0; i--){
			while(!r_st.empty() && r_st.top() <= nums[i]){
				r_st.pop();
			}
			if (!r_st.empty()){
				rightres[i] = r_st.top();
			}

			r_st.push(nums[i]);
		}
		
		stack<ll> l_st;
		for(int i=0; i < n; i++){
			while(!l_st.empty() && l_st.top() <= nums[i]){
				l_st.pop();
			}
			if (!l_st.empty()){
				leftres[i] = l_st.top();
			}

			l_st.push(nums[i]);	
		}

		ll ans = 0LL;
		for(int i = 0; i < n; i++){
			if(leftres[i] != -1 && rightres[i] != -1){
				ans++;
			}
		}

		return ans;
	}
};