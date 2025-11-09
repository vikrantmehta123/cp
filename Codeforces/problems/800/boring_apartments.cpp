#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

const ll INF = 1e18;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#endif

static void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastio();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;

        int res = 0;
        for (int i = 1; i <= 9; i++)
        {
            int num = i;
            bool flag = false;
            if (num == x){
                res++;
                break;
            }
            else{
                res++;
            }
            for (int j = 1; j <= 3; j++)
            {
                num = pow(10, j) * i + num;

                if (num == x)
                {
                    res += j + 1;
                    flag = true;
                    break;
                }
                else{
                    res += j + 1;
                }
            }
            if (flag){break;}
        }

        cout << res << endl;
    }

    return 0;
}