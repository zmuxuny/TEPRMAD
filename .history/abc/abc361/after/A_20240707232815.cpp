#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x;

    cin >> n >> k >> x;

    vector<int> a(n), b;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
        if (i == k - 1)
        {
            b.push_back(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}