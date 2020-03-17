/*
ID: sah2020
PROG: milk2
LANG: C++14
*/
//# include <iostream>
# include <vector>
# include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin ("milk2.in");
    ofstream cout ("milk2.out");
    int n;
    cin >> n;
    vector<pair<int, int> > vp;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (b < a)
            continue;
        vp.push_back({a, b});
    }
    sort(vp.begin(), vp.end());
    int mx1, mx2;
    mx1 = vp[0].second - vp[0].first;
    mx2 = 0;
    int lastIndex = 0;
    int lastIndex2 = 0;
    for (int i = 0; i < vp.size() - 1; ++i)
    {
        if (vp[lastIndex2].second >= vp[i+1].first)
        {
            if (vp[i+1].second > vp[lastIndex2].second)
            {
                lastIndex2 = i+1;
            }
            mx1 = max(mx1, vp[lastIndex2].second - vp[lastIndex].first);
        }
        else
        {
            mx2 = max(mx2, vp[i+1].first - vp[lastIndex2].second);
            lastIndex = lastIndex2 = i+1;
        }
    }
    mx1 = max(mx1, vp[vp.size()-1].second - vp[vp.size()-1].first);
    cout << mx1 << " " << mx2 << endl;
}
