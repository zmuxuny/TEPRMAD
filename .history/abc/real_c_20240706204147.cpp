#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);

    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long ans = 1e12;

    for (int i = 1, j = n - k; i <= k; i++, j++)
    {
        ans = min(a[j] - a[i], ans);
    }
    if (k == n)
        ans = 0;
    cout << ans << endl;
    return 0;
}