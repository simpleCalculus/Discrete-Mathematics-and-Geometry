/*
ID: sah2020
PROG: combo
LANG: C++14
*/
//# include <iostream>
# include <fstream>
# include <algorithm>
# include <vector>
# include <map>
# include <cmath>

using namespace std;

bool check(int a, int b, int c, int i, int j, int l, int n)
{
    return ( (abs(i - a) <= 2 || abs(i - a) >= n - 2) &&
             (abs(j - b) <= 2 || abs(j - b) >= n - 2) &&
             (abs(l - c) <= 2 || abs(l - c) >= n - 2) );
}

int main()
{
    ofstream cout ("combo.out");
    ifstream cin ("combo.in");
    int n, ans = 0;
    cin >> n;
    int a, b, c;
    int x, y, z;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int l = 1; l <= n; ++l)
            {
                if (check(a, b, c, i, j, l, n))
                {
                    ++ans;
                    continue;
                }
                ans += check(x, y, z, i, j, l, n);
            }
        }
    }
    cout << ans << "\n";
}
