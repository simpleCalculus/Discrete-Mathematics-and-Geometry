/*
ID: sah2020
PROG: ariprog
LANG: C++14
*/
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int SIZE = 2 * 250 * 250;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second) 
        return a.first < b.first;
    return false;
}

int main()
{
    ofstream cout ("ariprog.out");
    ifstream cin ("ariprog.in");
    int n, m, arr[SIZE + 5];
    cin >> n >> m;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i <= m; ++i)
    {
        for (int j = i; j <= m; ++j) {
            arr[i*i + j*j] = 1;
        }
    }
    vector<pair<int, int>> ans;
    int max = 2 * m * m;
    for (int i = 0; i < max; ++i)
    {
        if (!arr[i])
            continue;
        for (int j = 1; j <= (max - i) / (n - 1); ++j)
        {
            bool prog = true;
            for (int k = 1; k < n; ++k)
            {
                if (!arr[i + j * k]) 
                {
                    prog = false;
                    break;
                }
            }
            if (!prog)
                continue;
            ans.emplace_back(make_pair(i, j));
        }
    }
    if (ans.size() == 0)
    {
        cout << "NONE\n";
        return 0;
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
