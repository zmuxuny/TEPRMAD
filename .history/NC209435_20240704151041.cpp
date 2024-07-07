#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;

    while (cin >> a >> b)
    {
        long long lena = a.size(), lenb = b.size();

        long long g = __gcd(lena, lenb);

        long long l = lena * lenb / g;

        string new_a = "", new_b = "";

        while (new_a.size() != l)
        {
            new_a += a;
        }
        while (new_b.size() != l)
        {
            new_b += b;
        }
        if (new_a > new_b)
        {
            cout << ">" << endl;
        }
        else if (new_a < new_b)
        {
            cout << "<" << endl;
        }
        else
            cout << "=" << endl;
    }
}