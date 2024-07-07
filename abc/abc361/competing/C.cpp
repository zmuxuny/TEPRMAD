#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long ans = 1e12;
    if (k == n)
    {
        ans = 0;
        cout << ans << endl;
    }
    for (int i = 0, j = n - k - 1; i < k; i++, j++)
    {
        ans = min(a[j] - a[i], ans);
    }

    cout << ans << endl;
    return 0;
}