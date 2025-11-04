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

            int left = j + 1;
            int right = n - 1;

            while(left < right){
                int sum = a[left].first + a[right].first;

                if( sum < target){
                    left += 1;
                }
                else if(sum > target){
                    right -= 1;
                }
                else{
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[left].second + 1 << " " << a[right].second + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;   
    return 0;    
}