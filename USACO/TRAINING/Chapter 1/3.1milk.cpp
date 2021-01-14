/*
ID: sah2020
PROG: milk
LANG: C++14
*/

//# include <iostream>
# include <fstream>
# include <algorithm>
# include <vector>

using namespace std;

int main()
{
    ofstream cout ("milk.out");
    ifstream cin ("milk.in");
    int n, m;
    vector<pair<int, int> > v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; n > 0; ++i)
    {
        ans += min(v[i].second, n) * v[i].first;
        n -= min(v[i].second, n);
    }
    cout << ans << "\n";
}
