/*
ID: sah2020
PROG: dualpal
LANG: C++14
*/

//# include <iostream>
# include <fstream>
# include <string>
using namespace std;

char Numb(int n)
{
    return (char)((n < 10) ? (n + '0') : ('A' + n - 10));
}

string From10ToB(int B, int a)
{
    string ans = "";
    while(a > 0)
    {
        ans = Numb(a % B) + ans;
        a /= B;
    }
    return ans;
}

bool IsPolindr(string a)
{
    for (int i = 0; i < a.size()/2; ++i)
    {
        if (a[i] != a[a.size()-1-i])
            return false;
    }
    return true;
}

int GetPolindrome(int S)
{
    while(true)
    {
        int cnt = 0;
        for (int i = 2; i <= 10; ++i)
        {
            if (IsPolindr(From10ToB(i, S)))
            {
                ++cnt;
            }
        }
        if (cnt >= 2)
            break;
        ++S;
    }
    return S;
}

int main()
{
    ofstream cout ("dualpal.out");
    ifstream cin ("dualpal.in");
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; ++i)
    {
        S = GetPolindrome(S + 1);
        cout << S << "\n";
    }
}
