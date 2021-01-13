/*
ID: sah2020
PROG: milk3
LANG: C++14
*/
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int s[21][21][21];

int m[6];

void dfs(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0) return;
    if (!s[a][b][c])
    {
        s[a][b][c] = 1;
        dfs(a + min(b, m[0] - a), b - min(b, m[0]-a), c);
        dfs(a + min(c, m[0] - a), b, c - min(c, m[0] - a));

        dfs(a - min(a, m[1] - b), b + min(a, m[1] - b), c);
        dfs(a, b + min(c, m[1] - b), c - min(c, m[1] - b));

        dfs(a - min(a, m[2] - c), b, c + min(a, m[2] - c));
        dfs(a, b - min(b, m[2] - c), c + min(b, m[2] - c));
    }
}

int main()
{
    ofstream cout ("milk3.out");
    ifstream cin ("milk3.in");
    cin >> m[0] >> m[1] >> m[2];
    dfs(0, 0, m[2]);
    int ans[21], t = 0;
    for (int i = 0; i < 21; ++i)
        for (int j = 0; j < 21; ++j)
            if (s[0][i][j])
                ans[t++] = j;
    sort(ans, ans + t);
    for (int i = 0; i < t - 1; ++ i)
        cout << ans[i] << " ";
    cout << ans[t-1] << "\n";
}
