class Solution {
public:
const int MAX = 2147483647;
const int MIN = -2147483648;

int myAtoi(string s)
{
    bool negative = false;
    while (s.size() > 0 && s[0] == ' ')
    {
        s.erase(0, 1);
    }
    if (s[0] == '-')
    {
        negative = true;
        s.erase(0, 1);
    }
    else if (s[0] == '+')
    {
        s.erase(0, 1);
    }

    string str = "";
    while (s.size() > 0 && (s[0] >= '0' && s[0] <= '9'))
    {
        str += s[0];
        s.erase(0, 1);
    }
    
    while (str.size() > 0 && str[0] == '0')
    {
        str.erase(0, 1);
    }

    if (str.size() == 0)
        return 0;
    if (str.size()  > 10)
        return (negative) ? MIN : MAX;
    long long x = 0;
    for (int i = 0; i < str.size(); ++i)
        x = x*10 + (str[i]-'0');
    if (negative)
    {   
        x *= -1;
        return (x < MIN) ? MIN : (int)x;
    }
    return (x > MAX) ? MAX : (int)x;
}
};
