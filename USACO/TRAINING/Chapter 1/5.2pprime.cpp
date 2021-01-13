/*
ID: sah2020
PROG: pprime
LANG: C++14
*/
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int getPolin(int n, int x)
{
    string s = to_string(n);
    int m = 10 * n + x;
    for (int i = s.size() - 1; i >= 0; --i)
        m = m*10 + (s[i] - '0');
    return m;
}

bool isPrime(int m)
{
    for (int i = 2; i <= sqrt(m); ++i)
        if (m % i == 0)
            return false;
    return true;
}

int main()
{
    ofstream cout ("pprime.out");
    ifstream cin ("pprime.in"); 
    int a, b;
    cin >> a >> b;
    vector<int> v;
    for (int i = 1; i <= 999; ++i)
    {
        if (i < 10 && (i == 1 || i == 3 || i == 7 || i == 9))
            v.emplace_back(i);
        if (i < 100 && (i / 10 == 1 || i / 10 == 3 || i / 10 == 7 || i / 10 == 9))
            v.emplace_back(i);
        if (i < 1000 && (i / 100 == 1 || i / 100 == 3 || i / 100 == 7 || i / 100 == 9))
            v.emplace_back(i);
    }
    vector<int> primes;
    primes.emplace_back(5);
    primes.emplace_back(7);
    primes.emplace_back(11);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < 10; ++j) 
        {
            int x = getPolin(v[i], j);
            if (isPrime(x))
                primes.emplace_back(x);           
        }
    }

    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] > b)
            break;
        if (primes[i] >= a)
            cout << primes[i] << "\n";
    }
}
