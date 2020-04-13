/*
ID: sah2020
PROG: crypt1
LANG: C++14
*/
//# include <iostream>
# include <fstream>
# include <algorithm>
# include <vector>
# include <map>

using namespace std;

int n;
map<int, bool> mp;

bool check(int x)
{
    while(x > 0)
    {
        if (!mp[x%10])
            return 0;
        x /= 10;
    }
    return 1;
}

bool Check(int i, int j)
{
    if (!check(i) || !check(j))
        return 0;

    if (((i%10) * j < 1000) && ((i/10) * j < 1000) && (i * j > 999) && (i * j < 10000))
    {
        return check((i%10) * j) && check((i/10) * j) && check(i * j);
    }
    return 0;
}

int main()
{
    ofstream cout ("crypt1.out");
    ifstream cin ("crypt1.in");
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 11; i <= 99; ++i)
        for (int j = 111; j <= 999; ++j)
        {
            ans += Check(i, j);
        }
    cout << ans << "\n";
}
