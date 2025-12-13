#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

vector<int> slidingWindowMedian(vector<int>& nums, int k) {
    ordered_set<pair<int,int>> os;
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        os.insert({nums[i], i});

        if (i >= k - 1) {
            int median_index = (k - 1) / 2;   // lower median for both odd/even k
            int median_val = os.find_by_order(median_index)->first;
            ans.push_back(median_val);

            // Remove outgoing element
            os.erase({nums[i - k + 1], i - k + 1});
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i=0; i < n; i++){
        cin >> nums[i];
    }

    vector<int> res = slidingWindowMedian(nums, k);

    for (int x : res) cout << x << " ";
    cout << endl;
}
