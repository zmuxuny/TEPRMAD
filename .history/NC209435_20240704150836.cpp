#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string a, b;

    while (cin >> a >> b)
    {
        long long lena = a.size(), lenb = b.size();

        long long g = __gcd(lena, lenb);

        long long l = lena * lenb / g;
    }
}