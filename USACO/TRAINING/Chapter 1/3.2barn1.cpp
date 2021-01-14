/*
ID: sah2020
PROG: barn1
LANG: C++14
*/

//# include <iostream>
# include <fstream>
# include <algorithm>
# include <vector>

using namespace std;

int main()
{
    ofstream cout ("barn1.out");
    ifstream cin ("barn1.in");
    int m, s, c;
    cin >> m >> s >> c;
    int arr[220];
    for (int i = 0; i < c; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + c);
    vector<pair<int, int> > v;
    for (int i = 1; i < c; ++i)
    {
        v.push_back({arr[i] - arr[i-1] - 1, i});
    }
    sort(v.rbegin(), v.rend());
    int ans = arr[c-1] - arr[0] + 1;
    for (int i = 0; i < min(m, c) - 1; ++i)
    {
        ans -= v[i].first;
    }
    cout << ans << "\n";
}
