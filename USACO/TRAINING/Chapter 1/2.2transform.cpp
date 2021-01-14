/*
ID: sah2020
PROG: transform
LANG: C++14
*/

//# include <iostream>
# include <vector>
# include <algorithm>
# include <fstream>
using namespace std;

char before[15][15], after[15][15];

bool Transform_1(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
    {
        if (before[i][j] != after[j][n-1-i])
            return false;
    }
    return true;
}

bool Transform_2(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
    {
        if (before[i][j] != after[n-1-i][n-1-j])
            return false;
    }
    return true;
}

bool Transform_3(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
    {
        if (before[i][j] != after[n-1-j][i])
            return false;
    }
    return true;
}

bool Transform_4(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n/2; ++j)
    {
        if (before[i][j] != after[i][n-1-j])
            return false;
    }
    return true;
}

bool Transform_5(int n)
{
    bool sec = true;
    T:
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n/2; ++j)
    {
        int c = before[i][j];
        before[i][j] = before[i][n-1-j];
        before[i][n-1-j] = c;
    }
    if (sec && Transform_1(n))
        return true;
    if (sec && Transform_2(n))
        return true;
    if (sec && Transform_3(n))
        return true;
    if (sec)
    {
        sec = false;
        goto T;
    }
    return false;
}

bool Transform_6(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
    {
        if (before[i][j] != after[i][j])
            return false;
    }
    return true;
}

int main()
{
    ifstream cin ("transform.in");
    ofstream cout ("transform.out");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        cin >> before[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        cin >> after[i][j];

    if (Transform_1(n))
        cout << 1;
    else if (Transform_2(n))
        cout << 2;
    else if (Transform_3(n))
        cout << 3;
    else if (Transform_4(n))
        cout << 4;
    else if (Transform_5(n))
        cout << 5;
    else if (Transform_6(n))
        cout << 6;
    else
        cout << 7;
    cout << "\n";
}
