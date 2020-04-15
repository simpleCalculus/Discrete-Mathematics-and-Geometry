/*
ID: sah2020
PROG: skidesign
LANG: C++14
*/
//# include <iostream>
# include <fstream>
# include <algorithm>
# include <vector>
# include <map>
# include <cmath>

using namespace std;

int main()
{
    ofstream cout ("skidesign.out");
    ifstream cin ("skidesign.in");
    int n, a[1005], ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int t = a[n-1] - a[0];
    if (t > 17)
    {
        ans = 1000000;
        for (int k = 1; k < t - 17; ++k)
        {
            int sum = 0;
            int x = a[0] + k;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] < x)
                    sum += (x - a[i]) * (x - a[i]);
                else if (a[i] - x > 17)
                    sum += (a[i] - x - 17) * (a[i] - x - 17);
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << "\n";
}
