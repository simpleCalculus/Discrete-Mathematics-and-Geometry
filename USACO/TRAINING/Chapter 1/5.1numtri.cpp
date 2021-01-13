/*
ID: sah2020
PROG: numtri
LANG: C++14
*/
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int vec[1002][1002];
int res[1002][1002];
int n;
int max_sum;


int dfs(int level, int index, int n)
{
    if (res[level][index] != -1)
        return res[level][index];
    else if (level <= n) {
        res[level][index] = vec[level][index] + max(dfs(level+1, index, n), dfs(level + 1, index + 1, n));
        return res[level][index];
    } else return 0;
}

int main()
{
    ofstream cout ("numtri.out");
    ifstream cin ("numtri.in"); 
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> vec[i][j];
            res[i][j] = -1;
        } 
    }
    cout << dfs(1, 1, n) << "\n";
}
