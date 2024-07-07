#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;

char trans(char c)
{
    if (p1 == 1)
    {
        if (isdigit(c))
            return c;
        else
            return _tolower(c);
    }
    if (p1 == 2)
    {
        if (isdigit(c))
            return c;
        else
            return _toupper(c);
    }
    if (p1 == 3)
    {
        return '*';
    }
    return '*';
}

string expand(char a, char b)
{
    if (isdigit(a) != isdigit(b))
    {
        return "-";
    }
    string res = "";
    for (char c = a + 1; c < b; c++)
    {
        string temp = "";
        for (int i = 0; i < p2; i++)
        {
            temp += trans(c);
        }
        res += temp;
    }
    if (a == b)
    {
        return "-";
    }
    if (b - a == 1)
    {
        return "";
    }
    if (a > b)
    {
        return "-";
    }
    return res;
}

void myreverse(string &s)
{

    if (p3 == 1)
    {
        return;
    }
    else if (p3 == 2)
    {
        std::reverse(s.begin(), s.end());
        return;
    }
    else
    {
        cout << string("cao") << endl;
        exit(0);
    }
}

string option(char a, char b)
{
    string res = expand(a, b);
    myreverse(res);
    return res;
}
string fun(char b, char e, int p1, int p2, int p3)
{
    if (e - b == 1)
    {
        return "";
    }
    if (!((isalpha(b) && isalpha(e) && b < e) ||
          (isdigit(b) && isdigit(e) && b < e)))
    {
        return "-";
    }
    string ans = "";
    for (char t = b + 1; t < e; t++)
    {
        for (int i = 0; i < p2; i++)
        {
            ans += t;
        }
    }
    if (p1 == 2 && isalpha(b))
    {
        for (int i = 0; i < ans.length(); i++)
        {
            ans[i] = ans[i] - 'a' + 'A';
        }
    }
    if (p1 == 3)
    {
        for (int i = 0; i < ans.length(); i++)
        {
            ans[i] = '*';
        }
    }
    if (p3 == 2)
    {
        reverse(ans.begin(), ans.end());
    }
    return ans;
}
int main()
{

    cin >> p1 >> p2 >> p3;

    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' && (i == 0 || i == s.size() - 1))
        {
            ans += s[i];
            continue;
        }
        if (s[i] != '-')
        {
            ans += s[i];
        }
        else if (s[i] == '-')
        {
            auto temp = option(s[i - 1], s[i + 1]);
            ans += temp;
        }
    }
    cout << ans << endl;

    return 0;
}