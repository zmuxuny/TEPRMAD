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
            return _toupper(c);
    }
    if (p1 == 2)
    {
        return _tolower(c);
    }
}

int main()
{

    cin >> p1 >> p2 >> p3;

    string s;
    cin >> s;
}