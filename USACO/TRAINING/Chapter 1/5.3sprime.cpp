/*
ID: sah2020
PROG: sprime
LANG: C++14
*/
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int N;
vector<int> figures = {1, 3, 7, 9};
vector<int> ans;

bool isPrime(int m)
{
    for (int i = 2; i <= sqrt(m); ++i)
        if (m % i == 0)
            return false;
    return true;
}

void dfs(int num, int length)
{
    if (length == N)
    {
        ans.emplace_back(num);
        return;
    }
    for (int i = 0; i < figures.size(); ++i)
    {
        if (isPrime(num * 10 + figures[i]))
            dfs(num * 10 + figures[i], length + 1);
    }
}

int main()
{
    ifstream cin ("sprime.in"); 
    ofstream cout ("sprime.out");
    cin >> N;
    // 2, 3, 5, 7
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << "\n";
}
