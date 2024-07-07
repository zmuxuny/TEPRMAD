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
}

string expand(char a, char b)
{
    string res = "";
    for (char c = a; c <= b; c++)
    {
        string temp = "";
        for (int i = 0; i < p2; i++)
        {
            temp += c;
        }
        res += temp;
    }
    return res;
}

void myreverse(string &s)
{
    if (p3 == 1)
    {
        return;
    }
    else
    {
        std::reverse(s.begin(), s.end());
    }
}

int main()
{

    cin >> p1 >> p2 >> p3;

    string s;
    cin >> s;
}