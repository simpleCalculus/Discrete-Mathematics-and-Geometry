/*
ID: sah2020
PROG: beads
LANG: C++14
*/
#include <iostream>
#include <string>
//#include <fstream>

using namespace std;

bool check(string str)
{
    int col1 = 0;
    int col2 = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'r')
            ++col1;
        else if (str[i] == 'b')
            ++col2;
    }
    return (col1 <= 1 || col2 <= 1);
}

/// x нужен для того, чтобы не было бесконечной рекурсии
int Solve(string s, int i, bool x)
{
    char c = s[i];
    int ans = 0;
    int k = i;
    int size_s = s.size();
    while (c == s[k] || s[k] == 'w')
    {
        s[k] = c;
        ++ans;
        k = (k + 1) % size_s;
    }
    int l = i - 1;
    while (c == s[l] || s[l] == 'w')
    {
        s[l] = c;
        ++ans;
        if (l == 0)
            l = size_s - 1;
        else
            --l;
    }
    if (x == false)
        return ans;
    return ans + max(Solve(s, k, false), Solve(s, l, false));
}

int main()
{
//    ifstream cin ("beads.in");
//    ofstream cout ("beads.out");
    int n, mx = 0;
    cin >> n;
    string s, str;
    cin >> s;
    str = s;
    if (check(s))
    {
        cout << n << "\n";
        return 0;
    }
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == 'r' || s[i] == 'b')
            mx = max(mx, Solve(s, i, true));
    }
    cout << mx << "\n";
}
