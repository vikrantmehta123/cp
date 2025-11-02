#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<pair<long long int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        pair<long long int, int> p;
        cin >> p.first;
        p.second = i;
        a[i] = p;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long target = x - a[i].first - a[j].first;

            // Binary search to find the third number
            auto it = lower_bound(a.begin(), a.end(), make_pair(target, 0LL),
                                  [](const pair<long long int, int> &p, const pair<long long int, int> &val)
                                  {
                                      return p.first < val.first;
                                  });

            // Get index of the found element
            int index = it - a.begin();

            // If the index is the same as i or j, increment iterator
            while ((a[index].second == a[i].second || a[index].second == a[j].second)){
                it++;
                index = it - a.begin();
            }

            // Check if the iterator == target. If so, answer is found
            if(it->first == target){
                cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[index].second + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;   
    return 0;    
}