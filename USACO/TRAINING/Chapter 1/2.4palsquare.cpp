/*
ID: sah2020
PROG: palsquare
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

int main()
{
    ofstream cout ("palsquare.out");
    ifstream cin ("palsquare.in");
    int B;
    cin >> B;
    for (int i = 1; i <= 300; ++i)
    {
        if (IsPolindr(From10ToB(B, i*i)))
            cout << From10ToB(B, i) << " " << From10ToB(B, i*i) << "\n";
    }
}
